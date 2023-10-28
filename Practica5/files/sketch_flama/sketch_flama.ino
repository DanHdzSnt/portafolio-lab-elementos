#include <Wire.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1  // Cambia a -1 si no utilizas un pin de reinicio

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

int flameSensorPin = 2; // Pin al que está conectado el sensor de llama (cámbialo según tu configuración)

void setup() {
  pinMode(flameSensorPin, INPUT);
  
  if(!display.begin(SSD1306_I2C_ADDRESS, OLED_RESET)) {
    Serial.println(F("Error al iniciar la pantalla OLED"));
    for(;;);
  }
  display.display(); // Borra la pantalla
  delay(2000); // Espera 2 segundos
  
  // Mostrar un mensaje de inicio en la pantalla
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,0);
  display.println(F("Deteccion de llama:"));
  display.display();
}

void loop() {
  int flameDetected = digitalRead(flameSensorPin);
  
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  
  if (flameDetected == LOW) {
    display.setCursor(0,20);
    display.println(F("Fuego detectado"));
  } else {
    display.setCursor(0,20);
    display.println(F("No se detecta fuego"));
  }
  
  display.display();
  delay(1000); // Espera 1 segundo antes de actualizar la pantalla
}
