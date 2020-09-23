#define SensorTouch 5

int Led = 8;
int touch;

void setup() {
  pinMode(SensorTouch,INPUT);
  pinMode(Led,OUTPUT);
}

void loop() {
  touch = digitalRead(SensorTouch);
  if (touch == HIGH){
    digitalWrite(Led,HIGH);
  }
  else {
    digitalWrite(Led,LOW);
  }
}
