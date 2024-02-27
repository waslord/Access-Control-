#include <MFRC522.h> 
#include <SPI.h>

#define CS_RFID 10
#define RST_RFID 9/



MFRC522 rfid(CS_RFID, RST_RFID); 

String id;

void setup() {

  Serial.begin(9600);
  SPI.begin(); 

  rfid.PCD_Init(); 
}

void loop() {
  
  if(rfid.PICC_IsNewCardPresent()) {
    readRFID();
    delay(10);
  }
  
}

void readRFID() {
  rfid.PICC_ReadCardSerial();
  id = String(rfid.uid.uidByte[0]) + " " + String(rfid.uid.uidByte[1]) + " " + 
    String(rfid.uid.uidByte[2]) + " " + String(rfid.uid.uidByte[3]);
  Serial.println(id);
}
