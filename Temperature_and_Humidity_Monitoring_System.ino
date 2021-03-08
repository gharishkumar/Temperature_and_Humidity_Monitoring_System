#include <SoftwareSerial.h>
SoftwareSerial bt(8, 9); // RX, TX


#include "dht.h"
#define dataPin A0
dht DHT;

int temp;
int hum;

void setup() {
 
 Serial.begin(9600); 
 bt.begin(9600); 
}

void loop(){
  int readData = DHT.read11(dataPin);

  hum = DHT.humidity;
  temp = DHT.temperature;

  Serial.print("Humidity: ");
  Serial.print(hum);
  Serial.println("% ");

  Serial.print("Temp: "); 
  Serial.print(temp); 
  Serial.print((char)223); //degree symbol
  Serial.println("C ");

 bt.print(temp); //send distance to MIT App
 bt.print(";");
 bt.print(hum); //send distance to MIT App 
 bt.println(";");
  
  delay(1000);
}
