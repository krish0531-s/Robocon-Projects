int step = 9;
int dir = 10;
int pot = A0;
void setup() {
  // put your setup code here, to run once:
  pinMode(step, OUTPUT);
  pinMode(dir, OUTPUT);
  pinMode(pot, INPUT);
  Serial.begin(9600);
  
}
int map1(float value, float inp_start, float inp_end, float out_start, float out_end){
    
    float out_diff = out_end-out_start;
    float inp_diff = inp_end-inp_start;
    float val = value * (out_diff/inp_diff);

    return val;
}
int check = 0;
int lastChangeTime  = 0;
int holdDelay = 400;
void loop() {
  int sensor = analogRead(pot);
  int speed = map1(sensor, 0 , 1023, 5, 100);
  int steps = 200;
  
  if(abs(sensor - check) > 3){
    lastChangeTime = millis();
    // Serial.println("Moving");
    
    digitalWrite(dir, HIGH);
    digitalWrite(step, HIGH);
    delay(100);
    digitalWrite(step, LOW);
    
  }

  if (millis() - lastChangeTime > holdDelay) {
    Serial.print("Stopped. Final value: ");
    Serial.println(sensor);
    
    digitalWrite(dir, HIGH);
    digitalWrite(step, HIGH);
    delay(speed);
    digitalWrite(step, LOW);
    
    
  }

  check = sensor;
  
}





