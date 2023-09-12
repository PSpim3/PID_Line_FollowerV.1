void readsensor() 
{
  sensor_pin[0] = analogRead(PA0);
  sensor_pin[1] = analogRead(PA1);
  sensor_pin[2] = analogRead(PA2);
  sensor_pin[3] = analogRead(PA3);
  sensor_pin[4] = analogRead(PA4);
  sensor_pin[5] = analogRead(PA5);
  sensor_pin[6] = analogRead(PA6);
  sensor_pin[7] = analogRead(PA7);
  sensor_pin[8] = analogRead(PB0);
  sensor_pin[9] = analogRead(PB1);
}
