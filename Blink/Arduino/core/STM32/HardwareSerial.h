#ifndef _HARDWARESERIAL_H_
#define _HARDWARESERIAL_H_

#include "variant.h"
#include "Stream.h"
#include "util/toolschain.h"

class HardwareSerial : public Stream{
  public:
    HardwareSerial(USART_TypeDef *instance);
    void begin(const uint32_t baud = 115200);
    void end(void);
    int available(void);
    int availableForWrite();
    int peek(void);
    int read(void);
    void flush(void);
    size_t write(const uint8_t c);
    using Print::write; // pull in write(str) and write(buf, size) from Print
    operator bool() {
      return true;
    }; // UART always active

		void stm32SetRX(uint8_t rx) ;
		void stm32SetTX(uint8_t tx) ;
    void setPins(uint8_t tx, uint8_t rx);

    USART_TypeDef *instance = NULL;
    UART_HandleTypeDef *handle = NULL;

    uint8_t receive_buffer = 0;
    uint8_t *txBuffer = NULL;

    volatile uint16_t txStart = 0;
    volatile uint16_t txEnd = 0;

    uint8_t *rxBuffer = NULL;

    volatile uint16_t rxStart = 0;
    volatile uint16_t rxEnd = 0;

    uint8_t rxPin = 0xff;
    uint8_t txPin = 0xff;

  private:
    uint8_t _config;
};

//声明所有UART类实体
#define CHIPUART(name,a,b)	extern HardwareSerial Serial##b;
CHIP_UART_LIST;
#undef CHIPUART

#endif // _HARDWARESERIAL_H_
