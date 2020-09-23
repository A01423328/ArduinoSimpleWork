int valor;
int led = 7;
int sensorPin = 6;
int prendido=0;

void setup ()
{
  Serial.begin(9600);
  pinMode (A0,INPUT);
  pinMode (sensorPin,INPUT);
  pinMode (led,OUTPUT);
}
void loop ()
{
  valor=analogRead(A0);
  int cambio=0;
  cambio = digitalRead(sensorPin);
  Serial.println(valor);
  Serial.println(cambio);

    if (cambio == 0)
    {
      if (prendido == 0)
      {
        digitalWrite (led,HIGH);
        prendido = 1;
      }
      else
      {
        digitalWrite (led,LOW);
        prendido = 0;
      }
       delay(1000);
    }
}
