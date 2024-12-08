
#include <LiquidCrystal.h>
LiquidCrystal lcd(47, 46, 45, 40, 39, 38, 37);
String v;
String tag =  "3B003B3B86BD";
int M1 = 33;
int M2 = 34;
void setup()
{
  lcd.begin(16,2);
  Serial3.begin(9600);
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.print("RFID BASED");
  lcd.setCursor(0,1);
  lcd.print("ATTENDANCE SYSTEM");
  delay(1000);
  lcd.setCursor(0,0);
  lcd.clear();
  lcd.print("SHOW ID");
}
void loop() {
  // put your main code here, to run repeatedly:
if (Serial3.available()>0)
{
  v = Serial3.readString();
if (v == tag)
{
  lcd.setCursor(0, 0);
  lcd.write("Welcome");
  Serial.print("Present");
  delay(1000);
  digitalWrite(M1, HIGH);
  digitalWrite(M2, LOW);
  delay(1000);
  digitalWrite(M1, LOW);
  digitalWrite(M2, HIGH);
  delay(1000);
  digitalWrite(M1, LOW);
  digitalWrite(M2, LOW);
  delay(1000);
  lcd.clear();
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
