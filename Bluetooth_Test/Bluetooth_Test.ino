#include <SPI.h>
#include <Adafruit_BluefruitLE_SPI.h>
#include <Adafruit_BLE.h>
#include <Adafruit_BluefruitLE_UART.h>

Adafruit_BluefruitLE_UART ble(Serial, -1);

void setup()
{
  /*if ( !ble.begin(true) ) {
    Serial.println("Couldn't find Bluefruit, make sure it's in CoMmanD mode & check wiring?");
  }
  if ( !ble.factoryReset() ){
    Serial.println("Couldn't factory reset");
  }*/
  Serial.begin(9600);
}

void loop()
{
  char c;
  if(Serial.available())  
  {  
    c = Serial.read();  
    if(c=='t')
      Serial.println("Hello world!");
      //printHello();
    else
      Serial.println("Blah!");
  }
}

void printHello() {
  Serial.println("Hello world!");
}
