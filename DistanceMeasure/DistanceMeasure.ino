// #include <Stepper.h>
// int stepsPerRevolution = 2048;
// int motSpeed = 10;
// int dt = 500;
// int counter = 0;
// Stepper myStepper(stepsPerRevolution, 8,10,9,11);

// void setup() {
//   // put your setup code here, to run once:ySt
//   myStepper.setSpeed(motSpeed);
// }

// void loop() {
//   // put your main code here, to run repeatedly:
//   // myStepper.step(-stepsPerRevolution);
//   // delay(dt);
//   // myStepper.step(-stepsPerRevolution);
//   // delay(dt);
//   counter++;

// }

#include "NewPing.h"

#define TRIG_PIN 7
#define ECHO_PIN 8
#define MAX_DISTANCE 400

NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE);

float duration, distance;

void setup() {
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

void loop() {
  // digitalWrite(TRIG_PIN, LOW);
  // delayMicroseconds(2);
  // digitalWrite(TRIG_PIN, HIGH);
  // delayMicroseconds(10);
  // digitalWrite(TRIG_PIN, LOW);

  // duration = pulseIn(ECHO_PIN, HIGH);

  distance = sonar.ping_cm();
  //distance = (duration/2)*0.0343;


  Serial.print("Distance =");

  if(distance >= 400 || distance <= 2){
    Serial.println("out of range");
  }else {
    Serial.print(distance);
    Serial.println("cm");
    delay(1000);
  }  

  delay(2000);
}