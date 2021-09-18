// Pocket Alarm v0.2
// Written by Antonio Sarcevic
// WTFPL License

//Pins and Variables
int trigger = 4;
int echo    = 2;
int speaker = 0;
int button  = 1;

long alarmDistance = 0;

void setup() {
  // Pin Modes
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(button, INPUT);
}

void loop(){
  // get current distance from distance sensor and save it as a variable
  long currentDistance = getDistance();
  // If distance sensor isn't working
  //  if(currentDistance >= 500 || currentDistance <= 0){
  //    // play a low tone
  //    tone(speaker, 69);
  //    delay(100);
  //    noTone(speaker);
  //    delay(500);
  //  }

  // if button is pressed
  if(digitalRead(button) == HIGH){
    // go to the set distance sequence
    setDistance();
  }

  // check distance 
  if((currentDistance >= alarmDistance + 10) && (alarmDistance != 0)){
    //play alarm if distance is further then set. (+10 to be a bit forgiving to the sensor)
     tone(speaker, 4186);
     delay(500);
     tone(speaker, 2093);
  }else{
    noTone(speaker);
  }


  delay(500);
}

// measure the distance from the distance sensor
long getDistance(){
  digitalWrite(trigger, LOW);
  delay(5);
  digitalWrite(trigger, HIGH);
  delay(10);
  digitalWrite(trigger, LOW);
  long duration = pulseIn(echo, HIGH);
  long distance = (duration/2) * 0.03432;
}

// set the distance to be compared
void setDistance(){
  if(alarmDistance == 0){
    tone(speaker, 1047);
    delay(100);
    noTone(speaker);
    delay(900);
    tone(speaker, 1047);
    delay(100);
    noTone(speaker);
    delay(900);
    tone(speaker, 1047);
    delay(100);
    noTone(speaker);
    delay(900);
    tone(speaker, 1047);
    delay(100);
    noTone(speaker);
    delay(900);
    alarmDistance = getDistance();
    tone(speaker, 1109);
    delay(200);
    noTone(speaker);
  }else{
   alarmDistance = 0; 
  }
}
