

const int pinLed = LED_BUILTIN;
const int pinButton = 2;

void setup() {
  pinMode(pinLed, OUTPUT);
  pinMode(pinButton, INPUT);
  digitalWrite(pinLed, LOW);

  Serial.begin(9600);
}

void loop() {
  // Hold a lot of keys at the same time
  if (digitalRead(pinButton)==HIGH) {
    digitalWrite(pinLed, HIGH);

    // Do not press to many at once or some OS will have problems.
    // Note that the resulting pressed order might differ,
    // because all keys are pressed at the same time.
    Serial.print('0');
    Serial.print('1');
    Serial.print('2');
    Serial.print('3');
    Serial.print('4');
    Serial.print('5');
    Serial.print('6');
    Serial.print('7');
    Serial.print('8');
    Serial.print('9');

    Serial.println();

    // Simple debounce
    delay(300);
  }else{
    digitalWrite(pinLed, LOW);
    }
}
