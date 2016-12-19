int Rpin = 9;
int Gpin = 6;
int Bpin = 5;
int brightness = 0;
int increment = 1;

void setup() {
  pinMode(Rpin, OUTPUT);
  pinMode(Gpin, OUTPUT);
  pinMode(Bpin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  //cycle(255, 0, 0);
  //cycle(0, 255, 0);
  //cycle(0, 0, 255);
  //cycle(255, 0, 255);
  //cycle(0, 255, 255);
  //cycle(255, 255, 0);
  int R = random(256);
  int G = random(256);
  int B = random(256);
  int sum = R+G+B;
  R = R*255/sum;
  G = G*255/sum;
  B = B*255/sum;
  cycle(random(256), random(256), random(256));
}

void cycle(int R, int G, int B) {
  while (true) {
    brightness = brightness + increment;
    if (brightness<1 || brightness>254)
      increment = increment * -1;
    brightness = constrain(brightness, 0, 255);
    analogWrite(Rpin, R*brightness/255);
    analogWrite(Gpin, G*brightness/255);
    analogWrite(Bpin, B*brightness/255);
    if (brightness<1)
      break;
    delay(3);
  }
}
