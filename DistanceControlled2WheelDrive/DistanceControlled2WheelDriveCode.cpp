// C++ code
//
int trig = 4;
int echo = 3;
int in4 = 6;
int in3 = 5;
int in1 = 8;
int in2 = 7;
int enable12 = 10;
int enable34 = 9;
void setup()
{
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enable12, OUTPUT);
  pinMode(enable34, OUTPUT);
  Serial.begin(9600);
}
int distance(){
  digitalWrite(trig, LOW);
  delay(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  int duration = pulseIn(echo, HIGH);
  int distance = duration * 0.0343 / 2;
  Serial.println(distance);
  return distance;
}
void loop()
{
  int d = distance();
  if(d > 200){
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    analogWrite(enable12, 255);
    
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite(enable34, 255);
  }else if(d <= 200){
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    analogWrite(enable12, 255);
    
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    analogWrite(enable34, 255);
  }
  
}