#ifndef STM32_PIN_LIST_H
#define STM32_PIN_LIST_H

#include "variant.h"

#define PIN_LIST CHIP_PIN_LIST

#define PIN(a, b) __P##a##b
enum {
  PIN_LIST
  NUM_DIGITAL_PINS,
};
#undef PIN

#ifdef __cplusplus

class __ConstPin {
  public:
    constexpr __ConstPin(const int ulPortBase, const int pinMask, const int ucPin): ulPortBase(ulPortBase), pinMask(pinMask), ucPin(ucPin) {};
    constexpr operator int() const {
      return ucPin;
    }
    const int ulPortBase;
    const int pinMask;
    const int ucPin;
};

#define PIN(a, b) P##a##b(GPIO##a##_BASE,GPIO_PIN_##b,__P##a##b)
constexpr __ConstPin PIN_LIST __IGNORE(0, 0, -1);
#undef PIN

#endif  //__cplusplus

#endif  //STM32_PIN_LIST_H
