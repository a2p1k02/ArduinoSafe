#include <Keypad.h>

const byte KEYPAD_ROWS = 4;
const byte KEYPAD_COLS = 4;
byte rowPins[KEYPAD_ROWS] = {5, 4, 3, 2};
byte colPins[KEYPAD_COLS] = {A3, A2, A1, A0};
char keys[KEYPAD_ROWS][KEYPAD_COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, KEYPAD_ROWS, KEYPAD_COLS);

void setup() {
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  String secretCode = "1234";
  String newCode;

  while (newCode.length() < 4) {
    char key = keypad.getKey();
    if (key >= '0' || key >= '9') {
      newCode += key;
      if (secretCode.equals(newCode)) {
        digitalWrite(11, HIGH);
        digitalWrite(10, LOW);
        Serial.println("Success");
      } else {
        digitalWrite(10, HIGH);
        Serial.println("Failed");
      }
    } 
  }
}
