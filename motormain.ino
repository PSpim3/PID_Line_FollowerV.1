void MotorR(int Speed){
  if(Speed < 0){
  digitalWrite(IN1L, HIGH);
  digitalWrite(IN2L, LOW);
  analogWrite(PWML, Speed*-1);
  }
  else{
  digitalWrite(IN1L, LOW);
  digitalWrite(IN2L, HIGH);
  analogWrite(PWML, Speed);
  }
}
void MotorL(int Speed){
  if(Speed < 0){
    digitalWrite(IN1R, LOW);
    digitalWrite(IN2R, HIGH);
    analogWrite(PWMR, Speed*-1);
  }
  else {
    digitalWrite(IN1R, HIGH);
    digitalWrite(IN2R, LOW);
    analogWrite(PWMR, Speed);
  }
}
