#define PWML  PB8
#define IN1L  PB12
#define IN2L  PB13
#define PWMR  PB9
#define IN1R  PB10
#define IN2R  PB11
#include <Servo.h>
Servo ESC;
  int baseSpeed = 100;  //ความเร็วตอนช้า
  int maxSpeed  = 120;  //ความเร็วตอนเร็ว
  double motorSpeed;
  double rightSpeed,leftSpeed;
  double sum_error = 0;
  double error = 0;
  double pre_error = 0;
  int Kp = 25;  
  int Kd = 15;  
  int Ki = 0;
  uint16_t sensor_pin[10];
  uint16_t sensor_values[] = {1000, 1000, 1000, 1000,1000,1000,1000,1000,1000,1000};
void setup() {
  Serial.begin(115200);
  pinMode(PWML, OUTPUT);
  pinMode(IN1L, OUTPUT);
  pinMode(IN2L, OUTPUT);
  pinMode(PWMR, OUTPUT);
  pinMode(IN1R, OUTPUT);
  pinMode(IN2R, OUTPUT);
  ESC.attach(3);//Brushless attach
  ESC.writeMicroseconds(1000); //1000-2500 maxspeed for Brushless
  delay(1000);
}

void loop() {
 ESC.attach(3);//Brushless attach
 ESC.writeMicroseconds(1400); //1000-2500 maxspeed for Brushless
 delay(300);
 go();
}
