//  lux
#define TMP36_INPUT 0
#define CDS_INPUT 1

void setup() {
  Serial.begin(9600);
}

void loop() {
  int value = analogRead(TMP36_INPUT);
  float voltage = value * 5.0 * 1000.0;
  voltage /= 1023.0;
  float temperatureC = (voltage - 500) / 10 ; 
     
  int cds_value = analogRead(CDS_INPUT);
  int lux = int(luminosity(cds_value));
  Serial.print(temperatureC); 
  Serial.print(',');
  Serial.println(lux);
  
  delay(1000);
}

//Voltage to Lux
double luminosity (int RawADC0){
  double Vout=RawADC0*5.0/1023.0;  // 5/1023 (Vin = 5 V)
  double lux=(2500/Vout-500)/10;  
  // lux = 500 / Rldr, Vout = Ildr*Rldr = (5/(10 + Rldr))*Rldr
  return lux;
}
