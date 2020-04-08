
char buffer[256];

void setup() {
    Serial.begin(9600);  // opens serial port, sets data rate to 9600 bps


}

void loop() {

  // send data only when you receive data:
  if (Serial.available() > 0) {

  // read the data
          Serial.readBytes(buffer, 256);
          Serial.end();
       for (int i = 0; i < (buffer[0]/5); i++) {
          digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
          delay(300);                       // wait for a second
          digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
          delay(300);
       } 
               
  // say what you got:
//        Serial.print(buffer);

 }

}
