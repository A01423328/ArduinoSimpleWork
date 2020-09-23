#include <Servo.h>

Servo s;
int flame_sensor_pin=4;
int fuego=LOW;

void setup() {
  Serial.begin(9600);
  pinMode(flame_sensor_pin,INPUT);
  s.attach(5);
}

void loop() {
  fuego = digitalRead(flame_sensor_pin);
  Serial.println(fuego);
  if (fuego == HIGH)
  {
    delay(500);
    s.write(0);
  }
  else
  {
    s.write(180);
  }
}
