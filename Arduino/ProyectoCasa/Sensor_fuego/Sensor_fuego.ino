int flame_sensor_pin=8;
int fuego=LOW;

void setup() {
  Serial.begin(9600);
  pinMode(flame_sensor_pin,INPUT);
}

void loop() {
  fuego = digitalRead(flame_sensor_pin);
  if (fuego == HIGH)
  {
    Serial.println("FUEGO");
    delay(1000);
  }
  else
  {
    Serial.println("NO FUEGO");
    delay(1000);
  }
}
