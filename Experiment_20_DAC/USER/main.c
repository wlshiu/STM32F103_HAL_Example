#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "key.h"
#include "lcd.h"
#include "usmart.h"
#include "adc.h"
#include "dac.h"
/************************************************
 ALIENTEK 战舰STM32F103开发板 实验20
 DAC实验-HAL库函数版
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
    u8 t = 0;
    u16 dacval = 0;
    u8 key;

    HAL_Init();                         //初始化HAL库
    Stm32_Clock_Init(RCC_PLL_MUL9);     //设置时钟,72M
    delay_init(72);                     //初始化延时函数
    uart_init(115200);                  //初始化串口
    usmart_dev.init(84);                //初始化USMART
    LED_Init();                         //初始化LED
    KEY_Init();                         //初始化按键
    LCD_Init();                         //初始化LCD FSMC接口
    MY_ADC_Init();                      //初始化ADC1通道1
    DAC1_Init();                        //初始化DAC1

    POINT_COLOR = RED;
    LCD_ShowString(30, 50, 200, 16, 16, "WarShip STM32");
    LCD_ShowString(30, 70, 200, 16, 16, "DAC TEST");
    LCD_ShowString(30, 90, 200, 16, 16, "ATOM@ALIENTEK");
    LCD_ShowString(30, 110, 200, 16, 16, "2017/5/29");
    LCD_ShowString(30, 130, 200, 16, 16, "WK_UP:+  KEY1:-");
    POINT_COLOR = BLUE; //设置字体为蓝色
    LCD_ShowString(30, 150, 200, 16, 16, "DAC VAL:");
    LCD_ShowString(30, 170, 200, 16, 16, "DAC VOL:0.000V");
    LCD_ShowString(30, 190, 200, 16, 16, "ADC VOL:0.000V");

    HAL_DAC_SetValue(&DAC1_Handler, DAC_CHANNEL_1, DAC_ALIGN_12B_R, 0); //初始值为0
    while(1)
    {
        t++;
        key = KEY_Scan(0);
        if(key == WKUP_PRES)
        {
            if(dacval < 4000)dacval += 200;
            HAL_DAC_SetValue(&DAC1_Handler, DAC_CHANNEL_1, DAC_ALIGN_12B_R, dacval); //设置DAC值
        }
        else if(key == 2)
        {
            if(dacval > 200)dacval -= 200;
            else dacval = 0;
            HAL_DAC_SetValue(&DAC1_Handler, DAC_CHANNEL_1, DAC_ALIGN_12B_R, dacval); //设置DAC值
        }
        if(t == 10 || key == KEY1_PRES || key == WKUP_PRES) //WKUP/KEY1按下了,或者定时时间到了
        {
            adcx = HAL_DAC_GetValue(&DAC1_Handler, DAC_CHANNEL_1); //读取前面设置DAC的值
            LCD_ShowxNum(94, 150, adcx, 4, 16, 0);      //显示DAC寄存器值
            temp = (float)adcx * (3.3 / 4096);          //得到DAC电压值
            adcx = temp;
            LCD_ShowxNum(94, 170, temp, 1, 16, 0);      //显示电压值整数部分
            temp -= adcx;
            temp *= 1000;
            LCD_ShowxNum(110, 170, temp, 3, 16, 0X80);  //显示电压值的小数部分
            adcx = Get_Adc_Average(ADC_CHANNEL_1, 10);  //得到ADC转换值
            temp = (float)adcx * (3.3 / 4096);          //得到ADC电压值
            adcx = temp;
            LCD_ShowxNum(94, 190, temp, 1, 16, 0);      //显示电压值整数部分
            temp -= adcx;
            temp *= 1000;
            LCD_ShowxNum(110, 190, temp, 3, 16, 0X80);  //显示电压值的小数部分
            LED0 = !LED0;
            t = 0;
        }
        delay_ms(10);
    }
}

