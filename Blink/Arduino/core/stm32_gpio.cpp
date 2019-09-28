#include "stm32_gpio.h"

extern "C"
void stm32GpioClockEnable(GPIO_TypeDef *port) {

#ifdef GPIOA
  if (port == GPIOA) __HAL_RCC_GPIOA_CLK_ENABLE();
#endif
#ifdef GPIOB
  if (port == GPIOB) __HAL_RCC_GPIOB_CLK_ENABLE();
#endif
#ifdef GPIOC
  if (port == GPIOC) __HAL_RCC_GPIOC_CLK_ENABLE();
#endif
#ifdef GPIOD
  if (port == GPIOD) __HAL_RCC_GPIOD_CLK_ENABLE();
#endif
#ifdef GPIOE
  if (port == GPIOE) __HAL_RCC_GPIOE_CLK_ENABLE();
#endif
#ifdef GPIOF
  if (port == GPIOF) __HAL_RCC_GPIOF_CLK_ENABLE();
#endif
#ifdef GPIOG
  if (port == GPIOG) __HAL_RCC_GPIOG_CLK_ENABLE();
#endif
#ifdef GPIOH
  if (port == GPIOH) __HAL_RCC_GPIOH_CLK_ENABLE();
#endif
#ifdef GPIOI
  if (port == GPIOI) __HAL_RCC_GPIOI_CLK_ENABLE();
#endif
#ifdef GPIOJ
  if (port == GPIOJ) __HAL_RCC_GPIOJ_CLK_ENABLE();
#endif
#ifdef GPIOK
  if (port == GPIOK) __HAL_RCC_GPIOK_CLK_ENABLE();
#endif
}

extern "C"
void pinMode(uint32_t pin, uint32_t mode)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	stm32_port_pin_type port_pin = variant_pin_list[pin];

  /* GPIO Ports Clock Enable */
	stm32GpioClockEnable(port_pin.port);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(port_pin.port, port_pin.pinMask, GPIO_PIN_RESET);

  /*Configure GPIO pin : PtPin */
  GPIO_InitStruct.Pin = port_pin.pinMask;
  GPIO_InitStruct.Mode = mode & DIRECTION_MODE;
  GPIO_InitStruct.Pull = mode & PULL_MODE;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  HAL_GPIO_Init(port_pin.port, &GPIO_InitStruct);
}


