// Pocket Alarm
// Written by Antonio Sarcevic
// WTFPL License

// Pins
int trigger = 4;
int echo    = 2;
int speaker = 3;
int button  = 1;

// Variables
long duration = 0;
long distance = 0;
long setDistance = 0;

void setup() {
  // Pin Modes
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(button, INPUT_PULLUP);
}

void loop() {
  // Send out a ultra sonic wave and read the duration
  digitalWrite(trigger, LOW);
  delay(5); 
  digitalWrite(trigger, HIGH);
  delay(10);
  digitalWrite(trigger, LOW);
  duration = pulseIn(echo, HIGH);
  // Calculate Distance
  distance = (duration/2) * 0.03432;

  if(distance >= 500 || distance <= 0){
    tone(speaker, 31);
  }
  
  if(digitalRead(button) == LOW){
    setDistance = distance;
    tone(speaker, 2637, 83);
  }

  if((distance >= setDistance+10) && (setDistance != 0)){
    tone(speaker, 4000);
  }else{
    noTone(speaker);
  }
  delay(1000); 
}
