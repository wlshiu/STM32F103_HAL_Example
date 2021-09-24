#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "key.h"
#include "lcd.h"
#include "usmart.h"
#include "24cxx.h"
/************************************************
 ALIENTEK 战舰STM32F103开发板 实验23
 IIC实验-HAL库函数版
 技术支持：www.openedv.com
 淘宝店铺： http://eboard.taobao.com
 关注微信公众平台微信号："正点原子"，免费获取STM32资料。
 广州市星翼电子科技有限公司
 作者：正点原子 @ALIENTEK
************************************************/

//要写入到24c02的字符串数组
const u8 TEXT_Buffer[] = {"WarShipSTM32 IIC TEST"};
#define SIZE sizeof(TEXT_Buffer)

int main(void)
{
    u8 key;
    u16 i = 0;
    u8 datatemp[SIZE];

    HAL_Init();                         //初始化HAL库
    Stm32_Clock_Init(RCC_PLL_MUL9);     //设置时钟,72M
    delay_init(72);                     //初始化延时函数
    uart_init(115200);                  //初始化串口
    usmart_dev.init(84);                //初始化USMART
    LED_Init();                         //初始化LED
    KEY_Init();                         //初始化按键
    LCD_Init();                         //初始化LCD FSMC接口

    AT24CXX_Init();                     //初始化IIC
    POINT_COLOR = RED;
    LCD_ShowString(30, 50, 200, 16, 16, "WarShip STM32");
    LCD_ShowString(30, 70, 200, 16, 16, "IIC TEST");
    LCD_ShowString(30, 90, 200, 16, 16, "ATOM@ALIENTEK");
    LCD_ShowString(30, 110, 200, 16, 16, "2017/5/30");
    LCD_ShowString(30, 130, 200, 16, 16, "KEY1:Write  KEY0:Read"); //显示提示信息
    while(AT24CXX_Check())//检测不到24c02
    {
        LCD_ShowString(30, 150, 200, 16, 16, "24C02 Check Failed!");
        delay_ms(500);
        LCD_ShowString(30, 150, 200, 16, 16, "Please Check!      ");
        delay_ms(500);
        LED0 = !LED0; //DS0闪烁
    }
    LCD_ShowString(30, 150, 200, 16, 16, "24C02 Ready!");
    POINT_COLOR = BLUE; //设置字体为蓝色
    while(1)
    {
        key = KEY_Scan(0);
        if(key == KEY1_PRES) //KEY1按下,写入24C02
        {
            LCD_Fill(0, 170, 239, 319, WHITE); //清除半屏
            LCD_ShowString(30, 170, 200, 16, 16, "Start Write 24C02....");
            AT24CXX_Write(0, (u8 *)TEXT_Buffer, SIZE);
            LCD_ShowString(30, 170, 200, 16, 16, "24C02 Write Finished!"); //提示传送完成
        }
        if(key == KEY0_PRES) //KEY0按下,读取字符串并显示
        {
            LCD_ShowString(30, 170, 200, 16, 16, "Start Read 24C02.... ");
            AT24CXX_Read(0, datatemp, SIZE);
            LCD_ShowString(30, 170, 200, 16, 16, "The Data Readed Is:  "); //提示传送完成
            LCD_ShowString(30, 190, 200, 16, 16, datatemp); //显示读到的字符串
        }
        i++;
        delay_ms(10);
        if(i == 20)
        {
            LED0 = !LED0; //提示系统正在运行
            i = 0;
        }
    }
}

