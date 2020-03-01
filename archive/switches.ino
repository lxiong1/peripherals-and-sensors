int momPin = D2;

void setup() {
  pinMode(momPin, INPUT_PULLDOWN);
  Serial.begin(115200);
}

void loop() {
  int momState = 0;
  momState = digitalRead(momPin);

  Serial.println("mom: ");
  Serial.println(momState);

  delay(200);
}
