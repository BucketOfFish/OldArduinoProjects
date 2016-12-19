int CLK = 5;
int DT = 6;
int SW = 7;
int turning = 0; //-1 = CCW; 0 = not turning; 1 = CW
int count = 0;

void setup() {
  pinMode(CLK,INPUT);
  pinMode(DT,INPUT);
  pinMode(SW,INPUT);
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(CLK)==0 && turning==0) {
    if (digitalRead(DT)==1)
      turning = 1;
    else
      turning = -1;
    count += turning;
  }
  else if (digitalRead(CLK)==1)
    turning = 0;
  Serial.println(count);
}
