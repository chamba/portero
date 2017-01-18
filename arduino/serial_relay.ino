/*
Blink
Turns on an LED on for one second, then off for one second, repeatedly.

This example code is in the public domain.
*/

// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 13;
int opto = 12;
int incomingByte = 1;   // for incoming serial data
int MAGIC = 48; // magic number to trigger

// the setup routine runs once when you press reset:
void setup()
{
// opens serial port, sets data rate to 9600 bps
Serial.begin(9600);
// initialize the digital pin as an output.
pinMode(led, OUTPUT);
pinMode(opto, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop()
{
          // send data only when you receive data:
        if (Serial.available() > 0) {
                // read the incoming byte:
                incomingByte = Serial.read();

                // say what you got:
                //Serial.print("I received: ");
                Serial.println("0"); // print that condition was not meet, false

                // if MAGIC key is sent trigger
                if ( incomingByte == MAGIC ) {
                    Serial.println("1"); // print that condition was meet, true

                    digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
                    digitalWrite(opto, HIGH);
                    delay(3500);               // wait for a 3.5 secs
                    digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
                    digitalWrite(opto, LOW);

                    serialFlush(); //clear any request made while waiting
                    }
        }

}

void serialFlush(){
  while(Serial.available() > 0) {
    char t = Serial.read();
  }
}
