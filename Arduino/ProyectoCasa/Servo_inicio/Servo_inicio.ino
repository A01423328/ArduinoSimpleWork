#include <Servo.h>
Servo ser;

int pos=0;

void setup() {
  Serial.begin(9600);
  ser.attach(9);
  ser.write(pos);
}

void loop() {
  // put your main code here, to run repeatedly:

}
