#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "lcd.h"
/************************************************
 ALIENTEK 战舰STM32F103开发板 实验13
 LCD显示实验-HAL库函数版
 技术支持：www.openedv.com
 淘宝店铺： http://eboard.taobao.com
 关注微信公众平台微信号："正点原子"，免费获取STM32资料。
 广州市星翼电子科技有限公司
 作者：正点原子 @ALIENTEK
************************************************/

int main(void)
{
    u8 x = 0;
    u8 lcd_id[12];                      //存放LCD ID字符串

    HAL_Init();                         //初始化HAL库
    Stm32_Clock_Init(RCC_PLL_MUL9);     //设置时钟,72M
    delay_init(72);                     //初始化延时函数
    uart_init(115200);                  //初始化串口
    LED_Init();                         //初始化LED

    LCD_Init();                         //初始化LCD FSMC接口
    POINT_COLOR = RED;                  //画笔颜色：红色
    sprintf((char *)lcd_id, "LCD ID:%04X", lcddev.id); //将LCD ID打印到lcd_id数组。
    while(1)
    {
        switch(x)
        {
            case 0:
                LCD_Clear(WHITE);
                break;
            case 1:
                LCD_Clear(BLACK);
                break;
            case 2:
                LCD_Clear(BLUE);
                break;
            case 3:
                LCD_Clear(RED);
                break;
            case 4:
                LCD_Clear(MAGENTA);
                break;
            case 5:
                LCD_Clear(GREEN);
                break;
            case 6:
                LCD_Clear(CYAN);
                break;
            case 7:
                LCD_Clear(YELLOW);
                break;
            case 8:
                LCD_Clear(BRRED);
                break;
            case 9:
                LCD_Clear(GRAY);
                break;
            case 10:
                LCD_Clear(LGRAY);
                break;
            case 11:
                LCD_Clear(BROWN);
                break;
        }
        POINT_COLOR = RED;
        LCD_ShowString(30, 40, 210, 24, 24, "WarShip STM32 ^_^");
        LCD_ShowString(30, 70, 200, 16, 16, "TFTLCD TEST");
        LCD_ShowString(30, 90, 200, 16, 16, "ATOM@ALIENTEK");
        LCD_ShowString(30, 110, 200, 16, 16, lcd_id);   //显示LCD ID
        LCD_ShowString(30, 130, 200, 12, 12, "2017/5/27");
        x++;
        if(x == 12)x = 0;
        LED0 = !LED0;
        delay_ms(1000);
    }
}

