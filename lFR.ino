
int aphase = A1;
int aenbl = A0;
int bphase = A3;
int benbl = A5;
// int mode = 8;

int P;
int I;
int D;

float Kp = 0.05;
float Ki = 0.00001;
float Kd = 0.8;

int lastError = 0;

void setup(){
  pinMode(aphase, OUTPUT);
  pinMode(aenbl, OUTPUT);
  pinMode(bphase, OUTPUT);
  pinMode(benbl, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  PID_control();
}
void PID_control() {
  uint16_t positionLine =Sensor();
  int error = 3500 - positionLine;

  P = error;
  I = error + I;
  D = error - lastError;
  lastError = error; 
  

  int motorSpeedChange = P*Kp + I*Ki + D*Kd;

  int motorSpeedA = 200 + motorSpeedChange;
  int motorSpeedB = 200 - motorSpeedChange;


  if (motorSpeedA > 225) {
    motorSpeedA = 225;
  }
  if (motorSpeedB > 225) {
    motorSpeedB = 225;
  }
  if (motorSpeedA < -75) {
    motorSpeedA = 100;
  }
  if (motorSpeedB < -75) {
    motorSpeedB = 100;
  }
  forward_movement(motorSpeedA, motorSpeedB);

  Serial.print("MotorSpeedA=");
  Serial.println(motorSpeedA);
  Serial.print("MotorSpeedB=");
  Serial.println(motorSpeedB);

  // delay(1000);
}

void forward_movement(int speedA, int speedB) {
  if (speedA < 0) {
    speedA = 0 - speedA;
    analogWrite(aphase, 0);
  }
  else {
    analogWrite(aphase, speedA);
  }
  if (speedB < 0) {
    speedB = 0 - speedB;
    analogWrite(bphase, 0);
  }
  else {
    analogWrite(bphase, speedB);
  }
  analogWrite(aenbl, speedA);
  analogWrite(benbl, speedB);
}

int Sensor(){
    int value=(digitalRead(12)*0+digitalRead(11)*1000+digitalRead(10)*2000+digitalRead(9)*3000+digitalRead(8)*4000+digitalRead(7)*5000+digitalRead(6)*6000+digitalRead(5)*7000)/
    (digitalRead(12)+digitalRead(11)+digitalRead(10)+digitalRead(9)+digitalRead(8)+digitalRead(7)+digitalRead(6)+digitalRead(5));    
Serial.println(value);
// delay(1000);
return value;
}




