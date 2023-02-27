bool isXOpen(){
  // return digitalRead(limitPinX) != HIGH;
  return false;
}
bool isYOpen(){
  return digitalRead(limitPinY) != HIGH;;
}
bool isZOpen(){
  return digitalRead(limitPinZ) != HIGH;
}

void homingAll(int delay){

  digitalWrite(DirX,HIGH);
  digitalWrite(DirY,LOW);
  digitalWrite(DirZ,LOW);

  while(true){
    
    if(isXOpen()){
      digitalWrite(StepX,LOW);
      delayMicroseconds(delay);
      digitalWrite(StepX, HIGH);
      delayMicroseconds(delay);
    }
    if(isYOpen()){
      digitalWrite(StepY,LOW);
      delayMicroseconds(delay);
      digitalWrite(StepY, HIGH);
      delayMicroseconds(delay);
    }
    if(isZOpen()){
      digitalWrite(StepZ,LOW);
      delayMicroseconds(delay);
      digitalWrite(StepZ, HIGH);
      delayMicroseconds(delay);
    }
    if(!isXOpen() && !isYOpen() && !isZOpen()){
       break;
    }else{
      delayMicroseconds(delay);
    }
  } 
}