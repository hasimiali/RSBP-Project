// Define photodiode pin
#define photo 15

// Variable for stroing value from  photodiode
int photoData = 0;

void setup() {
  Serial.begin(115200);
}

void loop() {
  photoData = analogRead(photo);
  Serial.println(photoData);
  delay(100);
}