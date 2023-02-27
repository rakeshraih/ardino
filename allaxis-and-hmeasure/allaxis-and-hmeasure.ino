const int StepX = 2;
const int DirX = 5;
const int StepY = 3;
const int DirY = 6;
const int StepZ = 4;
const int DirZ = 7;
bool turn = true;
int count = 0;
bool STOP = false;

const int limitPinX = 9;
const int limitPinY = 10;
const int limitPinZ = 11;

bool homingDoneX = false;

void setup() {

  Serial.begin(9600);

  pinMode(limitPinX, INPUT_PULLUP);
  pinMode(limitPinY, INPUT_PULLUP);
  pinMode(limitPinZ, INPUT_PULLUP);

  pinMode(StepX,OUTPUT);
  pinMode(DirX,OUTPUT);
  pinMode(StepY,OUTPUT);
  pinMode(DirY,OUTPUT);
  pinMode(StepZ,OUTPUT);
  pinMode( DirZ,OUTPUT);

}

void topX(int distanceMM, int status, int delay){
  digitalWrite(DirX,status);
 int counts = distanceMM * 5;
 for(int x = 0; x<counts; x++) { // loop for 200 steps
  digitalWrite(StepX,HIGH);
  delayMicroseconds(delay);
  digitalWrite(StepX,LOW);
  delayMicroseconds(delay);
 }
}

void rightY(int distanceMM, int status, int delay){
  digitalWrite(DirY,status);
 int counts = distanceMM * 5;
 for(int x = 0; x<counts; x++) { // loop for 200 steps
  digitalWrite(StepY,HIGH);
  delayMicroseconds(delay);
  digitalWrite(StepY,LOW);
  delayMicroseconds(delay);
 }
}

void heightZ(int distanceMM, int status, int delay){
  digitalWrite(DirZ,status);
 int counts = distanceMM * 5;
 for(int x = 0; x<counts; x++) { // loop for 200 steps
  digitalWrite(StepZ,HIGH);
  delayMicroseconds(delay);
  digitalWrite(StepZ,LOW);
  delayMicroseconds(delay);
 }
}

void homing(int Dir, int Step, int delay, int limitSwitch, int direction){

  digitalWrite(Dir,direction);
  while(digitalRead(limitSwitch) != HIGH){
    digitalWrite(Step,LOW);
    delayMicroseconds(1000);
    digitalWrite(Step, HIGH);
    delayMicroseconds(1000);
  } 
}

void loop() {
  homing(DirY, StepY, 1000, limitPinY, LOW);
  rightY(150, HIGH, 1000);
  delay(5000);
  rightY(150, LOW, 1000);
  delay(10000000);
}

void loop1() {

  homing(DirX, StepX, 1000, limitPinX, HIGH);
  homing(DirY, StepY, 1000, limitPinY, LOW);
  homing(DirZ, StepZ, 1000, limitPinZ, LOW);
  delay(5000);

  int i = 150;
  int delayRotation = 1000;
  int gap = 10;
  int rounds =0; 
  
  topX(i, LOW,delayRotation);
  rightY(i, HIGH,delayRotation);
  topX(i, HIGH,delayRotation);
  heightZ(250, HIGH,delayRotation);
  i = i-gap;
  rightY(i, LOW,delayRotation);

 while(i > 0){
  topX(i, LOW,delayRotation); // up
  delay(100);
  int leftDown = i-gap;
  rightY(leftDown, HIGH,delayRotation); // left
  delay(100);
  topX(leftDown, HIGH,delayRotation); // down
  delay(100);
  int right = i-2*gap;
  rightY(right, LOW,delayRotation); // right
  // Serial.print(i);
  // Serial.print(leftDown);
  // Serial.println(right);
  i = right;
  delay(100);
 }

}
