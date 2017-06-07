#include <SPI.h>
#include "PN532_SPI.h"
#include "PN532.h"
#include "NfcAdapter.h"



PN532_SPI interface(SPI, 10); // create a SPI interface for the shield with the SPI CS terminal at digital pin 10
NfcAdapter nfc = NfcAdapter(interface); // create an NFC adapter object

bool collectingMessage = false;
const int buzzPin = 2;
String cUID = "";

void setup() {
  Serial.begin(115200);
  nfc.begin();
  pinMode(buzzPin, OUTPUT);
  digitalWrite(buzzPin, HIGH);
  delay(1000);
  digitalWrite(buzzPin, LOW);

}

void loop() {

  //scan for nfc chip and use
  if (collectingMessage == false) {
    cUID = NfcScan();
    if (cUID != "") {
        Serial.println("#LOCK:" + cUID + "%");
    }
  }
    // If a message is recieved check if the user is outhorised
    String recievedMessage = checkRemote();
    //If checkremote(); has an output use this outpout to determine whats gone happen
    if (recievedMessage != "") {
      ProccesSM(recievedMessage);
    }
}

