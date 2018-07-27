#include <HID-Project.h>
#include <HID-Settings.h>

const int pinLed = LED_BUILTIN;
const int pinButton = 4;

void setup() {
  pinMode(pinLed, OUTPUT);
  pinMode(pinButton, INPUT);

  // Sends a clean report to the host. This is important on any Arduino type.
  NKROKeyboard.begin();
}

void loop() {
  // Hold a lot of keys at the same time
  //if (digitalRead(pinButton)==HIGH) {
    digitalWrite(pinLed, HIGH);

    // Do not press to many at once or some OS will have problems.
    // Note that the resulting pressed order might differ,
    // because all keys are pressed at the same time.
    NKROKeyboard.add('0');
    NKROKeyboard.add('1');
    NKROKeyboard.add('2');
    NKROKeyboard.add('3');
    NKROKeyboard.add('4');
    NKROKeyboard.add('5');
    NKROKeyboard.add('6');
    NKROKeyboard.add('7');
    NKROKeyboard.add('8');
    NKROKeyboard.add('9');
    NKROKeyboard.send();

    // Release all keys and hit enter
    NKROKeyboard.releaseAll();
    NKROKeyboard.println();

    // Simple debounce
    delay(3000);
  //}
}
