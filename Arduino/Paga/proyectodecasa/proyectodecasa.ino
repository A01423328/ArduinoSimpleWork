#define SensorTouch 5
int Led = 8;
int sensortouch;
#include <Servo.h>;
#define SensorTouch 4
Servo servomotor;
int sensortouch2;
#include "DHT.h"
#define DHTPIN 2
#define DHTYPE DHT11
DHT dht (DHTPIN, DHTYPE);
int motor = 9;

void setup() {
  Serial.begin(9600);
  pinMode(SensorTouch,INPUT);
  pinMode(Led,OUTPUT);
  pinMode(SensorTouch,INPUT);
  servomotor.attach(7);
  Serial.begin(9600);
  dht.begin();
  pinMode(motor,OUTPUT);
}

void loop() {
  sensortouch = digitalRead(SensorTouch);
  if (sensortouch == HIGH){
    digitalWrite(Led,HIGH);
  }
  if (sensortouch == LOW){
    digitalWrite(Led,LOW);
  }
  sensortouch2 = digitalRead(SensorTouch);
  if (sensortouch2 == HIGH) {
    servomotor.write(180);
  }
  if (sensortouch == LOW) {
    servomotor.write(0);
  }
  float h= dht.readHumidity();
  float t= dht.readTemperature();
  Serial.println("Humedad: ")
  Serial.println(h);
  Serial.println("Temperatura: ");
  Serial.println(t);
  if (h >= 50){
    digitalWrite(motor,HIGH);
  }
  if(h > 50) {
    digitalWrite(motor,LOW);
  }
  }
}
