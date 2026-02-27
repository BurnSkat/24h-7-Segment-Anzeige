int REDLED = 5;
int GREENLED = 6;
int BLUELED = 3;
int brightnessRED = 0;
int brightnessGREEN = 0;
int brightnessBLUE = 0;
int fadeAmount = 5;

void setup() {
  pinMode(REDLED, OUTPUT);
  pinMode(GREENLED, OUTPUT);
  pinMode(BLUELED, OUTPUT);
}

void loop() {
    analogWrite(REDLED, brightnessRED);
    analogWrite(GREENLED, brightnessGREEN);
    analogWrite(BLUELED, brightnessBLUE);
    brightnessRED = brightnessRED + fadeAmount;
    brightnessGREEN = brightnessGREEN + fadeAmount;
    brightnessBLUE = brightnessBLUE + fadeAmount;
    if (brightnessRED == 0 || brightnessRED == 255)
    if (brightnessGREEN == 0 || brightnessGREEN == 255)
    if (brightnessBLUE == 0 || brightnessBLUE == 255)
    {
    fadeAmount = -fadeAmount;
    }
    delay(20);
  }
