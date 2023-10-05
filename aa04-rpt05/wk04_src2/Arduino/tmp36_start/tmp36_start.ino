//
// AA00, TMP36 sensor
//

#define TEMP_INPUT 0
// or  int TEMP_INPUT = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
   //getting the voltage reading from the temperature sensor
  int value = analogRead(TEMP_INPUT);
  // Print value
  Serial.print("aa04, value:");
  Serial.print(value);
  int voltage = 5000.0 * value /1023.0;
  Serial.print(" Voltage:");
  Serial.print(voltage);

  float temperatureC = (voltage - 500) /10;
  Serial.print(" Temperature:");
  Serial.println(temperatureC);
  
  delay(1000);
}
