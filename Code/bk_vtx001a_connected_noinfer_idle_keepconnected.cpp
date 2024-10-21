#include <Arduino.h>
#include <ECG2_inferencing.h>
#include <ArduinoBLE.h>

/**BLE UUID**/
const char* deviceServiceUuid = "19b10000-e8f2-537e-4f6c-d104768a1214";
const char* deviceServiceCharacteristicUuid = "19b10001-e8f2-537e-4f6c-d104768a1214";

/**Static ECG data**/
static const float ecg_sample_data[][260] = {
}; 


/**Adjusted inference structure for 2D array**/
typedef struct {
  const float (*buffer)[260];  // Pointer to a 2D array
  uint32_t buf_count;
  uint32_t n_samples;
  uint32_t n_rows;
} inference_t;

/**Initialize inference structure for 2D array**/
static inference_t inference = {
  ecg_sample_data,
  0,
  sizeof(ecg_sample_data[0]) / sizeof(ecg_sample_data[0][0]),
  sizeof(ecg_sample_data) / sizeof(ecg_sample_data[0])
};

static bool debug_nn = false;

/**Power Saver**/
void PowerSave_Settings(void){
  ///Saves 4mA
  digitalWrite(LED_PWR, LOW);   //Turn off the power LED
  digitalWrite(PIN_ENABLE_SENSORS_3V3, LOW);    //Turn off the sensors
  digitalWrite(PIN_ENABLE_I2C_PULLUP, LOW);   //Turn off the I2C pull-up resistors
}

/**Serial Settings
void Serial_Settings(void){
  Serial.begin(9600);
  while (!Serial);  
}**/


/**BLE Pre-Settings**/
void BLE_Settings(void){
  if (!BLE.begin()) {
    while (1);
  }
  BLE.setLocalName("Nano 33 BLE (Central)");
  BLE.advertise();
  BLE.end();
}


/**Get raw ECG signal data for a specific row in the 2D array**/
static int ecg_signal_get_data(size_t offset, size_t length, float *out_ptr) {
  if (offset + length > inference.n_samples) {
      return -1; // Out of range
  }
  for (size_t i = 0; i < length; ++i) {
      out_ptr[i] = inference.buffer[inference.buf_count][offset + i];
  }
  return 0;
}


/************************************/
void split_send(int row, BLECharacteristic TransMSG) {
  int batch_lenth = 20;
  for (int i = 0; i < 260; i += batch_lenth) {
    char dataCharArray[256] = {0}; // Initialize the array to zeros
    //String rowStr = String(row) + ":";
    //rowStr.toCharArray(dataCharArray, sizeof(dataCharArray));

    char rowStr[12]; // Buffer for the row number
    snprintf(rowStr, sizeof(rowStr), "%d:", row); // Convert row number to string
    strcat(dataCharArray, rowStr); // Append row string to the dataCharArray

    for (int j = i; j < i + batch_lenth && j < 260; ++j) {
      char temp[8]; // Temp buffer for individual float conversion
      snprintf(temp, sizeof(temp), "%.9f", ecg_sample_data[row][j]);
      
      strcat(dataCharArray, temp); // Append the converted float to the array

      if (j < i + (batch_lenth - 1) && j < 259) {
        strcat(dataCharArray, ","); // Append a comma if not the last element
      }
    }

    //Serial.println(String(dataCharArray));

    TransMSG.writeValue(dataCharArray); // Send the data
  }
}

/************************************/
void Inference_BLE(){
  while(!BLE.begin());
  BLEDevice peripheral;
  while(!peripheral){
    BLE.scanForUuid(deviceServiceUuid);
    peripheral = BLE.available();
  }
  BLE.stopScan();
  if (peripheral.connect()) {
  } else {
    return;
  }

  if (peripheral.discoverAttributes()) {
  } else {
    peripheral.disconnect();
    return;
  }

  BLECharacteristic TransMSG = peripheral.characteristic(deviceServiceCharacteristicUuid);

  for (uint32_t row = 0; row < inference.n_rows; row++) {

    split_send(row, TransMSG);
    delay(650);

  }

  BLE.end();
  delay(100000);
}


/************************************/
void setup(){
  //Serial_Settings();
  PowerSave_Settings();
  BLE_Settings();
}

/************************************/
void loop() {
  Inference_BLE();
}

/************************************/
int main(void){
  init();
  initVariant();

  //Disabling UART0 (saves around 300-500¦ÌA)
  NRF_UART0->TASKS_STOPTX = 1;
  NRF_UART0->TASKS_STOPRX = 1;
  NRF_UART0->ENABLE = 0;

  *(volatile uint32_t *)0x40002FFC = 0;
  *(volatile uint32_t *)0x40002FFC;
  *(volatile uint32_t *)0x40002FFC = 1; //Setting up UART registers again due to a library issue

  //Removing USB CDC feature
  //#if defined(SERIAL_CDC)
  //  PluggableUSBD().begin();
  //  SerialUSB.begin(115200);
  //#endif

  setup();
  for(;;){
    loop();
  //If you won't be using serial communication comment next line
  //    if(arduino::serialEventRun) arduino::serialEventRun();
  }
  return 0;
}



