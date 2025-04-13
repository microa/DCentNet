#include <ArduinoBLE.h>

void setup() {
  Serial.begin(9600);
  while (!Serial);

  if (!BLE.begin()) {
    Serial.println("Failed to activate BLE module");
    while (1);
  }

  Serial.println("Searching BLE broadcast signals...");
  BLE.scan(true); // Start to continue searching BLE broadcast signal
}

void loop() {
  // Detecting BLE devices
  BLEDevice foundDevice = BLE.available();
  if (foundDevice) {
    String deviceName = foundDevice.localName();
    String numberStr = deviceName.c_str();
    Serial.print("Receiving: ");
    Serial.println(numberStr);

  }
}
