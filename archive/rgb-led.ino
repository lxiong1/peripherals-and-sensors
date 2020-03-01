int bPin = D2;
int gPin = D3;
int rPin = D4;

void setup() {
  pinMode(bPin, OUTPUT);
  pinMode(gPin, OUTPUT);
  pinMode(rPin, OUTPUT);
}

void loop() {
  int delay_in_milliseconds = 10;

  // blink(bPin, delay_in_milliseconds);
  // blink(gPin, delay_in_milliseconds);
  // blink(rPin, delay_in_milliseconds);
  fade(bPin, delay_in_milliseconds);
  fade(gPin, delay_in_milliseconds);
  fade(rPin, delay_in_milliseconds);

  delay(1000);
}

void blink(int pin, int delay_in_milliseconds) {
  digitalWrite(pin, HIGH);
  delay(delay_in_milliseconds);
  digitalWrite(pin, LOW);
  delay(delay_in_milliseconds);
}

void fade(int pin, int delay_in_milliseconds) {
  for(int brightness = 0; brightness < 256; brightness++) {
    analogWrite(pin, brightness);
    delay(delay_in_milliseconds);
  }

  for(int brightness = 255; brightness >= 0; brightness--) {
    analogWrite(pin, brightness);
    delay(delay_in_milliseconds);
  }
}
