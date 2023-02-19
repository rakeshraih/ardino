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

bool homingDoneX = false;

void setup() {

  Serial.begin(9600);

  pinMode(limitPinX, INPUT_PULLUP);
  pinMode(limitPinY, INPUT_PULLUP);

  pinMode(StepX,OUTPUT);
  pinMode(DirX,OUTPUT);
  pinMode(StepY,OUTPUT);
  pinMode(DirY,OUTPUT);
  pinMode(StepZ,OUTPUT);
  pinMode( DirZ,OUTPUT);

}

// void loop() {
//  digitalWrite(DirX, HIGH); // set direction, HIGH for clockwise, LOW for anticlockwise
//  digitalWrite(DirY, HIGH);
//  digitalWrite(DirZ, HIGH);
 
//  for(int x = 0; x<200; x++) { // loop for 200 steps
//   digitalWrite(StepX,HIGH);
//   delayMicroseconds(500);
//   digitalWrite(StepX,LOW); 
//   delayMicroseconds(500);
//  }
// delay(1000); // delay for 1 second

// for(int x = 0; x<200; x++) { // loop for 200 steps
//   digitalWrite(StepY,HIGH);
//   delayMicroseconds(500);
//   digitalWrite(StepY,LOW); 
//   delayMicroseconds(500);
//  }
// delay(1000); // delay for 1 second

// for(int x = 0; x<200; x++) { // loop for 200 steps
//   digitalWrite(StepZ,HIGH);
//   delayMicroseconds(500);
//   digitalWrite(StepZ,LOW); 
//   delayMicroseconds(500);
//  }
// delay(1000); // delay for 1 second

// }

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

void homing(int Dir, int Step, int delay, int limitSwitch, int direction){

  digitalWrite(Dir,direction);
  while(digitalRead(limitSwitch) != HIGH){
    digitalWrite(Step,LOW);
    delayMicroseconds(1000);
    digitalWrite(Step, HIGH);
    delayMicroseconds(1000);
  } 

  // if(digitalRead(limitPinX) == HIGH){
  //   homingDoneX = true;
  // }

}

void loop() {

  int  delay = 1000;
  int counts = 1 * 5;
  for(int x = 0; x<counts; x++) { // loop for 200 steps
    digitalWrite(StepY,HIGH);
    delayMicroseconds(delay);
    digitalWrite(StepY,LOW);
    delayMicroseconds(delay);
  }

  delayMicroseconds(100000);

}
