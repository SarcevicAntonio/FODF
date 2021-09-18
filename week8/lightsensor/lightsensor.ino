#define PhC_PIN PB3                       //Define the Photoconductive Cell Pin
#define LED_PIN PB2                       //Define the LED Pin
int phcellReading;                        //Variable for PhCell Reading

#include <SoftwareSerial.h>               //Including the SoftwareSerial library
#define RX PB0                            //Defining the MOSI Pin as RX
#define TX PB1                            //Defining the MISO Pin as TX
SoftwareSerial mySerial(RX, TX);          //Defining the SoftwareSerial Pins (RX, TX)

void setup() {  
  mySerial.begin(2400);                   //Opening the serial, 2400 as data rate
  pinMode(PhC_PIN, INPUT_PULLUP);         //Setup the internal Pullup
  pinMode(LED_PIN, OUTPUT);
}

void loop(){
  phcellReading = analogRead(PhC_PIN);  //Read the PhCell
  mySerial.print("Analog reading = ");  
  mySerial.println(phcellReading);      //Print PhCell
  if(phcellReading > 120){              //If low brightness
    digitalWrite(LED_PIN, HIGH);        //Light up LED
  }else{
    digitalWrite(LED_PIN, LOW);        //turn off LED
  }
  delay(100);                           //wait a bit
}
