 
byte IR1=8;//Right sensor
int IR2=9;//left Sensor
// motor one
int enA = 5;//Right motor
int MotorAip1=2;
int MotorAip2=3;
// motor two
int enB = 6;//Left motor
int MotorBip1=4;
int MotorBip2=7;
void setup() 
{
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(IR1,INPUT);
  pinMode(IR2,INPUT);
  pinMode(MotorAip1,OUTPUT);
  pinMode(MotorAip2,OUTPUT);
  pinMode(MotorBip1,OUTPUT);
  pinMode(MotorBip2,OUTPUT);
}
void loop() 
{
   while(digitalRead(IR1)==HIGH && digitalRead(IR2)==HIGH) //IR will not glow on black line
  {
    digitalWrite(MotorAip1,LOW);
    digitalWrite(MotorAip2,LOW);
    digitalWrite(MotorBip1,LOW);
    digitalWrite(MotorBip2,LOW);
    analogWrite (enA, 0);
    analogWrite (enB, 0);
  }

  while(digitalRead(IR1)==LOW && digitalRead(IR2)==LOW)  //IR not on black line
  {
    digitalWrite(MotorAip1,HIGH);
    digitalWrite(MotorAip2,LOW);
    digitalWrite(MotorBip1,HIGH);
    digitalWrite(MotorBip2,LOW);
    analogWrite (enA, 200);
    analogWrite (enB, 200);
  }

  while(digitalRead(IR1)==LOW && digitalRead(IR2)==HIGH)
  {
    digitalWrite(MotorAip1,HIGH);     
    digitalWrite(MotorAip2,LOW);
    digitalWrite(MotorBip1,LOW);
    digitalWrite(MotorBip2,HIGH);
    analogWrite (enA, 200);
    analogWrite (enB, 150);
    delay(100);
  }

  while(digitalRead(IR1)==HIGH && digitalRead(IR2)==LOW)
  {
   
     digitalWrite(MotorAip1,LOW);     
     digitalWrite(MotorAip2,HIGH);
     digitalWrite(MotorBip1,HIGH);
     digitalWrite(MotorBip2,LOW);
     analogWrite (enA, 150);
     analogWrite (enB, 200);
     delay(100);
  }

}
