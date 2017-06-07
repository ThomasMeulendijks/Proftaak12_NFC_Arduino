String serialMessage = "";
String fullMessage = "";

String checkRemote() {
  fullMessage = "";
  //Serial.println("checking remote...");
  if (Serial.available() > 0)
  {
    char incomingChar = getChar();
    // # is used to indicate the start of a message
    if (incomingChar == '#')
    {
      collectingMessage = true;
    }
    // % is used to indicate the end of a message
    else if (incomingChar == '%')
    {
      collectingMessage = false;
      fullMessage = serialMessage;
      delay(100);
      serialMessage = "";
      return fullMessage;
    }
    else
    {
      // If # is recieved, start reading message
      if (collectingMessage == true)
      {
        serialMessage = serialMessage + incomingChar;
      }
    }
  }
  else {
    return fullMessage;
  }
}

char getChar()
{
  int readByte = Serial.read();
  char readChar = (char)readByte;
  return readChar;
}
