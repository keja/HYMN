
#include <SoftwareSerial.h>
SoftwareSerial USB(10, 11);

// the setup function runs once when you press reset or power the board
void setup() {

  // Setup serial communication with the computer (using a baud rate of 9600 on serial monitor)
  Serial.begin(9600);                                 

  //init button module
  pinMode(A0, INPUT);

  //init debug module (numbers)
  pinMode(1, OUTPUT);

}


void loop() {

  //connected status (debugging)
  if (Serial) {
    //we are connected to computer via usb
    digitalWrite(1, 1);
  } else {
    //we are not connected to usb
    digitalWrite(1, 0);
    setup(); //restart untill we are connected
  }

  //if we get a input on a0 (button module)
  if (digitalRead(A0) == HIGH) {
    
      // send data via d1/tX
      Serial.print("input ");
      Serial.print(digitalRead(A0));
      Serial.print("\n");
    
  }

}
