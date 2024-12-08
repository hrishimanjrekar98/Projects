int ldr=A15;                                                                //initalize ldr pin number
int led1=22;                                                               //initalize led1 pin number
void setup()
{
Serial.begin(9600);                                                  //initalize for serial communication
pinMode(led1,OUTPUT);                                        //initalize led1 pin as a output
digitalWrite(led1,HIGH);//led off
}
void loop()
{
ldr=analogRead(A15);                                                     //read analog value of ldr
char ch=Serial.read();                                                     //read incoming data in char
Serial.print(ldr);
delay(1000);
if(ldr<400)                                                                       //initalize ldr value is less then 100
{
Serial.println(ldr);                                                           //ldr value print in serial monitor
digitalWrite(led1,LOW);                                                 //led on
}
else
{
digitalWrite(led1,HIGH);                                                 //led off
}
}
