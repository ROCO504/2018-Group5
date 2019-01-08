byte servoID_1 = 0x00;
byte servoAll = 0xFE; //Broadcast ID, All hear this
int InputPinDyna = 2;
int MotorBaud = 57600;

void setup() {
  pinMode(InputPinDyna,OUTPUT);
  Serial.begin(9600);
  Serial3.begin(MotorBaud);
  Serial.flush();
}

void loop() {
  SendRequest(servoID_1);
  Serial.println("Test");
  //AskTemp(servoID_1);
  //printBuff();
  delay(1000);
}

/* Dynamixel Formula
Serial3.write(HEX);
0xFF
0xFF
ID
Read/Write/Ping
Length of message (params + 2)
Parameter 1
Parameter 2
Datacheck
*/

//Single Parameter Control
void SendRequest(byte servoID){
  byte notchecksum = ~lowByte(servoID + 0x03 + 0x03 + 0x19);
  digitalWrite(2,HIGH);
  delay(1);
  Serial3.write(0xFF); //Making the dyna Listen
  Serial3.write(0xFF); //Second Required
  Serial3.write(servoID); //Servo ID
  Serial3.write(0x03);  //0x02 = Read, 0x03 = Write, 0x01 = Ping, 0x83 = SyncWrite
  Serial3.write(0x03);  //Length of RWP which is Parameters + 2
  Serial3.write(0x19);  //LED Toggle
  Serial3.write(notchecksum); //NEEDS TO BE SAME AS ID, RWP, Len and Params!
  Serial3.flush();
  digitalWrite(2,LOW);
}

void AskTemp(byte servoID){
  byte check = ~lowByte(servoID + 0x03 + 0x03 + 0x19);
  digitalWrite(2,HIGH);
  delay(1);
  Serial3.write(0xFF); //Making the dyna Listen
  Serial3.write(0xFF); //Second Required
  Serial3.write(servoID); //Servo ID
  Serial3.write(0x02); //0x02 = Read, 0x03 = Write, 0x01 = Ping, 0x83 = SyncWrite
  Serial3.write(0x04);  //Length of RWP which is Parameters + 2
  Serial3.write(0x03);  //AskTemp
  Serial3.write(0x01);
  Serial3.write(check); //NEEDS TO BE SAME AS ID, RWP, Len and Params!

  Serial3.flush();
  digitalWrite(2,LOW);
    delay(1);
}

void printBuff(){
  Serial.println("-");
  delay(20);
  while(Serial3.available()){
    Serial.println(Serial3.read());
    delay(1);
  }
}
