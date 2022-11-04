void Measurement()
{
  long now = millis();
  if (now - lastMeasured > MEASURING_INTERVAL)
  {
      lastMeasured = now;
    test++;
    if (test > 99) test = 0;
    
    // send packet
    LoRa.beginPacket();
    //LoRa.print(F("Pkt No:"));
    LoRa.println(test);
  
    LoRa.endPacket();
  }
}

void onReceive(int packetSize)
{
  int goodRec = 0;
  int rec = 0;

  if (packetSize > 25)
  {
    for (char c='a'; c<'z'; c++)
    {
      if (c == (char)LoRa.read())
      {
        goodRec++;
      }
      rec++;
    }
    for (char c='A'; c<'Z'; c++)
    {
      if (c == (char)LoRa.read())
      {
        goodRec++;
      }
      rec++;
    }

    int rssi = LoRa.packetRssi();


    // send packet
      LoRa.beginPacket();

      char sendBuffer[255];
      int i= 0;
      for (char c='A'; c<'Z'; c++)
      {
        sendBuffer[i] = c;
        i++;
      }
      for (char c='a'; c<'z'; c++)
      {
        sendBuffer[i] = c;
        i++;
      }

      char buffer[10];
      sprintf(buffer, "%2d", goodRec);

      sendBuffer[i++] = buffer[0];
      sendBuffer[i++] = buffer[1];

      sprintf(buffer, "%3d", rssi);
      sendBuffer[i++] = buffer[0];
      sendBuffer[i++] = buffer[1];
      sendBuffer[i++] = buffer[2];
      sendBuffer[i++] = buffer[3];
      sendBuffer[i] = '\0';

      LoRa.println(sendBuffer);
  
      LoRa.endPacket();

      LoRa.receive();
  }
}