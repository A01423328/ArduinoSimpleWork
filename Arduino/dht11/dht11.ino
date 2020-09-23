#include "dht.h"
#define dht_apin A0 
dht DHT;
int humedad = 0;
int motor = 9;
 
void setup(){
 
  Serial.begin(9600);
  delay(500);//Delay to let system boot
  Serial.println("DHT11 Humidity & temperature Sensor\n\n");
  delay(1000);//Wait before accessing Sensor
  pinMode(motor,OUTPUT);
 
}//end "setup()"
 
void loop(){
  //Start of Program 
 
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
 
  //Fastest should be once every two seconds.
 
}// end loop() 
