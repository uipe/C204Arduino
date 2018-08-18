/*
 Copyright (c) 2014-2015 NicoHood
 See the readme for credit to other people.
 Serial HID-Bridge USB
 Select HoodLoader16u2 as board.
 After upload make sure the 16u2 sketch runs, not the HoodLoader2 bootloader.
 This example will type any serial data via keyboard.
*/

#include "HID-Project.h"

#include "USBCore.h"

void setup() {
  // Start the Serial1 which is connected with the IO MCU.
  // Make sure both baud rates are the same
  // you can go up to 2000000 for very fast data transmission.
  Serial1.begin(115200);

  // Sends a clean report to the host. This is important on any Arduino type.
  Consumer.begin();
  Keyboard.begin();

  // Start the USB Serial for debugging
  Serial.begin(115200);
}

void loop() {
  // Check if any Serial data from the IO MCU was received
  char c = Serial1.read();



  // If it's a character, print it!

  
  if (c == '>') {
    Consumer.write(MEDIA_NEXT);
    Serial.println(c);
  
  }
  else if (c == '<') {
    Consumer.write(MEDIA_PREVIOUS);
    Serial.println(c);
  
  }
  
  else if (c == '+') {
    Consumer.write(MEDIA_VOLUME_UP);
    Serial.println(c);
  
  }else if (c == '-') {
    Consumer.write(MEDIA_VOLUME_DOWN);
    Serial.println(c);
  }else if (c == 'k') {
    Consumer.write(CONSUMER_BROWSER_BACK);
    Serial.println(c);
    }
    else if (c == 'y') {
    Consumer.write(CONSUMER_BROWSER_HOME);
   Serial.println(c);
  }else if (c == 'x') {
    Consumer.write(CONSUMER_POWER);
   Serial.println(c);
  }

  
  
  else if (c == 'a') {
    
   
    Keyboard.press(KEY_F1);
    Keyboard.releaseAll();
   Serial.println(c);
  }

  else if (c == 'b') {
    Keyboard.press(KEY_F2);
    Keyboard.releaseAll();
    Serial.println(c);
  }
  else if (c == 'c') {
    Consumer.write(MEDIA_VOL_MUTE);
    Serial.println(c);
  }
  else if (c == 'd') {
    Keyboard.press(KEY_F3);
    Keyboard.releaseAll();
    Serial.println(c);
  }else if (c == 'e') {
    Keyboard.press(KEY_F4);
    Keyboard.releaseAll();
    Serial.println(c);
  }else if (c == 'f') {
    Keyboard.press(KEY_F5);
    Keyboard.press(c);
    Keyboard.releaseAll();
    Serial.println(c);
  }else if (c == 'g') {
    Keyboard.press(KEY_F6);
    Keyboard.releaseAll();
    Serial.println(c);
  }else if (c == 'h') {
    Keyboard.press(KEY_F7);
    Keyboard.releaseAll();
    Serial.println(c);
  }else if (c == 'w') {
    Keyboard.press(KEY_F8);
    Keyboard.releaseAll();
    Serial.println(c);
  }
  
  
  
  else 
  
  if ( (c >= '!' && c <= 'z')) {
    Keyboard.press(c);
    Keyboard.releaseAll();
    Serial.println(c);
  }
  Keyboard.releaseAll();
  
    USBDevice.wakeupHost();
}
