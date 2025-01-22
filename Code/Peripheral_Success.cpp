//peripheral
#include <ArduinoBLE.h>

const char* deviceServiceUuid = "19b10000-e8f2-537e-4f6c-d104768a1214";
const char* deviceServiceCharacteristicUuid = "19b10001-e8f2-537e-4f6c-d104768a1214";

BLEService gestureService(deviceServiceUuid); 
BLEStringCharacteristic gestureCharacteristic(deviceServiceCharacteristicUuid, BLERead | BLEWrite, 20); // ��Ϊ�����ַ�������

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
  BLE.setAdvertisedService(gestureService);
  gestureService.addCharacteristic(gestureCharacteristic);
  BLE.addService(gestureService);
  gestureCharacteristic.writeValue("Waiting..."); // ��ʼֵ����Ϊ�ȴ�״̬
  BLE.advertise();

  Serial.println("Nano 33 BLE (Peripheral Device)");
  Serial.println(" ");
}

void loop() {
  BLEDevice central = BLE.central();
  Serial.println("- Discovering central device...");
  delay(500);

  if (central) {
    Serial.println("* Connected to central device!");
    Serial.print("* Device MAC address: ");
    Serial.println(central.address());
    Serial.println(" ");

    while (central.connected()) {
      if (gestureCharacteristic.written()) {
        String receivedValue = gestureCharacteristic.value(); // ��ȡ���յ����ַ���
        transmitReceivedValue(receivedValue); // ͨ������ת�����յ����ַ���
      }
    }
    
    Serial.println("* Disconnected to central device!");
  }
}

void transmitReceivedValue(String value) {
  Serial.print("Received Value: ");
  Serial.println(value);
  // �������������Ӹ�����߼���������յ�������
}
