#include <IRremote.h>

const int RECV_PIN = 4;  // Connect IR receiver OUT to D2
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
  Serial.begin(115200);
  Serial.println("IR Receiver Test Started...");
  irrecv.enableIRIn();  // Start the IR receiver
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.print("IR Code Received: ");
    Serial.println(results.value, HEX);  // Print IR code in HEX format
    irrecv.resume();  // Receive the next signal
  }
}