#include "Arduino.h"
#include "HardwareSerial.h"
#include "variant.h"
#include "stm32h7xx_hal_uart.h"
#include "usart.h"

//定义所有UART类实体
#define CHIPUART(name,a,b)	 HardwareSerial Serial##b( name##a);
CHIP_UART_LIST;
#undef CHIPUART

/**
   Set the underlying UART instance.
*/
HardwareSerial::HardwareSerial(USART_TypeDef *instance) {
  this->instance = instance;
}

void HardwareSerial::begin(const uint32_t baud) {

}

void HardwareSerial::end(void) {
  flush();
}

int HardwareSerial::available() {
   return 1;
}

int HardwareSerial::availableForWrite() {
  return 1;
}

int HardwareSerial::peek() {
    return 1;
}

void HardwareSerial::flush() {

}

int HardwareSerial::read() {
     return 1;
}

size_t HardwareSerial::write(const uint8_t c) {
	HAL_UART_Transmit(&huart3,(uint8_t*) &c,1,1000);
  return 1;
}

void HardwareSerial::stm32SetRX(uint8_t rx) {

}

void HardwareSerial::stm32SetTX(uint8_t tx) {

}

void HardwareSerial::setPins(uint8_t tx, uint8_t rx) {
  txPin = tx;
  rxPin = rx;
}


