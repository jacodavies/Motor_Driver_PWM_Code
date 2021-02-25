const int PositivePIN = 7;

const int driverpin1 = 5;

const int driverpin2 = 6;

const int potentiometerpin = A0;

void setup() {
  Serial.begin(9600);
  pinMode(PositivePIN, OUTPUT);
  pinMode(driverpin1, OUTPUT);
  pinMode(driverpin2, OUTPUT);
  pinMode(potentiometerpin, INPUT);
  digitalWrite(PositivePIN, HIGH);
}
void loop() {
  int potValue = analogRead(potentiometerpin);
  
  //Serial.println(potValue);
  int motorValue = potValue - 511;
  //Serial.println(motorValue);
  
  int finalmotorValue = abs(motorValue) * 0.5;
  
  if (finalmotorValue <= 30) {
    finalmotorValue = 0;
  }
  
  Serial.print(finalmotorValue);
  
  if (motorValue >= 0) {
  analogWrite(driverpin1, finalmotorValue);
  digitalWrite(driverpin2,LOW);
  Serial.println(" >");
  
  } else if (motorValue <= 0) {
  analogWrite(driverpin2, finalmotorValue);
  digitalWrite(driverpin1,LOW);
  Serial.println(" <");
  }
  delay(25);
}
