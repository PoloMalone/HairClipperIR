#include <SharpIR.h>
#include <Stepper.h>

#define IR A1
#define model 1080
#define MIN 9
#define MAX 50

SharpIR mySensor = SharpIR(IR, model);
int stepsRev = 2048;
int motSpeed = 15; //rpm
int speedPin = 5;
int dirPin1 = 4;
int dirPin2 = 3;
int mSpeed = 255; // 0 = 0%, 255 = 100% motor speed.
int cnt = 29;
Stepper myStepper(stepsRev, 8,10,9,11);
void setup() {
  
//pinMode(speedPin, OUTPUT);
//pinMode(dirPin1, OUTPUT);
//pinMode(dirPin2, OUTPUT);
Serial.begin(9600);
myStepper.setSpeed(motSpeed);

}

void loop() {

int distance = mySensor.distance();

Serial.print("Distance: ");
Serial.print(distance);
Serial.println("cm");

if (distance > MAX || distance < MIN){
  //digitalWrite(dirPin1, LOW);
  //digitalWrite(dirPin2, LOW);
  Serial.print("Distance: MAX OR LOW");
  Serial.print(distance);
  Serial.print("COUNT =");
  Serial.print(cnt);
}else if (cnt == distance){
  //digitalWrite(dirPin1, LOW);
  //digitalWrite(dirPin2, LOW);
  Serial.print("Distance: PAUSE");
  Serial.print(distance);
}else if (cnt < distance){
  Serial.print("COUNT =");
  Serial.print(cnt);
  motorUp();
}else if (cnt > distance){
  Serial.print("COUNT =");
  Serial.print(cnt);
  motorDown();
}
}

void motorUp(){
  //digitalWrite(dirPin1, LOW);
  //digitalWrite(dirPin2, HIGH);
  //analogWrite(speedPin, mSpeed);
  myStepper.step(20);
  cnt = cnt + 1;
  Serial.print("UP!!!");
 
}

void motorDown(){
    //digitalWrite(dirPin1, HIGH);
    //digitalWrite(dirPin2, LOW);
    //analogWrite(speedPin, mSpeed);
    myStepper.step(-20);
    cnt = cnt - 1;
    Serial.print("DOWN!!");
 
}
