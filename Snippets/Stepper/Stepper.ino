const int stepPin = 2;
const int dirPin = 5;

void setup() {
  // put your setup code here, to run once:ySt
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
 }

void loop() {
 digitalWrite(dirPin, HIGH);
 for( int x = 0; x < 200; x++){
  digitalWrite(stepPin, HIGH);
  delayMicroseconds(500);
  digitalWrite(stepPin, LOW);
  delayMicroseconds(500);
 }
 delay(1000);
}
