#include <Ultrasonic.h>

const int TRIG = 4;
const int ECHO = 3;
const int LEDPIN = 0; // Cambiado a un pin válido (por ejemplo, 13)
int distance;

  Ultrasonic ultrasonic(TRIG, ECHO); // Declarar la instancia aquí
  void setup(){
  pinMode(LEDPIN, OUTPUT);
}

void loop() {
  distance = ultrasonic.read();

  if (distance > 20) {
    digitalWrite(LEDPIN, HIGH);
  } else {
    digitalWrite(LEDPIN, LOW);
  }
}