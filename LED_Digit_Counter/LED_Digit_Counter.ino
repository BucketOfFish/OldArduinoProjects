void setup() {
  for (int i=6;i<=13;i++) {
    digitalWrite(i,LOW);
    pinMode(i,OUTPUT);
  }
}

int digits[][8] = {
  {6,7,8,10,11,12,-1},
  {7,10,-1},
  {6,8,10,11,13,-1},
  {7,8,10,11,13,-1},
  {7,10,12,13,-1},
  {7,8,11,12,13,-1},
  {6,7,8,11,12,13,-1},
  {7,10,11,-1},
  {6,7,8,10,11,12,13,-1},
  {7,10,11,12,13,-1}
};

int count=0;

void loop() {
  for (int i=6;i<=13;i++) {
    digitalWrite(i,LOW);
  }
  for (int j=0;j<8;j++) {
    int i = digits[count][j];
    if (i==-1)
      break;
    digitalWrite(i,HIGH);
  }
  delay(1000);
  count++;
  if (count>9)
    count=0;
}
