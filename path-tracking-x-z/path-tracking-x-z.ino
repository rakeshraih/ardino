const int StepX = 2;
const int DirX = 5;
const int StepY = 3;
const int DirY = 6;
const int StepZ = 4;
const int DirZ = 7;

const int limitPinX = 9;
const int limitPinY = 10;
const int limitPinZ = 11;

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

void travelToRightEnd(int distanceMM, int status, int delay){
  digitalWrite(DirY,status);
  digitalWrite(DirZ,status);

 int counts = distanceMM * 5;
 for(int x = 0; x<counts; x++) { // loop for 200 steps
  digitalWrite(StepY,HIGH);
  delayMicroseconds(delay);
  digitalWrite(StepY,LOW);
   for(int i = 0; i<4; i++) { // loop for 200 steps
    digitalWrite(StepZ,HIGH);
    delayMicroseconds(delay);
    digitalWrite(StepZ,LOW);
    delayMicroseconds(delay);
  }
 }
}

void travelToLeftEnd(int distanceMM, int status, int delay){
  digitalWrite(DirY,LOW);
  digitalWrite(DirZ,LOW);

 int counts = distanceMM * 5;
 for(int x = 0; x<counts; x++) { // loop for 200 steps
  if(isYOpen()){
    digitalWrite(StepY,HIGH);
    delayMicroseconds(delay);
    digitalWrite(StepY,LOW);
    delayMicroseconds(delay);
  }
   for(int i = 0; i<4; i++) { // loop for 200 steps
     if(isZOpen()){
      digitalWrite(StepZ,HIGH);
      delayMicroseconds(delay);
      digitalWrite(StepZ,LOW);
      delayMicroseconds(delay);
     }
  }
 }
}


void loop() {
  // homingAll(400);
  // delay(1000);
  // //travelToRightEnd(150, HIGH, 500);
  // heightZ(46, HIGH, 500);
  // rightY(30, HIGH, 500);
  // for(int i=0; i< 16; i++){
  //    rightY(10, HIGH, 500);
  //    heightZ(3, HIGH, 500);
  // }

  heightZ(150, LOW, 500);

  // heightZ(46, HIGH, 500);
  // rightY(10, HIGH, 500);
  // rightY(10, HIGH, 500);
  // rightY(10, HIGH, 500);
  // rightY(10, HIGH, 500);
  // rightY(10, HIGH, 500);
  // int x[5][2] = {{0,1}, {4,5}, {8,9},{8,9},{8,9}};
  // for(int i=0; i< 3; i++){
  //   heightZ(x[i][0], LOW, 1000);
  //   rightY(x[i][1], HIGH, 500);
  // }
  // delay(1000);

  // for(int i=0; i<100; i++){
  //   rightY(1, LOW, 500);
  //   heightZ(1, LOW, 500);
  // }

  // travelToLeftEnd(150, LOW, 500);
  delay(1000000);
}
