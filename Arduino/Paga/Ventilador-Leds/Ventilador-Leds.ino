#define SensorTouch 5

int Led = 8;
int touch;

#include "dht.h"
#define dht_apin A0 
dht DHT;
int humedad = 0;
int motor = 9;

void setup() {
  pinMode(SensorTouch,INPUT);
  pinMode(Led,OUTPUT);
  Serial.begin(9600);
  delay(500);//Delay to let system boot
  Serial.println("DHT11 Humidity & temperature Sensor\n\n");
  delay(1000);//Wait before accessing Sensor
  pinMode(motor,OUTPUT);
}

void loop() {
  DHT.read11(dht_apin);
    
    Serial.print("Current humidity = ");
    Serial.print(DHT.humidity);
    Serial.print("%  ");
    humedad = DHT.humidity;
    Serial.print("temperature = ");
    Serial.print(DHT.temperature); 
    Serial.println("C  ");
    if(humedad >= 73.00){
      digitalWrite(motor,HIGH);
    }
    if (humedad < 73.00){
      digitalWrite(motor,LOW);
    }
    
  touch = digitalRead(SensorTouch);
  if (touch == HIGH){
    digitalWrite(Led,HIGH);
  }
  else {
    digitalWrite(Led,LOW);
  }
}
