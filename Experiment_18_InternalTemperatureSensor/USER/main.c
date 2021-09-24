#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "lcd.h"
#include "usmart.h"
#include "adc.h"
/************************************************
 ALIENTEK 战舰STM32F103开发板 实验18
 内部温度传感器实验-HAL库函数版
 技术支持：www.openedv.com
 淘宝店铺： http://eboard.taobao.com
 关注微信公众平台微信号："正点原子"，免费获取STM32资料。
 广州市星翼电子科技有限公司
 作者：正点原子 @ALIENTEK
************************************************/

int main(void)
{
    short temp;

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
    LCD_ShowString(30, 70, 200, 16, 16, "Temperature TEST");
    LCD_ShowString(30, 90, 200, 16, 16, "ATOM@ALIENTEK");
    LCD_ShowString(30, 110, 200, 16, 16, "2017/5/29");
    POINT_COLOR = BLUE; //设置字体为蓝色
    LCD_ShowString(30, 140, 200, 16, 16, "TEMPERATE: 00.00C"); //先在固定位置显示小数点
    while(1)
    {
        temp = Get_Temprate();  //得到温度值
        if(temp < 0)
        {
            temp = -temp;
            LCD_ShowString(30 + 10 * 8, 140, 16, 16, 16, "-"); //显示负号
        }
        else LCD_ShowString(30 + 10 * 8, 140, 16, 16, 16, " "); //无符号

        LCD_ShowxNum(30 + 11 * 8, 140, temp / 100, 2, 16, 0); //显示整数部分
        LCD_ShowxNum(30 + 14 * 8, 140, temp % 100, 2, 16, 0); //显示小数部分

        LED0 = !LED0;
        delay_ms(250);
    }
}

