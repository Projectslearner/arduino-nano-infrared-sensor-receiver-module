/*
    Project name : Infrared sensor receiver module
    Modified Date: 10-06-2024
    Code by : Projectslearner
    Website : https://projectslearner.com/learn/arduino-nano-infrared-sensor-receiver-module
*/

#include <IRremote.h>

const int RECV_PIN = 11;  // Define the pin connected to the IR receiver module

IRrecv irrecv(RECV_PIN);  // Create an instance of the IRrecv class

decode_results results;   // Variable to store the IR decoding results

void setup() {
  Serial.begin(9600);     // Initialize serial communication for debugging
  irrecv.enableIRIn();    // Start the IR receiver
}

void loop() {
  if (irrecv.decode(&results)) {  // Check if IR signal is received
    Serial.println(results.value, HEX);  // Print the received IR code in hexadecimal format
    irrecv.resume();  // Receive the next IR signal
  }
}
