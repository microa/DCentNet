// ����D2��Ϊ�ⲿ�жϿ�
const int interruptPin = 2;
// ����LED״̬��־
volatile bool ledState = false;






void setup() {
  // ��ʼ������ͨ��
  // ����LEDΪ���
  pinMode(LED_BUILTIN, OUTPUT);
  // ����D2��Ϊ����
  pinMode(interruptPin, INPUT_PULLUP);
  // �����ⲿ�жϣ���D2�ڼ�⵽�½���ʱ������interruptRoutine
  attachInterrupt(digitalPinToInterrupt(interruptPin), interruptRoutine, FALLING);

  digitalWrite(PIN_ENABLE_SENSORS_3V3, LOW);

  digitalWrite(PIN_ENABLE_I2C_PULLUP, LOW);

  digitalWrite(LED_PWR, LOW);

  NRF_POWER->SYSTEMOFF = 1;
}

void LED(){
  digitalWrite(LED_BUILTIN, HIGH);
  delay(200);
  digitalWrite(LED_BUILTIN, LOW);
  delay(200);
}

void loop() {
  LED();
  NRF_POWER->SYSTEMOFF = 1;
}

// �жϷ�������
void interruptRoutine() {
  loop(); // �л�LED״̬
}

int main(void){
  init();
  initVariant();

  //Disabling UART0 (saves around 300-500��A)
  NRF_UART0->TASKS_STOPTX = 1;
  NRF_UART0->TASKS_STOPRX = 1;
  NRF_UART0->ENABLE = 0;
  //NRF_POWER->SYSTEMOFF = 1;

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
