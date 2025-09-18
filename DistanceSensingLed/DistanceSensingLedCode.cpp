// C++ code
//
int led1 = 2;
int led2 = 3;
int led3 = 4;
int trig = 11;
int echo = 12;
void setup()
{
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}
int distance;
int duration;
void loop()
{
  if(distance > 250){
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
  }
  else if(distance < 250 & distance >=175){
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
  }
  else if(distance < 175 & distance > 100){
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
  }
  else if(distance < 100){
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
  }
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  delayMicroseconds(10);
  
  duration = pulseIn(echo, HIGH);
  distance = 0.0343*duration/2;
  Serial.println(distance);
}