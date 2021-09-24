#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "lcd.h"
#include "usmart.h"
/************************************************
 ALIENTEK 战舰STM32F103开发板 实验14
 USMART调试实验-HAL库函数版
 技术支持：www.openedv.com
 淘宝店铺： http://eboard.taobao.com
 关注微信公众平台微信号："正点原子"，免费获取STM32资料。
 广州市星翼电子科技有限公司
 作者：正点原子 @ALIENTEK
************************************************/

//LED状态设置函数
void led_set(u8 sta)
{
    LED1 = sta;
}
//函数参数调用测试函数
void test_fun(void(*ledset)(u8), u8 sta)
{
    ledset(sta);
}

int main(void)
{
    HAL_Init();                         //初始化HAL库
    Stm32_Clock_Init(RCC_PLL_MUL9);     //设置时钟,72M
    delay_init(72);                     //初始化延时函数
    uart_init(115200);                  //初始化串口
    LED_Init();                         //初始化LED
    LCD_Init();                         //初始化LCD FSMC接口
    usmart_dev.init(84);                //初始化USMART
    POINT_COLOR = RED;                  //画笔颜色：红色
    LCD_ShowString(30, 50, 200, 16, 16, "WarShip STM32 ^_^");
    LCD_ShowString(30, 70, 200, 16, 16, "USMART TEST");
    LCD_ShowString(30, 90, 200, 16, 16, "ATOM@ALIENTEK");
    LCD_ShowString(30, 110, 200, 16, 16, "2017/5/27");
    while(1)
    {
        LED0 = !LED0;
        delay_ms(500);
    }
}

