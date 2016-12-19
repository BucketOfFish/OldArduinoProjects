#include <StandardCplusplus.h>
#include <vector>

using namespace std;

int SERROW = 13;
int LATCHROW = 12;
int CLOCKROW = 11;
int SERCOL = 10;
int LATCHCOL = 9;
int CLOCKCOL = 8;
int delayTime = 200;

void setup() {
  Serial.begin(9600);
  for (int i=8; i<=13; i++) {
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW);
  }
}

void loop() {
  Pharmacy();
  delay(delayTime);
}

//Pharmacy symbol
vector<vector<int> > initPharmacy();
vector<int> row(int a, int b, int c, int d, int e, int f, int g, int h);
void drawPixelGrid(vector<vector<int> > pixels);
void displayRow(int row, vector<int> rowPixels);

void moveIn(bool moveIn=true) {
  vector<vector<int> > pixels = initPharmacy();
  for(int animateCount=0; animateCount<32; animateCount++){
    for(int i=0; i<10; i++) drawPixelGrid(pixels);
  }
}

void moveOut() {
  moveIn(false);
}

void shrink(bool grow=false) {
  vector<vector<int> > pixels0 = initPharmacy();
  vector<vector<int> > pixels1;
  pixels1.push_back(row(0,1,1,1,1,1,1,0));
  pixels1.push_back(row(1,1,1,1,1,1,1,1));
  pixels1.push_back(row(1,1,1,1,1,1,1,1));
  pixels1.push_back(row(1,1,1,1,1,1,1,1));
  pixels1.push_back(row(1,1,1,1,1,1,1,1));
  pixels1.push_back(row(1,1,1,1,1,1,1,1));
  pixels1.push_back(row(1,1,1,1,1,1,1,1));
  pixels1.push_back(row(0,1,1,1,1,1,1,0));
  /*vector<vector<int> > pixels2=pixels1;*/
  /*//vector<int> ones(8, 1);*/
  /*//for(int i=0; i<8; i++) pixels2.push_back(ones);*/
  /*vector<vector<int> > pixels3 = pixels2;*/
  /*pixels3[3][3]=0;*/
  /*pixels3[3][4]=0;*/
  /*pixels3[4][3]=0;*/
  /*pixels3[4][4]=0;*/
  /*vector<vector<int> > pixels4 = pixels3;*/
  /*pixels4[2][3]=0;*/
  /*pixels4[2][4]=0;*/
  /*pixels4[5][3]=0;*/
  /*pixels4[5][4]=0;*/
  /*pixels4[3][2]=0;*/
  /*pixels4[3][5]=0;*/
  /*pixels4[4][2]=0;*/
  /*pixels4[4][5]=0;*/
  /*vector<vector<int> > pixels5;*/
  /*pixels5.push_back(row(1,1,1,1,1,1,1,1));*/
  /*pixels5.push_back(row(1,1,0,0,0,0,1,1));*/
  /*pixels5.push_back(row(1,0,0,0,0,0,0,1));*/
  /*pixels5.push_back(row(1,0,0,0,0,0,0,1));*/
  /*pixels5.push_back(row(1,0,0,0,0,0,0,1));*/
  /*pixels5.push_back(row(1,0,0,0,0,0,0,1));*/
  /*pixels5.push_back(row(1,1,0,0,0,0,1,1));*/
  /*pixels5.push_back(row(1,1,1,1,1,1,1,1));*/
  /*vector<vector<int> > pixels6;*/
  /*pixels6.push_back(row(1,1,0,0,0,0,1,1));*/
  /*pixels6.push_back(row(1,1,0,0,0,0,1,1));*/
  /*pixels6.push_back(row(0,0,0,0,0,0,0,0));*/
  /*pixels6.push_back(row(0,0,0,0,0,0,0,0));*/
  /*pixels6.push_back(row(0,0,0,0,0,0,0,0));*/
  /*pixels6.push_back(row(0,0,0,0,0,0,0,0));*/
  /*pixels6.push_back(row(1,1,0,0,0,0,1,1));*/
  /*pixels6.push_back(row(1,1,0,0,0,0,1,1));*/
  /*vector<vector<int> > pixels7;*/
  /*vector<int> zeroes(8, 0);*/
  /*for(int i=0; i<8; i++) pixels7.push_back(zeroes);*/
  /*pixels7[0][0]=1;*/
  /*pixels7[0][7]=1;*/
  /*pixels7[7][0]=1;*/
  /*pixels7[7][7]=1;*/
  /*vector<vector<int> > pixels8;*/
  /*for(int i=0; i<8; i++) pixels8.push_back(zeroes);*/

  for(int animateCount=0; animateCount<32; animateCount++){
    //int count=animateCount;
    //if(grow) count=31-animateCount;

    for(int i=0; i<10; i++) { drawPixelGrid(pixels1); }
  }
}

void grow() {
  shrink(true);
}

void flash() {
  vector<vector<int> > pixels = initPharmacy();
  vector<vector<int> > empty;
  vector<int> zeroes(8, 0);
  for(int i=0; i<8; i++) empty.push_back(zeroes);
  for(int animateCount=0; animateCount<32; animateCount++){
    if((animateCount/2)%2==0) {
      for(int i=0; i<10; i++) drawPixelGrid(empty);
    }
    else {
      for(int i=0; i<10; i++) drawPixelGrid(pixels);
    }
  }
}

void scrollRight() {
  vector<vector<int> > pixels = initPharmacy();
  for(int animateCount=0; animateCount<32; animateCount++){
    vector<int> tempRow = pixels[0];
    pixels.erase(pixels.begin());
    pixels.push_back(tempRow);
    for(int i=0; i<10; i++) drawPixelGrid(pixels);
  }
}

void scrollUp() {
  vector<vector<int> > pixels = initPharmacy();
  for(int animateCount=0; animateCount<32; animateCount++){
    for(int i=0; i<8; i++) {
      int tempPixel = pixels[i][0];
      pixels[i].erase(pixels[i].begin());
      pixels[i].push_back(tempPixel);
    }
    for(int i=0; i<10; i++) drawPixelGrid(pixels);
  }
}

void scrollLeft() {
  vector<vector<int> > pixels = initPharmacy();
  for(int animateCount=0; animateCount<32; animateCount++){
    vector<int> tempRow = pixels[7];
    pixels.erase(pixels.begin()+7);
    pixels.insert(pixels.begin(),tempRow);
    for(int i=0; i<10; i++) drawPixelGrid(pixels);
  }
}

void scrollDown() {
  vector<vector<int> > pixels = initPharmacy();
  for(int animateCount=0; animateCount<32; animateCount++){
    for(int i=0; i<8; i++) {
      int tempPixel = pixels[i][7];
      pixels[i].erase(pixels[i].begin()+7);
      pixels[i].insert(pixels[i].begin(),tempPixel);
    }
    for(int i=0; i<10; i++) drawPixelGrid(pixels);
  }
}

//Pharmacy sign display
void Pharmacy() {
  vector<vector<int> > pixels = initPharmacy();
  while(true) {
    int animationNumber = rand()%4;
    animationNumber=6;
    if (animationNumber==0) scrollRight();
    if (animationNumber==1) scrollUp();
    if (animationNumber==2) scrollLeft();
    if (animationNumber==3) scrollDown();
    if (animationNumber==4) moveIn();
    if (animationNumber==5) moveOut();
    if (animationNumber==6) shrink();
    if (animationNumber==7) grow();
    if (animationNumber==8) flash();
    for(int animateCount=0; animateCount<16; animateCount++){
        for(int i=0; i<10; i++) drawPixelGrid(pixels);
    }
  }
}

vector<vector<int> > initPharmacy() {
  vector<vector<int> > pixels;
  pixels.push_back(row(0,0,1,1,1,1,0,0));
  pixels.push_back(row(0,0,1,1,1,1,0,0));
  pixels.push_back(row(1,1,1,1,1,1,1,1));
  pixels.push_back(row(1,1,1,1,1,1,1,1));
  pixels.push_back(row(1,1,1,1,1,1,1,1));
  pixels.push_back(row(1,1,1,1,1,1,1,1));
  pixels.push_back(row(0,0,1,1,1,1,0,0));
  pixels.push_back(row(0,0,1,1,1,1,0,0));
  return pixels;
}

vector<int> row(int a, int b, int c, int d, int e, int f, int g, int h) {
  vector<int> returnRow;
  returnRow.push_back(a);
  returnRow.push_back(b);
  returnRow.push_back(c);
  returnRow.push_back(d);
  returnRow.push_back(e);
  returnRow.push_back(f);
  returnRow.push_back(g);
  returnRow.push_back(h);
  return returnRow;
}

void drawPixelGrid(vector<vector<int> > pixels) {
  for (int i=0; i<8; i++) {
    displayRow(i,pixels[i]);
    delay(3);
  }
}

void displayRow(int row, vector<int> rowPixels) {
  for (int i=0; i<8; i++) {
    digitalWrite(SERROW, i==row);
    digitalBlink(CLOCKROW);
    digitalWrite(SERCOL, rowPixels[i]);
    digitalBlink(CLOCKCOL);
  }
  digitalBlink(LATCHROW);
  digitalBlink(LATCHCOL);
}

//Make boxes scroll across the screen diagonally
void Boxes() {
  int outputSignal = HIGH;
  int count = 0;
  while(true) {
    pushOutput(outputSignal);
    count++;
    if (count>=2) {
      if (outputSignal==LOW) outputSignal=HIGH;
      else outputSignal=LOW;
      count=0;
    }
    delay(delayTime);
  }
}

void pushOutput(int output) {
  digitalWrite(SERROW, output);
  digitalWrite(SERCOL, output);
  digitalBlink(CLOCKROW);
  digitalBlink(LATCHROW);
  digitalBlink(CLOCKCOL);
  digitalBlink(LATCHCOL);
}

void digitalBlink(int pin) {
  digitalWrite(pin, HIGH);
  digitalWrite(pin, LOW);
}
