#define TouchPin 7
#include <Servo.h>;
Servo ser;
int pos=0;

void setup() {
 Serial.begin(9600);
 pinMode(TouchPin,INPUT);
 ´´ñser.attach(3);
 ser.write(0);
}

void loop() {
  int touch = digitalRead(TouchPin);
  if (touch == HIGH) 
  {
    for (pos=0;pos<=180;pos+=1)
    {
      ser.write(pos);
      delay(15);
    }
    delay(3000);
     for(pos=180;pos>=0;pos-=1)
    {
      ser.write(pos);
      delay(15);
    }
    Serial.println("Siente algo");
    delay(1000);
  }
  if (touch == LOW) 
  {
    ser.write(0);
    Serial.println("No siente nada");
    delay(1000);
  }
}
