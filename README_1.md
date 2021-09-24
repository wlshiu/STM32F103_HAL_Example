# [STM32F103-HAL-example-code](https://github.com/StrangeChen/STM32F103-HAL-example-code)
stm32f103的HAL庫例程


## 軟件版本
MDK: 5.26
stm32cubemx: 4.27.0
keil package: Keil.STM32F1 xx_DFP.2.1.0
cube package: STM32Cube_FW_F1_V1.6.0
## 芯片&引腳定義
stm32f103vet6

|功能|引腳|
|---|---|
|led_green|PB0|
|led_blue|PB1|
|led_red |PB5|
|key_1|PA0|
|key_2|PC13|
## 文件說明
1. 基礎代碼均由cubemx生成
2. deley.c/delay.h 為延時函數實現，包括微秒級和毫秒級延時，彌補HAL_Delay()同過中斷實現延時的缺陷
3. sys.h 文件中將常用數據類型簡化，如`typedef uint8_t  u8;`，以及實現51類似的GPIO控制功能，eg：	`PAout(n),PAin(n) `
4. interrupt_callback.c為中斷回調函數聚集地
5. keilkill.bat為清除編譯生成文件的腳本
## 例程說明
### key_control_led
按鍵控制led燈亮滅，按下按鍵改變led狀態
### key_control_led_by_interrupt
通過EXIT中斷方式，使用按鍵控制led亮滅，效果和上一程序相同
### uart_receive_and_transmit
|功能 |引腳 |
|---|----|
|RX|PA10|
|TX|PA9|

使用USART1，波特率9600，使用串口調試助手發送『1』控制led翻轉並回傳告知燈亮/燈滅，發送其他字符單片機回傳。
### uart_receive_interrupt
通過串口接收中斷實現上述操作，注意開啟接收中斷和中斷回調函數的寫法。
### timer_base
定時器基礎功能使用，使用TIM2，每一秒進一次中斷，通過USART1打印出單片機運行時間，格式為：00:00:00，同時實現流水燈，紅、藍、綠三燈依次亮滅。注意定時器Prescaler和Counter Period參數配置。
### timer_pwm
利用定時器輸出PWM波，使用TIM3_CH3，映射至PB0，實現呼吸燈功能，即漸亮漸滅。注意注意定時器**Prescaler**和**Counter Period**參數配置；注意**PWM Mode**和**CH Polarity**配置,具體配置根據自己實際情況設計。
### timer_input_capture
TIM3_CH1輸出PWM波，TIM8_CH2捕獲PWM，通過定時器捕獲實現獲取PWM波週期、占空比等信息，並通過串口打印出來。利用定時器輸入捕獲功能時注意**Prescaler**的設置，Prescaler的參數關係到捕獲的精度。
### timer_encoder
開啟定時器TIM3的編碼器模式，對正交編碼器解碼。利用TIM2，每10ms讀一次TIM3計數值並清零，從而獲取編碼器單位時間按內的增量，即旋轉速度。高級定時器和部分通用定時器有此功能。注意**Encoder Mode**和**Polarity**的設置。
***