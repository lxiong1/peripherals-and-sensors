#include <math.h>

int temperaturePin = A4;

void setup() {
  Serial.begin(115200);
}

void loop() {
  int adcValue = analogRead(temperaturePin);
  double output_voltage = ( (adcValue * 3.3) / 4095.0 );
  double thermistor_resistance_kilo_ohms = ( ( 3.3 * ( 10.0 / output_voltage ) ) - 10 );
  double thermistor_resistance_ohms = thermistor_resistance_kilo_ohms * 1000 ;
  double thermistor_resistance_log = log(thermistor_resistance_ohms);
  double kelvin = ( 1 / ( 0.001129148 + ( 0.000234125 * thermistor_resistance_log ) + 
                  ( 0.0000000876741 * thermistor_resistance_log * thermistor_resistance_log * thermistor_resistance_log ) ) );
  double celsius = kelvin - 273.15;
  double fahrenheit = ( celsius * 9 / 5 ) + 32;

  Serial.println("Temperature in Celsius: ");
  Serial.println(String(celsius));

  Serial.println("Temperature in Fahrenheit: ");
  Serial.println(String(fahrenheit));

  Particle.publish("Celsius: ", String(celsius));
  Particle.publish("Fahrenheit: ", String(fahrenheit));

  delay(1000);
}
