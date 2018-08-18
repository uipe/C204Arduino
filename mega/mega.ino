#include <SPI.h>
#include <mcp2515.h>

int power = -1;
int lastpower = -1;

const int remote = 8;

struct can_frame canMsg;
MCP2515 mcp2515(10);
const int can = 2;

// Setting up the counter
int reading = 0;
int lowest = -12;
int highest = 12;
int changeamnt = 1;

const int vra = 15;
const int vrb = 14;

// Timing for polling the encoder
unsigned long currentTime;
unsigned long lastTime;
unsigned long lastPowerTime;
unsigned long lastButtonTime;

// Storing the readings

boolean encA;
boolean encB;
boolean lastA = false;

const int b1 = 34;
const int b2 = 30;
const int b3 = 26;
const int b4 = 22;

const int b5 = 32;
const int b6 = 28;
const int b7 = 24;
const int b8 = 23;

const int b9 = 36;

const int b10 = 25;
const int b11 = 6;


const int b13 = 42;

const int b14 = 44;

const int b15 = 45;
const int b16 = 47;

const int b17 = 27;
const int b18 = 29;
const int b19 = 31;


const int b20 = 33;
const int b21 = 35;
const int b22 = 5;

const int b23 = 4;
const int b24 = 46;
const int b25 = 7;

const int bx = 40;



void setup() {
  Serial.begin(115200);

  power = -1;

  pinMode(remote, OUTPUT);
  digitalWrite(remote, LOW);
  // set the two pins as inputs with internal pullups
  pinMode(vra, INPUT_PULLUP);
  pinMode(vrb, INPUT_PULLUP);

  // Set up the timing of the polling
  currentTime = millis();
  lastPowerTime = currentTime;
  lastTime = currentTime;
  lastButtonTime = currentTime;


  //pinMode(41, OUTPUT);

  pinMode(b1, INPUT_PULLUP);
  pinMode(b2, INPUT_PULLUP);
  pinMode(b3, INPUT_PULLUP);
  pinMode(b4, INPUT_PULLUP);
  pinMode(b5, INPUT_PULLUP);
  pinMode(b6, INPUT_PULLUP);
  pinMode(b7, INPUT_PULLUP);
  pinMode(b8, INPUT_PULLUP);
  pinMode(b9, INPUT_PULLUP);
  pinMode(b10, INPUT_PULLUP);
  pinMode(b11, INPUT_PULLUP);

  pinMode(b13, INPUT_PULLUP);
  pinMode(b14, INPUT_PULLUP);
  pinMode(b15, INPUT_PULLUP);
  pinMode(b16, INPUT_PULLUP);
  pinMode(b17, INPUT_PULLUP);
  pinMode(b18, INPUT_PULLUP);
  pinMode(b19, INPUT_PULLUP);
  pinMode(b20, INPUT_PULLUP);
  pinMode(b21, INPUT_PULLUP);
  pinMode(b22, INPUT_PULLUP);
  pinMode(b23, INPUT_PULLUP);
  pinMode(b24, INPUT_PULLUP);
  pinMode(b25, INPUT_PULLUP);
  pinMode(bx, INPUT_PULLUP);

  SPI.begin();

  mcp2515.reset();
  mcp2515.setBitrate(CAN_125KBPS, MCP_8MHZ);
  mcp2515.setNormalMode();

}

void loop() {

  //ENCODER
  currentTime = millis();
  // Check if it's time to read
  if (currentTime >= (lastTime + 5))
  {
    // read the two pins
    encA = digitalRead(vra);
    encB = digitalRead(vrb);
    // check if A has gone from high to low
    if ((!encA) && (lastA))
    {
      if (encB)
      {
        Serial.write('+');
      }
      else
      {
        Serial.write('-');
      }
      // Output reading for debugging
    }
    // store reading of A and millis for next loop
    lastA = encA;
    lastTime = currentTime;

  }

  if (currentTime >= (lastButtonTime + 300))
  {

    if (digitalRead(bx) == LOW) {
      Serial.write('x');

      lastButtonTime = currentTime;
    } else  if (digitalRead(b1) == LOW) {
      Serial.write('a');
      lastButtonTime = currentTime;
    } else if (digitalRead(b2) == LOW) {
      Serial.write('b');
      lastButtonTime = currentTime;
    } else if (digitalRead(b3) == LOW) {
      Serial.write('c');
      lastButtonTime = currentTime;
    } else if (digitalRead(b4) == LOW) {
      Serial.write('d');
      lastButtonTime = currentTime;
    } else if (digitalRead(b5) == LOW) {
      Serial.write('e');
      lastButtonTime = currentTime;
    } else if (digitalRead(b6) == LOW) {
      Serial.write('f');
      lastButtonTime = currentTime;
    } else if (digitalRead(b7) == LOW) {
      Serial.write('g');
      lastButtonTime = currentTime;
    } else if (digitalRead(b8) == LOW) {
      Serial.write('h');
      lastButtonTime = currentTime;
    } else if (digitalRead(b9) == LOW) {
      Serial.write('y');
      lastButtonTime = currentTime;
    } else if (digitalRead(b10) == LOW) {
      Serial.write('<');
      lastButtonTime = currentTime;
    } else if (digitalRead(b11) == LOW) {
      Serial.write('>');
      lastButtonTime = currentTime;
      //}else if (digitalRead(b12)==HIGH) {
      // Serial.write('b');
    } else if (digitalRead(b13) == LOW) {
      Serial.write('k');
      lastButtonTime = currentTime;
    } else if (digitalRead(b14) == LOW) {
      Serial.write('1');
      lastButtonTime = currentTime;
    } else if (digitalRead(b15) == LOW) {
      Serial.write('2');
      lastButtonTime = currentTime;
    } else if (digitalRead(b16) == LOW) {
      Serial.write('3');
      lastButtonTime = currentTime;
    } else if (digitalRead(b17) == LOW) {
      Serial.write('4');
      lastButtonTime = currentTime;
    } else if (digitalRead(b18) == LOW) {
      Serial.write('5');
      lastButtonTime = currentTime;
    } else if (digitalRead(b19) == LOW) {
      Serial.write('6');
      lastButtonTime = currentTime;
    } else if (digitalRead(b20) == LOW) {
      Serial.write('7');
      lastButtonTime = currentTime;
    } else if (digitalRead(b21) == LOW) {
      Serial.write('8');
      lastButtonTime = currentTime;
    } else if (digitalRead(b22) == LOW) {
      Serial.write('9');
      lastButtonTime = currentTime;
    } else if (digitalRead(b23) == LOW) {
      Serial.write('*');
      lastButtonTime = currentTime;
    } else if (digitalRead(b24) == LOW) {
      Serial.write('0');
      lastButtonTime = currentTime;
    } else if (digitalRead(b25) == LOW) {
      Serial.write('#');
      lastButtonTime = currentTime;

    }
    if (mcp2515.readMessage(&canMsg) == MCP2515::ERROR_OK) {

      if (canMsg.can_id == 0x0de) {
        if (canMsg.data[0] == 0x03) {
          power = 0;

        } else if (canMsg.data[0] == 0x00) {
          power = 1;
        }
      }else if (canMsg.can_id == 0x045) {
        if (canMsg.data[4] == 0x10) {
          Serial.write('+');
          lastButtonTime = currentTime;

        } else if (canMsg.data[4] == 0x20) {
          Serial.write('-');
          lastButtonTime = currentTime;

        } else if (canMsg.data[4] == 0x80) {
          Serial.write('d');
          lastButtonTime = currentTime;

        } else if (canMsg.data[4] == 0x40) {
          Serial.write('h');
          lastButtonTime = currentTime;

        }
      }else if (canMsg.can_id == 0x3f6) {
        if (canMsg.data[1] == 0x10) {
          Serial.write('v');
          lastButtonTime = currentTime;

        }
      }

    }
  }
  if (lastpower != power && currentTime >= (lastPowerTime + 6000)) {
      if (power == 0 || power == -1) {
      digitalWrite(remote, LOW);
      Serial.write('w');
    } else if (power == 1) {
      digitalWrite(remote, HIGH);
      Serial.write('x');
    }
    lastPowerTime = currentTime;
    lastpower = power;
  }
    
}
