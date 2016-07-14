/* 
 *  Hőmérséklet - és páratartalomérzékelő
 * 
 * Egy DHT11-es szenzor segítségével megmérjük a hőmérsékletet és a páratartalmat.
 * 
 * Készítette: Magyar Arduino Labor
 */

#include <dht.h>
#define dataPin 9 // a dataPin nevű változó definiálása (a 9-es lábra kötöttük)
dht DHT; // Létrehozzuk a DHT szenzorunkat
void setup() 
{
  Serial.begin(9600);
}
void loop() 
{
  int readData = DHT.read11(dataPin); // Kiolvassuk a szenzorból az értéket
  float t = DHT.temperature; // Megkapjuk a hőmérséklet értékét
  float h = DHT.humidity; // Megkapjuk a páratartalom értékét
  
  // A soros monitorra kiíratjuk az értékeket
  Serial.print("Temperature = ");
  Serial.print(t);
  Serial.print(" *C ");
  Serial.print("    Humidity = ");
  Serial.print(h);
  Serial.println(" % ");
  
  delay(2000); // 2 mp-et késleltetünk, hogy 2mp-ként mérjen.
}
