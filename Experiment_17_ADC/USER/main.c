#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "lcd.h"
#include "usmart.h"
#include "adc.h"
/************************************************
 ALIENTEK 战舰STM32F103开发板 实验17
 ADC模数转换实验-HAL库函数版
 技术支持：www.openedv.com
 淘宝店铺： http://eboard.taobao.com
 关注微信公众平台微信号："正点原子"，免费获取STM32资料。
 广州市星翼电子科技有限公司
 作者：正点原子 @ALIENTEK
************************************************/

int main(void)
{
    u16 adcx;
    float temp;

    HAL_Init();                         //初始化HAL库
    Stm32_Clock_Init(RCC_PLL_MUL9);     //设置时钟,72M
    delay_init(72);                     //初始化延时函数
    uart_init(115200);                  //初始化串口
    usmart_dev.init(84);                //初始化USMART
    LED_Init();                         //初始化LED
    LCD_Init();                         //初始化LCD FSMC接口
    MY_ADC_Init();                      //初始化ADC1通道1

    POINT_COLOR = RED;
    LCD_ShowString(30, 50, 200, 16, 16, "WarShip STM32");
    LCD_ShowString(30, 70, 200, 16, 16, "ADC TEST");
    LCD_ShowString(30, 90, 200, 16, 16, "ATOM@ALIENTEK");
    LCD_ShowString(30, 110, 200, 16, 16, "2017/5/29");
    POINT_COLOR = BLUE; //设置字体为蓝色
    LCD_ShowString(30, 130, 200, 16, 16, "ADC1_CH1_VAL:");
    LCD_ShowString(30, 150, 200, 16, 16, "ADC1_CH1_VOL:0.000V"); //先在固定位置显示小数点
    while(1)
    {
        adcx = Get_Adc_Average(ADC_CHANNEL_1, 20); //获取通道1的转换值，20次取平均
        LCD_ShowxNum(134, 130, adcx, 4, 16, 0); //显示ADCC采样后的原始值
        temp = (float)adcx * (3.3 / 4096);    //获取计算后的带小数的实际电压值，比如3.1111
        adcx = temp;                          //赋值整数部分给adcx变量，因为adcx为u16整形
        LCD_ShowxNum(134, 150, adcx, 1, 16, 0); //显示电压值的整数部分，3.1111的话，这里就是显示3
        temp -= adcx;                         //把已经显示的整数部分去掉，留下小数部分，比如3.1111-3=0.1111
        temp *= 1000;                         //小数部分乘以1000，例如：0.1111就转换为111.1，相当于保留三位小数。
        LCD_ShowxNum(150, 150, temp, 3, 16, 0X80); //显示小数部分（前面转换为了整形显示），这里显示的就是111.
        LED0 = !LED0;
        delay_ms(250);
    }
}

