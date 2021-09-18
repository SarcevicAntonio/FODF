int i = 0;                      //int for analog value
bool up = true;                 //bool as switch

void setup() {
  pinMode(A3, OUTPUT);        //speaker pin as output
}

void loop() {
  if(up){                     
  i++;                        //raise the value
  }else{
  i--;                        //lower the value
  }
  if(i &gt;= 255){
  up = false;                 //flip switch if value is too high
  }
  if(i &lt;=0){
  up = true;                  //flip switch if value is too low
  }
  analogWrite(A3, i);         //write value to speaker pin
}