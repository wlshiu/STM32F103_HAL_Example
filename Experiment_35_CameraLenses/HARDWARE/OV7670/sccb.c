#include "sys.h"
#include "sccb.h"
#include "delay.h"
//////////////////////////////////////////////////////////////////////////////////
//本程序参考自网友guanfu_wang代码。
//ALIENTEK战舰STM32开发板V3
//SCCB 驱动代码
//正点原子@ALIENTEK
//技术论坛:www.openedv.com
//创建日期:2017/6/1
//版本：V1.0
//////////////////////////////////////////////////////////////////////////////////

//初始化SCCB接口
//CHECK OK
void SCCB_Init(void)
{
    GPIO_InitTypeDef GPIO_Initure;

    __HAL_RCC_GPIOD_CLK_ENABLE();               //开启GPIOD时钟
    __HAL_RCC_GPIOG_CLK_ENABLE();               //开启GPIOG时钟

    GPIO_Initure.Pin = GPIO_PIN_13;             //PG13
    GPIO_Initure.Mode = GPIO_MODE_INPUT;        //输入
    GPIO_Initure.Pull = GPIO_PULLUP;            //上拉
    GPIO_Initure.Speed = GPIO_SPEED_HIGH;       //高速
    HAL_GPIO_Init(GPIOG, &GPIO_Initure);

    GPIO_Initure.Pin = GPIO_PIN_3;              //PD3
    GPIO_Initure.Mode = GPIO_MODE_OUTPUT_PP;    //推挽输出
    HAL_GPIO_Init(GPIOD, &GPIO_Initure);

    HAL_GPIO_WritePin(GPIOG, GPIO_PIN_13, GPIO_PIN_SET); //PG13输出高电平
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_3, GPIO_PIN_SET); //PD3输出高电平

    SCCB_SDA_OUT();
}

//SCCB起始信号
//当时钟为高的时候,数据线的高到低,为SCCB起始信号
//在激活状态下,SDA和SCL均为低电平
void SCCB_Start(void)
{
    SCCB_SDA = 1;   //数据线高电平
    SCCB_SCL = 1;   //在时钟线高的时候数据线由高至低
    delay_us(50);
    SCCB_SDA = 0;
    delay_us(50);
    SCCB_SCL = 0;   //数据线恢复低电平，单操作函数必要
}

//SCCB停止信号
//当时钟为高的时候,数据线的低到高,为SCCB停止信号
//空闲状况下,SDA,SCL均为高电平
void SCCB_Stop(void)
{
    SCCB_SDA = 0;
    delay_us(50);
    SCCB_SCL = 1;
    delay_us(50);
    SCCB_SDA = 1;
    delay_us(50);
}
//产生NA信号
void SCCB_No_Ack(void)
{
    delay_us(50);
    SCCB_SDA = 1;
    SCCB_SCL = 1;
    delay_us(50);
    SCCB_SCL = 0;
    delay_us(50);
    SCCB_SDA = 0;
    delay_us(50);
}
//SCCB,写入一个字节
//返回值:0,成功;1,失败.
u8 SCCB_WR_Byte(u8 dat)
{
    u8 j, res;
    for(j = 0; j < 8; j++) //循环8次发送数据
    {
        if(dat & 0x80)SCCB_SDA = 1;
        else SCCB_SDA = 0;
        dat <<= 1;
        delay_us(50);
        SCCB_SCL = 1;
        delay_us(50);
        SCCB_SCL = 0;
    }
    SCCB_SDA_IN();      //设置SDA为输入
    delay_us(50);
    SCCB_SCL = 1;       //接收第九位,以判断是否发送成功
    delay_us(50);
    if(SCCB_READ_SDA)res = 1; //SDA=1发送失败，返回1
    else res = 0;       //SDA=0发送成功，返回0
    SCCB_SCL = 0;
    SCCB_SDA_OUT();     //设置SDA为输出
    return res;
}
//SCCB 读取一个字节
//在SCL的上升沿,数据锁存
//返回值:读到的数据
u8 SCCB_RD_Byte(void)
{
    u8 temp = 0, j;
    SCCB_SDA_IN();      //设置SDA为输入
    for(j = 8; j > 0; j--) //循环8次接收数据
    {
        delay_us(50);
        SCCB_SCL = 1;
        temp = temp << 1;
        if(SCCB_READ_SDA)temp++;
        delay_us(50);
        SCCB_SCL = 0;
    }
    SCCB_SDA_OUT();     //设置SDA为输出
    return temp;
}
//写寄存器
//返回值:0,成功;1,失败.
u8 SCCB_WR_Reg(u8 reg, u8 data)
{
    u8 res = 0;
    SCCB_Start();                   //启动SCCB传输
    if(SCCB_WR_Byte(SCCB_ID))res = 1; //写器件ID
    delay_us(100);
    if(SCCB_WR_Byte(reg))res = 1;   //写寄存器地址
    delay_us(100);
    if(SCCB_WR_Byte(data))res = 1;  //写数据
    SCCB_Stop();
    return  res;
}
//读寄存器
//返回值:读到的寄存器值
u8 SCCB_RD_Reg(u8 reg)
{
    u8 val = 0;
    SCCB_Start();               //启动SCCB传输
    SCCB_WR_Byte(SCCB_ID);      //写器件ID
    delay_us(100);
    SCCB_WR_Byte(reg);          //写寄存器地址
    delay_us(100);
    SCCB_Stop();
    delay_us(100);
    //设置寄存器地址后，才是读
    SCCB_Start();
    SCCB_WR_Byte(SCCB_ID | 0X01); //发送读命令
    delay_us(100);
    val = SCCB_RD_Byte();       //读取数据
    SCCB_No_Ack();
    SCCB_Stop();
    return val;
}















