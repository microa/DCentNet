// 定义D2口为外部中断口
const int interruptPin = 2;
// 定义LED状态标志
volatile bool ledState = false;






void setup() {
  // 初始化串行通信
  // 设置LED为输出
  pinMode(LED_BUILTIN, OUTPUT);
  // 设置D2口为输入
  pinMode(interruptPin, INPUT_PULLUP);
  // 配置外部中断，当D2口检测到下降沿时，调用interruptRoutine
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

// 中断服务例程
void interruptRoutine() {
  loop(); // 切换LED状态
}

int main(void){
  init();
  initVariant();

  //Disabling UART0 (saves around 300-500μA)
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
