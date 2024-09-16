#include <SoftwareSerial.h>

SoftwareSerial gpsSerial(3, 4); // RX, TX

void setup() {
  Serial.begin(115200); // Start serial communication with the computer
  gpsSerial.begin(115200); // Start serial communication with the GPS module

  // Send command to change baud rate to 115200  $PCAS01,5*19
  // gpsSerial.print("$PCAS01,5*19\r\n");
  // delay(1000); // Wait for the command to be processed

  // Send command to change baud rate to 57600
  gpsSerial.print("$PCAS01,4*18");
  delay(1000); // Wait for the command to be processed

  // Reinitialize serial communication at the new baud rate
  gpsSerial.begin(57600);
  Serial.println("Baud rate changed");

  // Send the command to change the update rate to 5Hz
  gpsSerial.println("$PCAS02,200*1D");
  
  // Wait for the command to be processed
  delay(2000);
}

void loop() {
  // Your code to read data from the GPS module
  if (gpsSerial.available()) Serial.write(gpsSerial.read());
}
