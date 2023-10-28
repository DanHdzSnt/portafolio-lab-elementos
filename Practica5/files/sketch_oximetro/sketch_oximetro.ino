#define ANALOG_PIN A0 // Pin analógico al que está conectado el sensor MQ-135

void setup() {
  Serial.begin(9600); // Inicializa la comunicación serial para ver la salida en el monitor serial
}

void loop() {
  float sensorValue = analogRead(ANALOG_PIN); // Lee el valor analógico del sensor
  float voltage = (sensorValue / 1023.0) * 5.0; // Convierte el valor a voltaje (0-5V)
  
  // Calibración del sensor MQ-135 (ajusta los valores de acuerdo a la calibración de tu sensor)
  float ppm = (voltage - 0.1) / 0.2; // Fórmula de calibración para CO2
  
  // Muestra el valor de la concentración en el monitor serial
  Serial.print("Concentración de CO2 (ppm): ");
  Serial.println(ppm);
  
  // Puedes realizar ajustes similares para otros gases que el MQ-135 pueda detectar
  // Consulta la hoja de datos del sensor para obtener más información sobre la calibración de otros gases.
  
  delay(1000); // Espera 1 segundo antes de tomar otra lectura
}