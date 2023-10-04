void setup() {
  Serial.begin(115200); // Set the baud rate
}

void loop() {
  double dataToSend = 70.12;
  Serial.println(dataToSend); // Send the data
  delay(1000); // Wait for a moment
}
