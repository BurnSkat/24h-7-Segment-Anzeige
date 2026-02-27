// Taster RBG-LED Sketch Ariel/Fabian

const int tasterRotPin = 2;    // GPIO Taster rot
const int tasterGruenPin = 3;  // GPIO Taster grün
const int tasterBlauPin = 4;   // GPIO Taster blau
const int ledRotPin = 5;      // GPIO LED rot
const int ledGruenPin = 6;    // GPIO LED grün
const int ledBlauPin = 7;     // GPIO LED blau

// Status der Taster
bool tasterRotState = HIGH;
bool tasterGruenState = HIGH;
bool tasterBlauState = HIGH;
bool ledRotState = false;
bool ledGruenState = false;
bool ledBlauState = false;

void setup() {
  // Initialisiere LEDs:
  pinMode(ledRotPin, OUTPUT);
  pinMode(ledGruenPin, OUTPUT);
  pinMode(ledBlauPin, OUTPUT);
  // Initialisiere Buttons
  pinMode(tasterRotPin, INPUT_PULLUP);
  pinMode(tasterGruenPin, INPUT_PULLUP);
  pinMode(tasterBlauPin, INPUT_PULLUP);

}

void loop() {
  bool currentTasterStateRot = digitalRead(tasterRotPin);

  if (ledRotState == HIGH && currentTasterStateRot == LOW) {
    ledRotState = !ledRotState;
  }

  tasterRotState = currentTasterStateRot;

  digitalWrite(ledRotPin, ledRotState);

  bool currentTasterStateGruen = digitalRead(tasterGruenPin);

  if (ledGruenState == HIGH && currentTasterStateGruen == LOW) {
    ledGruenState = !ledGruenState;
  }

  tasterGruenState = currentTasterStateGruen;

  digitalWrite(ledGruenPin, ledGruenState);

  bool currentTasterStateBlau = digitalRead(tasterBlauPin);

  if (ledBlauState == HIGH && currentTasterStateBlau == LOW) {
    ledBlauState = !ledBlauState;
  }

  tasterBlauState = currentTasterStateBlau;

  digitalWrite(ledRotPin, ledRotState);

}


