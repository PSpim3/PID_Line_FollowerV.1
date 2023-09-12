void go() {
  while(1){
      readsensor();
      if( sensor_pin[3] > sensor_values[3] && sensor_pin[4] < sensor_values[4] && sensor_pin[5] < sensor_values[5] && sensor_pin[6] > sensor_values[6]){
        error = 0;
      }
     else if( sensor_pin[3] > sensor_values[3] && sensor_pin[4] < sensor_values[4] && sensor_pin[5] > sensor_values[5] && sensor_pin[6] > sensor_values[6]){
        error = 2;
      }
     else if( sensor_pin[3] < sensor_values[3] && sensor_pin[4] < sensor_values[4] && sensor_pin[5] > sensor_values[5] && sensor_pin[6] > sensor_values[6]){
        error = 6;
      }
     else if( sensor_pin[2] < sensor_values[2] && sensor_pin[3] < sensor_values[3] && sensor_pin[5] > sensor_values[5] && sensor_pin[6] > sensor_values[6]){
        error = 8;
      }
     else if( sensor_pin[1] > sensor_values[1] && sensor_pin[2] < sensor_values[2] && sensor_pin[5] > sensor_values[5] && sensor_pin[6] > sensor_values[6]){
        error = 10;
      }
      ////////////////////////////////////////////////////
     else if( sensor_pin[3] > sensor_values[3] && sensor_pin[4] > sensor_values[4] && sensor_pin[5] < sensor_values[5] && sensor_pin[6] > sensor_values[6]){
        error = -2;
      }
     else if( sensor_pin[3] > sensor_values[3] && sensor_pin[4] > sensor_values[4] && sensor_pin[5] < sensor_values[5] && sensor_pin[6] < sensor_values[6]){
        error = -6;
      }
     else if( sensor_pin[3] > sensor_values[3] && sensor_pin[4] > sensor_values[4] && sensor_pin[6] < sensor_values[6] && sensor_pin[7] < sensor_values[7]){
        error = -8;
      }
     else if( sensor_pin[3] > sensor_values[3] && sensor_pin[4] > sensor_values[4] && sensor_pin[5] > sensor_values[5] && sensor_pin[8] < sensor_values[8]){
        error = -10;
      }
      else{
        error = pre_error;
      }
      motorSpeed = Kp*error + Kd*(error - pre_error) + Ki*(sum_error); //สมการPID
      leftSpeed = baseSpeed + motorSpeed; //สมการPID
      rightSpeed = baseSpeed - motorSpeed; //สมการPID
      if(leftSpeed > maxSpeed) leftSpeed = maxSpeed; //สมการPID
      if(rightSpeed > maxSpeed) rightSpeed = maxSpeed; //สมการPID

      if(leftSpeed < -maxSpeed) leftSpeed = -maxSpeed; //สมการPID
      if(rightSpeed < -maxSpeed) rightSpeed = -maxSpeed; //สมการPID
      MotorL(leftSpeed); //สมการPID
      MotorR(rightSpeed);
      pre_error = error; //สมการPID
      sum_error += error; //สมการPID
  }

}
