Servo servo;

int momPin = D3;
int position = 0;
int resetCounter = 0;

void setup() {
  pinMode(momPin, INPUT_PULLDOWN);

  servo.attach(D2);
  servo.write(0);

  delay(500);

  Serial.begin(115200);
}

void loop() {
  int momState = 0;
  momState = digitalRead(momPin);

  delay(150);

  if(momState == 1) {
    if(position < 181) {
      servo.write(position += 20);
    }

    if(position > 180) {
      servo.write(position -= 180);
      Particle.publish("resetCounter", String(resetCounter += 1));
    }

    Serial.println("Position: ");
    Serial.println(String(position));
  }
}
