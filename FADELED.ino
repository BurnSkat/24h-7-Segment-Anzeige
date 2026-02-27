// Updated FADELED.ino code to make the LEDs fade in sequence

#define LED_COUNT 8
#define FADE_DELAY 100

int ledPins[LED_COUNT] = {2, 3, 4, 5, 6, 7, 8, 9};

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
    delay(FADE_DELAY);
  }
  delay(300); // Hold at full brightness
  for (int brightness = 255; brightness >= 0; brightness--) {
    analogWrite(ledPins[index], brightness);
    delay(FADE_DELAY);
  }
}