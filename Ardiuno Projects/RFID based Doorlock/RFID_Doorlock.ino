
#include <LiquidCrystal.h>
LiquidCrystal lcd(47, 46, 45, 40, 39, 38, 37);
String v;
String tag =  "3B003B3B86BD";
int M1_1 = 33;
int M1_2 = 34;
void setup()
{
  lcd.begin(16,2);
  Serial3.begin(9600);
  Serial.begin(9600);
  pinMode(M1_1, OUTPUT);
  pinMode(M1_2, OUTPUT);
}
void loop() {
  // put your main code here, to run repeatedly:
  if (v == "")
  {
      lcd.setCursor(0, 0);
      lcd.write("Scan Your Card");
      delay(1000);
      lcd.clear();
  }
if (Serial3.available()>0)
{
  v = Serial3.readString();
if (v == tag)
{
  lcd.setCursor(0, 0);
  lcd.write("Welcome to Home");
  delay(1000);
  lcd.clear();
  digitalWrite(M1_1,HIGH);
  digitalWrite(M1_2,LOW);
}
else
{
  lcd.setCursor(0, 0);
  lcd.write("Not matching");
  delay(1000);
  lcd.clear();
}
}
}
