
// CNC Shield Stepper  Control Demo
// Superb Tech
// www.youtube.com/superbtech

const int StepX = 2;
const int DirX = 5;
const int StepY = 3;
const int DirY = 6;
const int StepZ = 4;
const int DirZ = 7;
bool turn = true;
int count = 0;
bool STOP = false;


void setup() {
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


void loop() {
 if(false){
   return;
 }
 digitalWrite(DirX, turn ? LOW : HIGH);
 
for(int x = 0; x<1; x++) { // loop for 200 steps
  digitalWrite(StepX,turn ? LOW : HIGH);
  delayMicroseconds(1000);
  digitalWrite(StepX,turn ? HIGH : LOW);
  delayMicroseconds(1000);
 }

 digitalWrite(DirZ, turn ? LOW : HIGH);
 
for(int x = 0; x<1; x++) { // loop for 200 steps
  digitalWrite(StepZ,turn ? LOW : HIGH);
  delayMicroseconds(1000);
  digitalWrite(StepZ,turn ? HIGH : LOW);
  delayMicroseconds(1000);
 }
// delay(500); // delay for 1 second
  
  if(count > 500){
    turn = !turn;
    count = 0;
    delay(500);
  }
  count++;
}
