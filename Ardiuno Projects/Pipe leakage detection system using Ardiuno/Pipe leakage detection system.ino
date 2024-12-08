#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
int X1, X2,Y1,Y2;
float TIME1 = 0, TIME2 =0,Diff =0;
float a=2.0;  // Specified the difference range 
float FREQUENCY1 = 0,FREQUENCY2 = 0 ;
float WATER1 = 0,WATER2 = 0;
float TOTAL1 = 0,TOTAL2 = 0;
float LS1 = 0, LS2 = 0;
const int input1 = A0;  //Sensor 1 didital pin at A0
const int input2 = A1;  //Sensor 2 didital pin at A1
void setup()
{ 
  Serial.begin(9600);
  lcd.begin();
  lcd.backlight();
  lcd.print("Water Flow Meter");
  lcd.setCursor(0,1);
  lcd.print("****************");
  delay(2000);
  lcd.clear();
  pinMode(input1,INPUT); //Declare sensor1 as a Input pin
  pinMode(input2,INPUT); //Declare sensor2 as a Input pin                
}
void loop()
{
  X1 = pulseIn(input1, HIGH);  // Calculate the High Pulse of sensor 1
  Y1 = pulseIn(input1, LOW);   // Calculate the Low Pulse of sensor 1
  TIME1 = X1 + Y1;
  delay(1);
  Serial.println("TIME1");
  Serial.println(TIME1);
  X2 = pulseIn(input2, HIGH);  // Calculate the High Pulse of sensor 2
  Y2 = pulseIn(input2, LOW);   // Calculate the Low Pulse of sensor 2
  TIME2 = X2 + Y2;
  delay(1);
  Serial.println("TIME2");
  Serial.println(TIME2);
  FREQUENCY1 = 1000000/TIME1;
  Serial.println("FREQUENCY1");
  Serial.println(FREQUENCY1);
  WATER1 = FREQUENCY1/7.5;    // Calculate Flow rate for sensor 1 in L/m
  FREQUENCY2 = 1000000/TIME2;
  Serial.println("FREQUENCY2");
  Serial.println(FREQUENCY2);
  WATER2 = FREQUENCY2/7.5;    // Calculate Flow rate for sensor 2 in L/m
  if(FREQUENCY1 >= 0) 
   {
   if(isinf(FREQUENCY1))  //check wheather the output is infinite 
    {
      WATER1 = 0.00;
      lcd.setCursor(0,0);
      lcd.print("Flow1:"); 
      Serial.print("\n");
     }
    else
       {
        Serial.println("Flow1:");
        Serial.println(WATER1);
        Serial.print("\n");
       }
     }
     else
     {
      WATER1=0.00; // Initialize Flow1 = 0.00
     }
     if (FREQUENCY2 >= 0)
        {
        if(isinf(FREQUENCY2))
        {
          WATER2 = 0.00;
          Serial.println("Flow2:0.00");
          Serial.print("\n");
        }
    else
    {
    Serial.println("Flow2:");
    Serial.println(WATER2);
    Serial.print("\n");
    }
    }
    else
     {
      WATER2=0.00; // Initialize Flow2 = 0.00
     }
Diff = WATER1-WATER2;   //Compare the two sensors Output
Serial.println("Difference:");
Serial.println(Diff);
if (Diff > a)  // If difference is more than the specified range then display the message
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
  lcd.clear();
}
else   // When their is no difference in two sensors output
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
  Serial.println("Pipe not leakage");
}
}
