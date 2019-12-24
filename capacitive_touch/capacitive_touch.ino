int rojo = 5;                // Connect LED on pin 13, or use the onboard one
int KEY = 2;                 // Connect Touch sensor on Digital Pin 2
 
void setup(){
  pinMode(rojo, OUTPUT);      // Set ledPin to output mode
  pinMode(KEY, INPUT);       //Set touch sensor pin to input mode
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
}
 
void loop(){
   if(digitalRead(KEY)==HIGH) {      //Read Touch sensor signal
        digitalWrite(rojo, HIGH);   // if Touch sensor is HIGH, then turn on
     }
   else{
        digitalWrite(rojo, LOW);    // if Touch sensor is LOW, then turn off the led
     }
}
