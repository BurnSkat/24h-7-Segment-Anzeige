#define LED_COUNT 3
#define FADE_DELAY 10

int ledPins[LED_COUNT] = {3, 5, 6};
int fadeAmount = 5;

void setup() {
  for (int i = 0; i < LED_COUNT; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  for (int i = 0; i < LED_COUNT; i++) {
    fadeInSequence(i);
  }
}

void fadeInSequence(int index) {
  for (int brightness = 0; brightness <= 255; brightness++) {
    analogWrite(ledPins[index], brightness);
    brightness = brightness + fadeAmount;
    delay(FADE_DELAY);
  }
  delay(100); // Hold at full brightness
  for (int brightness = 255; brightness >= 0; brightness--) {
    analogWrite(ledPins[index], brightness);
    delay(FADE_DELAY);
  }
}
