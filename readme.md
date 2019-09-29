# keil arduino库支持

这个库为在Keil MDK环境中支持Arduino第三方库的中间件，目前开发平台为STM32，硬件测试平台为STM32H743ZIT6 NUCLEO(目前手头在用这个开发板，所以就直接用这个开发了)，使用STM32CUBE MX进行底层支持。
  
Arduino接口层应用结构如图所示：  

![应用结构](https://raw.githubusercontent.com/wiki/Gary-Hobson/Arduino_MiddleLayer/1.jpg "应用结构")

## 版本日志
1. 添加GPIO 兼容

## 目录结构
```
|	–	Arduino  兼容层文件
	|	-Core	Arduino内核文件
	|	-Variant	硬件资源定义
	|	-Blink.cpp	用户文件，可使用arduino库函数和HAL库函数
|	–	Drivers HAL库文件
	|	-	Inc	用户头文件
	|	-	src	用户源文件	
|	–	MDK-ARM	keil工程文件夹
|	–	readme.md	自述文件
|	–	开发日志.log	开发日志
|	-	Blink.ioc	stm32Cube工程文件
|	-	.mxproject	stm32Cube工程文件
```

## 使用说明

1. 在Blink.cpp中编写用户函数，steup()和loop()已在main函数中调用
2. 闪灯程序可运行

版本：0.0.1  
日期：2019年9月30日
