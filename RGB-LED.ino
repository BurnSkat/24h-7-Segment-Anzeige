// ------------------- Pin Definition -------------------
const int ledRed   = 9;
const int ledGreen = 10;
const int ledBlue  = 11;

const int btnRed   = 2;
const int btnGreen = 3;
const int btnBlue  = 4;

// ------------------- Statusverwaltung -------------------
enum ColorState {
  OFF,
  RED,
  GREEN,
  BLUE
};

ColorState currentState = OFF;

// ------------------- Entprellung -------------------
unsigned long lastDebounceTime[3] = {0, 0, 0};
const unsigned long debounceDelay = 50;

bool lastButtonState[3] = {HIGH, HIGH, HIGH};
bool buttonState[3]     = {HIGH, HIGH, HIGH};

// ------------------------------------------------------

void setup() {
  pinMode(ledRed, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledBlue, OUTPUT);

  pinMode(btnRed, INPUT_PULLUP);
  pinMode(btnGreen, INPUT_PULLUP);
  pinMode(btnBlue, INPUT_PULLUP);

  allOff();
}

void loop() {
  checkButton(0, btnRed, RED);
  checkButton(1, btnGreen, GREEN);
  checkButton(2, btnBlue, BLUE);
}

// ------------------------------------------------------

void checkButton(int index, int buttonPin, ColorState color) {
  bool reading = digitalRead(buttonPin);

  if (reading != lastButtonState[index]) {
    lastDebounceTime[index] = millis();
  }

  if ((millis() - lastDebounceTime[index]) > debounceDelay) {
    if (reading != buttonState[index]) {
      buttonState[index] = reading;

      // Taster gedrückt (LOW wegen INPUT_PULLUP)
      if (buttonState[index] == LOW) {

        // Wenn gleiche Farbe aktiv → ausschalten
        if (currentState == color) {
          currentState = OFF;
          allOff();
        }
        // Nur reagieren wenn keine andere Farbe aktiv ist
        else if (currentState == OFF) {
          currentState = color;
          setColor(color);
        }
      }
    }
  }

  lastButtonState[index] = reading;
}

// ------------------------------------------------------

void setColor(ColorState color) {
  allOff();

  switch (color) {
    case RED:
      digitalWrite(ledRed, HIGH);
      break;
    case GREEN:
      digitalWrite(ledGreen, HIGH);
      break;
    case BLUE:
      digitalWrite(ledBlue, HIGH);
      break;
    default:
      break;
  }
}

void allOff() {
  digitalWrite(ledRed, LOW);
  digitalWrite(ledGreen, LOW);
  digitalWrite(ledBlue, LOW);
}
