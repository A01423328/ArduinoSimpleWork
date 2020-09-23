#include <DHT.h>

#define DHTPIN 2
#define DHTYPE DHT11

DHT dht (DHTPIN, DHTYPE);
int motor = 9;

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  float h= dht.readHumidity();
  float t= dht.readTemperature();
  Serial.println("Humedad: ")
  Serial.println(h);
  Serial.println("Temperatura: ");
  Serial.println(t);
  delay (1000);
  pinMode(motor,OUTPUT);

  if (h >= 50){
    digitalWrite(motor,HIGH);
  }
  if (h > 50) {
    digitalWrite(motor,LOW);
  }
}
