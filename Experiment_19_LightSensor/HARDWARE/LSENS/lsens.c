#include "lsens.h"
#include "delay.h"
//////////////////////////////////////////////////////////////////////////////////
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//ALIENTEK STM32F103开发板
//LSENS(光敏传感器)驱动代码
//正点原子@ALIENTEK
//技术论坛:www.openedv.com
//创建日期:2017/5/29
//版本：V1.0
//版权所有，盗版必究。
//Copyright(C) 广州市星翼电子科技有限公司 2014-2024
//All rights reserved
//////////////////////////////////////////////////////////////////////////////////

//初始化光敏传感器
void Lsens_Init(void)
{
    GPIO_InitTypeDef GPIO_Initure;

    __HAL_RCC_GPIOF_CLK_ENABLE();           //开启GPIOF时钟

    GPIO_Initure.Pin = GPIO_PIN_8;          //PF8
    GPIO_Initure.Mode = GPIO_MODE_ANALOG;   //模拟
    GPIO_Initure.Pull = GPIO_NOPULL;        //不带上下拉
    HAL_GPIO_Init(GPIOF, &GPIO_Initure);

    ADC3_Init();                            //初始化ADC3
}
//读取Light Sens的值
//0~100:0,最暗;100,最亮
u8 Lsens_Get_Val(void)
{
    u32 temp_val = 0;
    u8 t;
    for(t = 0; t < LSENS_READ_TIMES; t++)
    {
        temp_val += Get_Adc3(ADC_CHANNEL_6); //读取ADC值,通道6
        delay_ms(5);
    }
    temp_val /= LSENS_READ_TIMES; //得到平均值
    if(temp_val > 4000)temp_val = 4000;
    return (u8)(100 - (temp_val / 40));
}












