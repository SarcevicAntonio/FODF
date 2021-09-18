//Including the librarys
#include <SoftwareSerial.h>
#include <SD.h>
#include <SPI.h>

//Setting up the SoftwareSerial (RX, TX)
//RX turned of because not enough pins
SoftwareSerial mySerial(0, PB1);

//Set Chip Select to pin 
#define CS_PIN PB4

//File Object
File myFile;

void setup() {
  //File we will read
  char myFileName[] = "MyFile.txt";
  //Holder of File content
  String LineString = ""; 
   
  //Opening the SoftwareSerial, 2400 as data rate for ATTiny
  mySerial.begin(2400);
  //Wait for SoftwareSerial to open.
  while (!mySerial) {}
  
  //Starting SD Card Setup
  mySerial.println("Setting up SD card...");
  mySerial.println();
  //Setting CS Pin as output
  pinMode(CS_PIN, OUTPUT);
  //Check if SD is found
  if(!SD.begin(CS_PIN)){
    mySerial.println("SD did not set up...");
    while(1);
  }
  mySerial.println("SD set up!");
  mySerial.println();

  //Reading the file
  mySerial.println("Reading MyFile.txt...");
  mySerial.println();
  //Open our File
  myFile = SD.open(myFileName, FILE_READ);
  //Keep reading
  while(myFile.available() != 0){
    LineString = myFile.readStringUntil('\n');
    mySerial.println(LineString);
  }
  myFile.close();
  mySerial.println();
  mySerial.println("Done");
}

void loop() {
    
}
