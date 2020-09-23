const int pinIRd = 8;
const int pinIRa = A0;
const int pinLED = 9;
int IRvalueA = 0;
int IRvalueB = 0;
void setup ()
{
  Serial.begin (9600);
  pinMode (pinIRd,INPUT);
  pinMode (pinIRa,INPUT);
  pinMode (pinLED, OUTPUT);
  
}
void loop ()
{
  Serial.print("Lectura de sensor: ");
  Serial.println(pinIRd); 
  delay (1000);
  Serial.print("Lectura de sensor: "); 
  Serial.println(pinIRa);
  delay(1000);

  IRvalueA = analogRead(pinIRa);
  IRvalueB = digitalRead(pinIRd);
}

