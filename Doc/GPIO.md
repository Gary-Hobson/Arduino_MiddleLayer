# GPIO有关函数及文件说明
##  有关文件：  
```
|   -   Arduino
    |   -   core  
        |   -  stm32_gpio.cpp
        |   -  stm32_gpio.h
        |   -  stm32_pin_list.c
        |   -  stm32_pin_list.h
    |   -   Variant
        |   -   variant.h
```
## 文件说明
stm32_gpio.x：  是有关GPI操作函数的定义和声明

stm32_pin_list.x:   芯片引脚映射有关文件，通过不同的宏展开，定义IO映射数组和IO索引枚举数据类型

variat.h    ：不同芯片IO资源定义宏


## 支持API
```C++
int digitalRead(uint8_t pin)
void digitalToggle(uint8_t pin)
void digitalWriteLow(uint8_t pin)
void digitalWriteHigh(uint8_t pin)
void digitalWrite(uint8_t pin, uint8_t value)
void pinMode(uint32_t pin, uint32_t mode )
```

版本：0.0.1  
日期：2019年9月29日
