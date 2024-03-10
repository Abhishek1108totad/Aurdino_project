// Define the analog pin for LM35 sensor
const int lm35Pin = A0;

// Define the onboard LED pin
const int ledPin = 13;

// Variables to store temperature readings and LED blink intervals
float temperature;
unsigned long previousMillis = 0;
unsigned long short_interval = 250; // Default interval for temperature below 30°C
unsigned long long_interval = 500; // Default interval for temperature above 30°C

void setup() {
  // Set the LED pin as an output
  pinMode(ledPin, OUTPUT);
  // Begin serial communication for debugging (optional)
  Serial.begin(9600);
}

void loop() {
  // Read the voltage from the LM35 sensor
  int sensorValue = analogRead(lm35Pin);
  
  // Convert the analog reading to temperature in degrees Celsius
  temperature = (sensorValue * 5.0 * 100.0) / 1024.0;

  // Print temperature for debugging (optional)
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  // Check temperature conditions and adjust LED blink interval accordingly
  if (temperature < 30) {
    interval = short_interval; // Blink every 250 milliseconds
  } else {
    interval = long_interval; // Blink every 500 milliseconds
  }

  // Blink the LED
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    // Save the last time the LED blinked
    previousMillis = currentMillis;
    // Toggle the LED state
    digitalWrite(ledPin, !digitalRead(ledPin));
  }
}
