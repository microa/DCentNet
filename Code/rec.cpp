//peripheral
#include <ArduinoBLE.h>

const char* deviceServiceUuid = ""; //please add your id here
const char* deviceServiceCharacteristicUuid = ""; //please add your id here

BLEService ReceiverService(deviceServiceUuid); 
BLEStringCharacteristic ReceiverCharacteristic(deviceServiceCharacteristicUuid, BLERead | BLEWrite, 4096);

unsigned long previousMillis = 0;
const long interval = 500;

void setup() {
  Serial.begin(115200);
  while (!Serial);  
  
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);

  if (!BLE.begin()) {
    Serial.println("- Starting Bluetooth? Low Energy module failed!");
    while (1);
  }

  BLE.setLocalName("Arduino Nano 33 BLE (Peripheral)");
  BLE.setAdvertisedService(ReceiverService);
  ReceiverService.addCharacteristic(ReceiverCharacteristic);
  BLE.addService(ReceiverService);
  ReceiverCharacteristic.writeValue("Waiting...");
  BLE.advertise();

  Serial.println("Nano 33 BLE (Peripheral Device)");
  Serial.println(" ");
}

void loop() {
  BLEDevice central = BLE.central();

  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    Serial.println("- Discovering central device...");
  }
  //Serial.println("- Discovering central device...");
  //delay(500);

  if (central) {
    Serial.println("* Connected to central device!");
    Serial.print("* Device MAC address: ");
    Serial.println(central.address());
    Serial.println(" ");

    while (central.connected()) {
      if (ReceiverCharacteristic.written()) {
        String receivedValue = ReceiverCharacteristic.value();
        transmitReceivedValue(receivedValue);
      }
    }
    
    Serial.println("* Disconnected to central device!");
  }
}

void transmitReceivedValue(String value) {
  Serial.print("Received Value: ");
  Serial.println(value);
}
