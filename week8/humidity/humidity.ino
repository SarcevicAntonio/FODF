#include <DHT.h>
#include <DHT_U.h>

//Including the librarys
#include <SoftwareSerial.h>

//Setting up the SoftwareSerial (RX, TX)
//RX turned of because not enough pins
SoftwareSerial mySerial(0, PB1);

#define DHTPIN PB3
#define DHTTYPE DHT11   // DHT 11
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  //Opening the SoftwareSerial, 2400 as data rate for ATTiny
  mySerial.begin(2400);
  //Wait for SoftwareSerial to open.
  mySerial.println("DHT:");
  dht.begin();
}

void loop() {
  // Wait a few seconds between measurements.
  delay(2000);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    mySerial.println("Failed to read from DHT sensor!");
    return;
  }

  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

  mySerial.print("Humidity: ");
  mySerial.print(h);
  mySerial.print(" %\t");
  mySerial.print("Temperature: ");
  mySerial.print(t);
  mySerial.print(" *C ");
  mySerial.print(f);
  mySerial.print(" *F\t");
  mySerial.print("Heat index: ");
  mySerial.print(hic);
  mySerial.print(" *C ");
  mySerial.print(hif);
  mySerial.println(" *F");
}
