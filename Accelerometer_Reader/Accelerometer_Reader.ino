#include <SPI.h>

int CS = 10;

char POWER_CTL = 0x2D;    //Power-saving features control
char DATA_FORMAT = 0x31;  //Data-format control for 0x32 to 0x37
char DATAX0 = 0x32;       //X-Axis Data 0
char DATAX1 = 0x33;       //X-Axis Data 1
char DATAY0 = 0x34;       //Y-Axis Data 0
char DATAY1 = 0x35;       //Y-Axis Data 1
char DATAZ0 = 0x36;       //Z-Axis Data 0
char DATAZ1 = 0x37;       //Z-Axis Data 1

byte values[6];  //Register readings
int x,y,z; //Accelerometer values

void setup() {
  SPI.begin();
  SPI.setDataMode(SPI_MODE3);
  Serial.begin(9600);

  pinMode(CS, OUTPUT);
  digitalWrite(CS, HIGH);

  writeRegister(DATA_FORMAT, 0x1); //Puts accelerometer in +-4g range
  writeRegister(POWER_CTL, 0x08); //Measurement mode
}

void loop() {
  readRegister(DATAX0, 6, values); //Read six bytes (byte = 8 bits) starting from DATAX0, and store in values[]
  //10-bit acceleration values are stored in two 8-bit values - need to combine
  x = (int)((values[1]<<8)|(values[0])); //<<8 means shift left by 8 bits, | means bitwise or
  y = (int)((values[3]<<8)|(values[2]));
  z = (int)((values[5]<<8)|(values[4]));
  //x = ((int)values[1])); //<<8 means shift left by 8 bits, | means bitwise or
  //y = ((int)values[3]));
  //z = ((invalues[5]));

  Serial.print((float)x*4/512.0, 2); //May be something wrong with the ranges I'm getting here - seems it should be impossible to get >1 or <1?
  //Serial.print(x);
  Serial.print(',');
  Serial.print((float)y*4/512.0, 2);
  //Serial.print(y);
  Serial.print(',');
  Serial.println((float)z*4/512.0, 2);
  //Serial.println(z);
  delay(10);
}

void writeRegister(char registerAddress, char value) {
  digitalWrite(CS, LOW);
  SPI.transfer(registerAddress);
  SPI.transfer(value);
  digitalWrite(CS, HIGH);
}

void readRegister(char registerAddress, int nBytes, byte* values) {
  char address = 0x80|registerAddress; //Performing read operation, so most significant bit of register address should be set?
  if(nBytes>1)
    address = address|0x40; //Doing multi-bit read requires bit 6 to be set as well
  digitalWrite(CS, LOW);
  SPI.transfer(address);
  //Continue to read registers until we've read the number specified, storing the results to the input buffer.
  for(int i; i<nBytes; i++) {
    values[i] = SPI.transfer(0x00);
  }
  //Set the Chips Select pin high to end the SPI packet.
  digitalWrite(CS, HIGH);
}

