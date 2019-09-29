#ifndef STM32_GPIO_H
#define STM32_GPIO_H


#include "stm32_pin_list.h"

#define DIRECTION_MODE 	(0x000000FFU)
#define PULL_MODE 			(0x00000F00U)

#define INPUT 					(0x00000000U) 
#define OUTPUT 					(0x00000001U) 
#define INPUT_PULLUP 		(0x00000100U) 
#define INPUT_PULLDOWN	(0x00000200U)  	

#define ANALOG					(0x00000003U) 

#define OUTPUT_PP 			(0x00000002U)    
#define OUTPUT_OD 			(0x00000012U)   

#ifndef GPIO_SPEED_FREQ_VERY_HIGH
#define GPIO_SPEED_FREQ_VERY_HIGH GPIO_SPEED_FREQ_HIGH
#endif

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  GPIO_TypeDef *port;
  uint32_t pinMask;
} stm32_port_pin_type;

extern const stm32_port_pin_type variant_pin_list[NUM_DIGITAL_PINS];

inline GPIO_TypeDef* pinToPort(uint8_t pin) {
  return variant_pin_list[pin].port; 
}

inline uint32_t pinToBitMask(uint8_t pin) {
  return variant_pin_list[pin].pinMask; 
}

void pinMode(uint32_t pin, uint32_t mode );

inline void digitalWriteHigh(uint8_t pin) {
  stm32_port_pin_type port_pin = variant_pin_list[pin];
  HAL_GPIO_WritePin(port_pin.port, port_pin.pinMask, GPIO_PIN_SET);
}

inline void digitalWriteLow(uint8_t pin) {
  stm32_port_pin_type port_pin = variant_pin_list[pin];
  HAL_GPIO_WritePin(port_pin.port, port_pin.pinMask, GPIO_PIN_RESET);
}

inline void digitalWrite(uint8_t pin, uint8_t value) {
  stm32_port_pin_type port_pin = variant_pin_list[pin];
  HAL_GPIO_WritePin(port_pin.port, port_pin.pinMask, value ? GPIO_PIN_SET : GPIO_PIN_RESET);
}

inline void digitalToggle(uint8_t pin) {
  stm32_port_pin_type port_pin = variant_pin_list[pin];
  HAL_GPIO_TogglePin(port_pin.port, port_pin.pinMask);
}

inline int digitalRead(uint8_t pin) {
  stm32_port_pin_type port_pin = variant_pin_list[pin];
  return HAL_GPIO_ReadPin(port_pin.port, port_pin.pinMask);
}

#ifdef __cplusplus
}
#endif

#endif //STM32_GPIO_H
