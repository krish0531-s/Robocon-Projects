// C++ code
//
#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x20, 16, 2);
int in1 = 8;
int in2 = 7;
int enable12 = 9;
int pot = A2;
void setup()
{
  lcd.begin(16,2);
  lcd.init();
  lcd.backlight();
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enable12, OUTPUT);
  pinMode(pot, INPUT);
  Serial.begin(9600);	
}
int speed = 0;
void loop()
{
  lcd.clear();
  //float sensor = analogRead(pot)*(5.0/1023.0);
  float sensor = analogRead(pot);
  speed = map(sensor, 0, 1023, 0, 255);

  Serial.print("Sensor: ");
  Serial.println(sensor);
  Serial.print("Speed: ");
  Serial.println(speed);
  //delay(100);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enable12, speed);
  lcd.setCursor(0,1);
  lcd.print(speed);
  delay(10);
}