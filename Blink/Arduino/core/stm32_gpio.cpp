#include "Arduino.h"
#include "stm32_gpio.h"

extern "C"
void pinMode(uint8_t pin, uint8_t mode)
{
	stm32_port_pin_type port_pin = variant_pin_list[pin];
}
