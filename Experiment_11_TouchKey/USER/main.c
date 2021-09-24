#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "key.h"
#include "tpad.h"
/************************************************
 ALIENTEK 战舰STM32F103开发板 实验11
 输入捕获实验-HAL库函数版
 技术支持：www.openedv.com
 淘宝店铺： http://eboard.taobao.com
 关注微信公众平台微信号："正点原子"，免费获取STM32资料。
 广州市星翼电子科技有限公司
 作者：正点原子 @ALIENTEK
************************************************/

int main(void)
{
    u8 t = 0;

    HAL_Init();                         //初始化HAL库
    Stm32_Clock_Init(RCC_PLL_MUL9);     //设置时钟,72M
    delay_init(72);                     //初始化延时函数
    uart_init(115200);                  //初始化串口
    LED_Init();                         //初始化LED
    TPAD_Init(6);                       //初始化触摸按键

    while(1)
    {
        if(TPAD_Scan(0))                //成功捕获到了一次上升沿(此函数执行时间至少15ms)
        {
            LED1 = !LED1;               //LED1取反
        }
        t++;
        if(t == 15)
        {
            t = 0;
            LED0 = !LED0;               //LED0取反,提示程序正在运行
        }
        delay_ms(10);
    }
}

