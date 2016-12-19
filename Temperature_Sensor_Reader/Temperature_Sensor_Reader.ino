int sensorPin = A0;
int sensorValue = 0;
int count = 0;
float celsiusTemp = 0;
int averaging = 1000;

void setup() {
  pinMode(sensorPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  sensorValue = analogRead(sensorPin);
  float mV = (sensorValue/1023.0)*5070;
  celsiusTemp = celsiusTemp + mV/10;
  count++;
  if (count>=averaging) {
    count = 0;
    celsiusTemp = celsiusTemp/averaging;
    Serial.print(celsiusTemp,1);
    Serial.println(" C");
    celsiusTemp = 0;
  }
  delay(1);
}
