#include <SoftwareSerial.h>

int RX_pin = 13;
int TX_pin = 12;
SoftwareSerial BTserial(RX_pin, TX_pin);

String BT_data;
String Arduino_data;

void setup() {
  Serial.begin(9600);
  BTserial.begin(9600);
}

void loop() {
  if (BTserial.available()) {
    BT_data = BTserial.readString();
    Serial.println(BT_data);
  }

  if (Serial.available()) {
    Arduino_data = Serial.readString();
    BTserial.println(Arduino_data);
  }
}
