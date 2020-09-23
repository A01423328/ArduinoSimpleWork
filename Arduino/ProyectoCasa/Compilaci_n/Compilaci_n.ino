#define TouchPin 2  //define que el sensor touch esta en el puerto 2
#include <Servo.h>  //define una librería de servomotor, lenguaje para saber que es un servomotor y usarlo
Servo puerta;       //se le nombra al servo: "puerta"

Servo ventila;      // se le nombra a otro servo: "ventila"-ventilador
int flame_sensor_pin=4; //define el sensor de fuego en el puerto 4
int fuego=LOW;      // define una variable usada para registrar si hay calor

int cambio=0;       // define una variable para saber si va a haber un obstaculo
int prendido=0;     // define si los leds estan prendidos 0=falso; 1=verdadero
int obstaculo = 6;  // define que el sensor diguelineas va estar en el puerto 6
int led = 7;        //define que los leds estan conectados al puerto 7

void setup ()
{
  pinMode(TouchPin,INPUT);  //inicializa el sensor touch para recibir información
  puerta.attach(3);         //define que el servomotor de la puerta estará en el puerto 3
  puerta.write(0);          //inicializa la puerta en la posicion 0 = cerrada
  
  pinMode(flame_sensor_pin,INPUT);  //inicializa el sensor dee fuego para recibir información
  ventila.attach(5);        //define que el servomotor del ventiador esta en el puerto 5
  
  pinMode (A0,INPUT);       //inicializa que el sensor siguelineas sacará valores numericos
  pinMode (led,OUTPUT);     //inicializa que el puerto 7 va a mandar energía para prender los leds
}

void loop ()
{
  int touch = digitalRead(TouchPin); //lee la información del sensor touch
  if (touch == HIGH)         // verifica si el sensor touch esta siendo presionado
  {
    puerta.write(0);         //si esta presionado va a abrir la puerta
    delay(3000);             // se espera 3 segundos
  }
  else 
  {
    puerta.write(90);       //sino detecta o deja de detectar se cierra
  }


  fuego = digitalRead(flame_sensor_pin);  //lee la información del sensor de fuego y la pone en la variable
  if (fuego == HIGH)         // si hay calor
  {
    ventila.write(0);       //mueve el servomotor
  }
  else
  {
    ventila.write(360);     //sino deja de mover el servomotor
  }

  
  cambio = digitalRead (obstaculo); //lee el sensor siguelineas y lo guarda en variable: 1=falso 0=verdadero
  if (cambio == 0)          //checa si hay un cambio
    {
      if (prendido == 0)    //chaca si estan las luces prendidas
      {
        digitalWrite (led,HIGH);  //prende los leds
        prendido = 1;             //cambia la variable a que 1=verdadero que los leds estan perndidos
      }
      else                  //los leds estan prendidos porque la variable "prendido" esta como 1=verdadero
      {
        digitalWrite (led,LOW); //apaga los leds
        prendido = 0;           //cambia la variable a 0=falso
      }
       delay(1000);         //se espera 1 segundo para que de tiempo de dejar pasar el obstaculo
    }
}
