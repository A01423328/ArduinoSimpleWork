#define TouchPin 2
#include <Servo.h>;
Servo ser;

void setup() {
 pinMode(TouchPin,INPUT);
 ser.attach(3);
 ser.write(0);
}

void loop() {
  int touch = digitalRead(TouchPin);
  if (touch == HIGH) 
  {
    ser.write(0);
    delay(2000);
  }
  else 
  {
    ser.write(90);
  }

}
