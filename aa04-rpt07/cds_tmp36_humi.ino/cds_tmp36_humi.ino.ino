#define TMP36_INPUT 0
#define CDS_INPUT 1
// or  int TEMP_INPUT = 0;
int humi=0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  humi = random(40,90);
  int temp_value = analogRead(TMP36_INPUT);
  
  // converting that reading to voltage
  float voltage = temp_value * 5.0 * 1000.0;  // in mV
  voltage /= 1023.0;
  float tempC = (voltage - 500) / 10 ;  

  int cds_value = analogRead(CDS_INPUT);
  int lux = int(luminosity(cds_value));
 
  Serial.print(lux);
  Serial.print(",");
  Serial.print(humi);
  Serial.print(",");
  Serial.println(tempC);

  delay(1000);
}

double luminosity(int RawADC0){
  double Vout=RawADC0 * 5.0 / 1023.0;
  int lux = (2500/Vout-500)/10;
  
  return lux;
 }