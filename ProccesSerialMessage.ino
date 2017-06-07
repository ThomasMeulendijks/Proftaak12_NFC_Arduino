void ProccesSM(String recievedSerialMessage) {
  if (recievedSerialMessage == "y") {
    /*door open*/
    digitalWrite(buzzPin, HIGH);
    delay(1000);
    /*door closed*/
    digitalWrite(buzzPin, LOW);
  }
  else if (recievedSerialMessage == "n") {
    digitalWrite(buzzPin, HIGH);
    delay(200);
    digitalWrite(buzzPin, LOW);
    delay(200);
    digitalWrite(buzzPin, HIGH);
    delay(200);
    digitalWrite(buzzPin, LOW);
    delay(200);
    digitalWrite(buzzPin, HIGH);
    delay(200);
    digitalWrite(buzzPin, LOW);
    delay(200);
  }
  else {
    digitalWrite(buzzPin, HIGH);
    delay(600);
    digitalWrite(buzzPin, LOW);
    delay(200);
    digitalWrite(buzzPin, HIGH);
    delay(200);
    digitalWrite(buzzPin, LOW);
    delay(200);
  }
}
