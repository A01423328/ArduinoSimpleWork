#include <Servo.h>;
#define SensorTouch 4
 Servo servomotor;
 int touch;

void setup() {
  Serial.begin(9600);
  pinMode(SensorTouch,INPUT);
  servomotor.attach(7);
}

void loop() {
  touch = digitalRead(SensorTouch);
  if (touch == HIGH) {
    servomotor.write(180);
    delay(500);
  }
  else {
    servomotor.write(0);
  }
}
