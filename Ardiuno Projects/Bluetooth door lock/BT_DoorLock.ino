#include <LiquidCrystal.h>

int M1_1 = 33, M1_2 = 34, buzz = 31;
String value = "";

int rs = 47, rw = 46, en = 45, d4 = 40, d5 = 39, d6 = 38, d7 = 37;
LiquidCrystal lcd(rs, rw, en, d4, d5, d6, d7);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial2.begin(9600);
  lcd.begin(16, 2);
  lcd.cursor();
  pinMode(buzz, OUTPUT);
  pinMode(M1_1, OUTPUT);
  pinMode(M1_2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(value ==  "") {
    lcd.setCursor(0, 0);
    lcd.noCursor();
    lcd.write("Connect and Enter Password");
    delay(500);
    lcd.scrollDisplayLeft();
  }
  
  if(Serial2.available()) {
    value = Serial2.readString();
    lcd.clear();
  }

  if(value == "Password") {
    lcd.setCursor(0, 0);
    lcd.noCursor();
    lcd.write("********");
    delay(500);
    digitalWrite(buzz, HIGH);
    delay(500);
    digitalWrite(buzz, LOW);
    delay(500);
    digitalWrite(M1_1, HIGH);
    digitalWrite(M1_2, LOW);
    delay(500);
    digitalWrite(M1_1, LOW);
    digitalWrite(M1_2, LOW);
    value = "success";
  }

  if(value == "success") {
    lcd.setCursor(0, 0);
    lcd.noCursor();
    lcd.write("Correct Password. Door Unlocked");
    delay(500);
    lcd.scrollDisplayLeft();
  }

  if(value != "" && value !="success") {     
    lcd.setCursor(0, 0);
    lcd.noCursor();
    lcd.write("Incorrect Password. Door Locked");
    delay(500);
    lcd.scrollDisplayLeft();
  }
}
