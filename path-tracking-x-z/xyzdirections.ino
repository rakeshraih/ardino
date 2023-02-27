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
  if(!isYOpen() && status == LOW){
    continue;
  }
  digitalWrite(StepY,HIGH);
  delayMicroseconds(delay);
  digitalWrite(StepY,LOW);
  delayMicroseconds(delay+x);
 }
}

void heightZ(int distanceMM, int status, int delay){
  digitalWrite(DirZ,status);
 int counts = distanceMM * 25;
 for(int x = 0; x<counts; x++) { // loop for 200 steps
  if(!isZOpen() && status == LOW){
    continue;
  }
  digitalWrite(StepZ,HIGH);
  delayMicroseconds(delay);
  digitalWrite(StepZ,LOW);
  delayMicroseconds(delay);
 }
}