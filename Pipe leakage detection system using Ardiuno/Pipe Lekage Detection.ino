#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
int X1, X2,Y1,Y2;
float TIME1 = 0, TIME2 =0,Diff =0,a=1.0;
float FREQUENCY1 = 0,FREQUENCY2 = 0 ;
float WATER1 = 0,WATER2 = 0;
float TOTAL1 = 0,TOTAL2 = 0;
float LS1 = 0, LS2 = 0;
const int input1 = A0;
const int input2 = A1;
void setup()
{ 
Serial.begin(9600);
lcd.begin();
lcd.backlight();
//lcd.clear();
//lcd.setCursor(0,0);
lcd.print("Water Flow Meter");
lcd.setCursor(0,1);
lcd.print("****************");
delay(2000);
lcd.clear();
pinMode(input1,INPUT);
pinMode(input2,INPUT);
}
void loop()
{
X1 = pulseIn(input1, HIGH);
Y1 = pulseIn(input1, LOW);
TIME1 = X1 + Y1;
FREQUENCY1 = 1000000/TIME1;
WATER1 = FREQUENCY1/7.5;
LS1 = WATER1/60;
X2 = pulseIn(input2, HIGH);
Y2 = pulseIn(input2, LOW);
TIME2 = X2 + Y2;
FREQUENCY2 = 1000000/TIME2;
WATER2 = FREQUENCY2/7.5;
LS2 = WATER2/60;
if(FREQUENCY1 >= 0)
{
if(isinf(FREQUENCY1))
{
WATER1 = 0.0;
Serial.print("Flow1:0.0");
Serial.print("\n");
}
else
{
Serial.print("Flow1:");
Serial.print(WATER1);
Serial.print("\n");
}
}
if (FREQUENCY2 >= 0)
{
if(isinf(FREQUENCY2))
{
WATER2 = 0.0;
Serial.print("Flow2: 0");
Serial.print("\n");
}
else
{
Serial.print("Flow2:");
Serial.print(WATER2);
Serial.print("\n");
}
}
delay(1000);
Diff = WATER1-WATER2;
Serial.print("Difference:");
Serial.print(Diff);
Serial.print("\n");
if (Diff > a)
{
  lcd.setCursor(0,0);
  lcd.print("Flow1:");
  lcd.print(WATER1);
  lcd.print(" L/M");
  lcd.setCursor(0,1);
  lcd.print("Flow2:");
  lcd.print(WATER2);
  lcd.print(" L/M");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Pipeline leakage");
  lcd.setCursor(0,1);
  lcd.print("Wastage:");
  lcd.print(Diff);
  lcd.print("L/M");
  delay(2000);
  Serial.print(Diff);
  Serial.print("\n");
  lcd.clear();
}
else
{ 
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Flow1:");
  lcd.print(WATER1);
  lcd.print(" L/M");
  lcd.setCursor(0,1);
  lcd.print("Flow2:");
  lcd.print(WATER2);
  lcd.print(" L/M");
  delay(2000);
  //lcd.clear();
  Serial.print("Pipe not leakage");
  Serial.print("\n");
}
}
