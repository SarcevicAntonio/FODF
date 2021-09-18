#include <SoftwareSerial.h>               //Including the SoftwareSerial library
#define RX PB0                            //Defining the MOSI Pin as RX
#define TX PB1                            //Defining the MISO Pin as TX
SoftwareSerial mySerial(RX, TX);          //Defining the SoftwareSerial Pins (RX, TX)

#define LED_PIN1 PB2                      //Define LED 1 Pin to PB2
#define LED_PIN2 PB4                      //Define LED 2 Pin to PB4

#define BUTTON_PIN PB3                    //Define Button Pin to BP3
int buttonState = false;                  //Variable for the state of the Button
 
char message[18] = "this is a for loop";  //Message as character array

void setup() {  
  pinMode(LED_PIN1, OUTPUT);              //LED 1 as OUTPUT
  pinMode(LED_PIN2, OUTPUT);              //LED 2 as OUTPUT
  pinMode(BUTTON_PIN, INPUT);             //BUTTON as INPUT
  mySerial.begin(2400);                   //Opening the serial, 2400 as data rate
  for(int i = 0; i < 18; i++){            //for loop, i will go from 0 to 18 in steps of 1
    mySerial.print(message[i]);           //Print character of array from current position of i
    delay(10);                            //Wait a bit
  }
}

void loop() {
  buttonState = digitalRead(BUTTON_PIN);  //Read the state of the button at the begining of the loop
  if(buttonState ==  HIGH){               //Code below will run, when the button is pressed
    turnBothLedOn();                      //Calls function to turn on both LEDs
    mySerial.println("Button is being pressed!"); //Writes button state in serial
  }else{                                  //Code below will run, when button is not pressed
    turnBothLedOff();                     //Calls function to turn off both LEDs
    mySerial.println("Button NOT is being pressed!"); //Writes button state in Serial
  }
  delay(100);                             //Wait a bit, to not spam the serial too much
}

void turnBothLedOn() {
    digitalWrite(LED_PIN1, HIGH);         //Turn the LED1 on   
    digitalWrite(LED_PIN2, HIGH);         //Turn the LED2 on
}

void turnBothLedOff() {
    digitalWrite(LED_PIN1, LOW);          //Turn the LED1 off
    digitalWrite(LED_PIN2, LOW);          //Turn the LED2 off
}
