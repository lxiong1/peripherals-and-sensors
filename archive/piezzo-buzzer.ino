int buzzPin = A0;

void setup() {
  pinMode(buzzPin, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  Serial.println("Buzzing...");

  twoBitsBuzz(buzzPin);
}

void buzzEffectOne(int buzzPin, int delayInMilliseconds) {
  analogWrite(buzzPin, 128);
  delay(delayInMilliseconds);
  analogWrite(buzzPin, 0);
  delay(delayInMilliseconds);
}

void buzzEffectTwo(int buzzPin, int delayInMilliseconds) {
  for(int i = 0; i < 256; i++) {
    analogWrite(buzzPin, i);
    delay(delayInMilliseconds * 0.2);
    analogWrite(buzzPin, 0);
    delay(delayInMilliseconds * 0.2);
  }
}

void twoBitsBuzz(int buzzPin) {
  analogWrite(buzzPin, 208);
  delay(100);
  analogWrite(buzzPin, 0);
  delay(300);
  analogWrite(buzzPin, 160);
  delay(100);
  analogWrite(buzzPin, 0);
  delay(50);
  analogWrite(buzzPin, 160);
  delay(100);
  analogWrite(buzzPin, 0);
  delay(50);
  analogWrite(buzzPin, 160);
  delay(100);
  analogWrite(buzzPin, 0);
  delay(75);
  analogWrite(buzzPin, 160);
  delay(100);
  analogWrite(buzzPin, 0);
  delay(500);
  analogWrite(buzzPin, 208);
  delay(100);
  analogWrite(buzzPin, 0);
  delay(300);
  analogWrite(buzzPin, 240);
  delay(100);
  analogWrite(buzzPin, 0);
  delay(3000);
}
