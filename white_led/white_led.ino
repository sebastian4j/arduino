int led = 7; 
void setup()
{
  pinMode(led, OUTPUT);     //Set Pin7 as output
}
void loop()
{   /* 
    digitalWrite(led, HIGH);   //Turn off led
          delay(1000);
          digitalWrite(led, LOW);    //Turn on led
          delay(1000);
*/
          digitalWrite(led, HIGH);    //Turn on led
          delay(1000);
}
