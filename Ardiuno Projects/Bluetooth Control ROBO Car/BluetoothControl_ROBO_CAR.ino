int motor1_1=33;                    //initalize motor1 positive terminal
int motor1_2=34;                   //initalize motor1 negative terminal
int motor2_1=35;                   //initalize motor2 positive terminal
int motor2_2=36;                  //initalize motor2 positive terminal

void setup()
{
  pinMode(33,OUTPUT);          //initalize motor1 as a output
  pinMode(34,OUTPUT);          //initalize motor1 as a output
  pinMode(35,OUTPUT);               //initalize motor2 as a output
  pinMode(36,OUTPUT);             //initalize motor2 as a output
  Serial.begin(9600);            //initialize for serial communication
  Serial2.begin(9600);                   // initialize Bluetooth serial communication
}

void loop()
{
  if(Serial2.available()>0)          // check the bluetooth data available on receiver line aur not
  {
  char ch=Serial2.read();           //read incoming data in char
  Serial2.print(ch);                     //display on serial monitor
  if(ch=='1')                                //bluetooth through transmitted data 1 condition for motor will                                                                                rotate on forward direction
  {
    Serial2.print("FORWARD");   //diplay  motor rotate on forward direction
    digitalWrite(33,HIGH);         //motor 1 positive terminal on
    digitalWrite(34,LOW);          //motor 1 negative terminal off
    digitalWrite(35,HIGH);          //motor 2 positive terminal on
    digitalWrite(36,LOW);           //motor 2 negative  terminal off
  }
  if(ch=='2')                              //bluetooth through transmitted data 1 condition for motor will stop
  {
  Serial2.print("STOP");               //diplay  motor rotate on forward direction
  digitalWrite(33,LOW);             //motor 1 positive terminal off
  digitalWrite(34,LOW);            //motor 1 negative terminal off
  digitalWrite(35,LOW);            //motor 2 positive terminal off
  digitalWrite(36,LOW);            //motor 2 negative  terminal off
  }
  if(ch=='3')                              //bluetooth through transmitted data 1 condition for motor will rotate on reverse direction
  {
  Serial2.print("REVERSE");
  digitalWrite(34,HIGH);           //motor 1 negative terminal on
  digitalWrite(33,LOW);            //motor 1 positive terminal off
  digitalWrite(36,HIGH);            //motor 2 negative  terminal on
  digitalWrite(35,LOW);             //motor 2 positive terminal off
  }
  if(ch=='4')                                //bluetooth through transmitted data 1 condition for motor will rotate on right direction
  {
  Serial2.print("RIGHT");
  digitalWrite(35,HIGH);           //motor 2 positive terminal on
  digitalWrite(34,HIGH);          //motor 1 negative terminal on
  digitalWrite(36,LOW);           //motor 2 negative  terminal off
  digitalWrite(33,LOW);          //motor 1 positive terminal off
  }
  if(ch=='5')                           //bluetooth through transmitted data 1 condition for motor will rotate on left direction
  {
  Serial2.print("LEFT");
  digitalWrite(33,HIGH);          //motor 1 positive terminal on
  digitalWrite(36,HIGH);          //motor 2 negative  terminal on
  digitalWrite(35,LOW);          //motor 2 positive terminal off
  digitalWrite(34,LOW);         //motor 1 negative terminal off
  }
  }
}
