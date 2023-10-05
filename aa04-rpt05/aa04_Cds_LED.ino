#defind CDS_INPUT 0

const int ledPin =13;

int threshold = 70;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int value = analogRead(CDS_INPUT);
  int lux = int(luminosity(value))
  Serial.println(lux);

  if(lux >= threshold)
    digitalWrite(ledPin, LOW);
  else
    digitalWrite(ledPin, HIGH);

  delay(1000);
}

double luminosity (int RawADCO){
  double Vout = RawADCO * 5.0 / 1023.0;
  double lux = (2500.0 / Vout - 500.0) /10;

  return lux;
}
