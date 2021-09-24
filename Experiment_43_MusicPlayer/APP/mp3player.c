#include "mp3player.h"
#include "vs10xx.h"
#include "delay.h"
#include "led.h"
#include "key.h"
#include "lcd.h"
#include "malloc.h"
#include "text.h"
#include "string.h"
#include "exfuns.h"
#include "ff.h"
#include "flac.h"
#include "usart.h"
//////////////////////////////////////////////////////////////////////////////////
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//ALIENTEK战舰STM32开发板V3
//MP3播放驱动 代码
//正点原子@ALIENTEK
//技术论坛:www.openedv.com
//创建日期:2017/6/2
//版本：V1.0
//版权所有，盗版必究。
//Copyright(C) 广州市星翼电子科技有限公司 2009-2019
//All rights reserved
//////////////////////////////////////////////////////////////////////////////////

//显示曲目索引
//index:当前索引
//total:总文件数
void mp3_index_show(u16 index, u16 total)
{
    //显示当前曲目的索引,及总曲目数
    LCD_ShowxNum(30 + 0, 230, index, 3, 16, 0X80); //索引
    LCD_ShowChar(30 + 24, 230, '/', 16, 0);
    LCD_ShowxNum(30 + 32, 230, total, 3, 16, 0X80); //总曲目
}
//显示当前音量
void mp3_vol_show(u8 vol)
{
    LCD_ShowString(30 + 110, 230, 200, 16, 16, "VOL:");
    LCD_ShowxNum(30 + 142, 230, vol, 2, 16, 0X80); //显示音量
}
u16 f_kbps = 0; //歌曲文件位率
//显示播放时间,比特率 信息
//lenth:歌曲总长度
void mp3_msg_show(u32 lenth)
{
    static u16 playtime = 0; //播放时间标记
    u16 time = 0; // 时间变量
    u16 temp = 0;
    if(f_kbps == 0xffff) //未更新过
    {
        playtime = 0;
        f_kbps = VS_Get_HeadInfo();     //获得比特率
    }
    time = VS_Get_DecodeTime();         //得到解码时间
    if(playtime == 0)playtime = time;
    else if((time != playtime) && (time != 0)) //1s时间到,更新显示数据
    {
        playtime = time;                //更新时间
        temp = VS_Get_HeadInfo();       //获得比特率
        if(temp != f_kbps)
        {
            f_kbps = temp;              //更新KBPS
        }
        //显示播放时间
        LCD_ShowxNum(30, 210, time / 60, 2, 16, 0X80); //分钟
        LCD_ShowChar(30 + 16, 210, ':', 16, 0);
        LCD_ShowxNum(30 + 24, 210, time % 60, 2, 16, 0X80); //秒钟
        LCD_ShowChar(30 + 40, 210, '/', 16, 0);
        //显示总时间
        if(f_kbps)time = (lenth / f_kbps) / 125; //得到秒钟数   (文件长度(字节)/(1000/8)/比特率=持续秒钟数
        else time = 0; //非法位率
        LCD_ShowxNum(30 + 48, 210, time / 60, 2, 16, 0X80); //分钟
        LCD_ShowChar(30 + 64, 210, ':', 16, 0);
        LCD_ShowxNum(30 + 72, 210, time % 60, 2, 16, 0X80); //秒钟
        //显示位率
        LCD_ShowxNum(30 + 110, 210, f_kbps, 3, 16, 0X80); //显示位率
        LCD_ShowString(30 + 134, 210, 200, 16, 16, "Kbps");
        LED0 = !LED0;   //DS0翻转
    }
}
//得到path路径下,目标文件的总个数
//path:路径
//返回值:总有效文件数
u16 mp3_get_tnum(u8 *path)
{
    u8 res;
    u16 rval = 0;
    DIR tdir;           //临时目录
    FILINFO *tfileinfo; //临时文件信息
    tfileinfo = (FILINFO *)mymalloc(SRAMIN, sizeof(FILINFO)); //申请内存
    res = f_opendir(&tdir, (const TCHAR *)path); //打开目录
    if(res == FR_OK && tfileinfo)
    {
        while(1)//查询总的有效文件数
        {
            res = f_readdir(&tdir, tfileinfo);              //读取目录下的一个文件
            if(res != FR_OK || tfileinfo->fname[0] == 0)break; //错误了/到末尾了,退出
            res = f_typetell((u8 *)tfileinfo->fname);
            if((res & 0XF0) == 0X40) //取高四位,看看是不是音乐文件
            {
                rval++;//有效文件数增加1
            }
        }
    }
    myfree(SRAMIN, tfileinfo); //释放内存
    return rval;
}

//播放音乐
void mp3_play(void)
{
    u8 res;
    DIR mp3dir;         //目录
    FILINFO *mp3fileinfo;//文件信息
    u8 *pname;          //带路径的文件名
    u16 totmp3num;      //音乐文件总数
    u16 curindex;       //图片当前索引
    u8 key;             //键值
    u16 temp;
    u16 *mp3indextbl;   //音乐索引表

    while(f_opendir(&mp3dir, "0:/MUSIC")) //打开图片文件夹
    {
        Show_Str(30, 190, 240, 16, "MUSIC文件夹错误!", 16, 0);
        delay_ms(200);
        LCD_Fill(30, 190, 240, 206, WHITE); //清除显示
        delay_ms(200);
    }
    totmp3num = mp3_get_tnum("0:/MUSIC"); //得到总有效文件数
    while(totmp3num == NULL) //音乐文件总数为0
    {
        Show_Str(30, 190, 240, 16, "没有音乐文件!", 16, 0);
        delay_ms(200);
        LCD_Fill(30, 190, 240, 146, WHITE); //清除显示
        delay_ms(200);
    }
    mp3fileinfo = (FILINFO *)mymalloc(SRAMIN, sizeof(FILINFO)); //申请内存
    pname = mymalloc(SRAMIN, _MAX_LFN * 2 + 1);             //为带路径的文件名分配内存
    mp3indextbl = mymalloc(SRAMIN, 2 * totmp3num);          //申请2*totmp3num个字节的内存,用于存放音乐文件索引
    while(!mp3fileinfo || !pname || !mp3indextbl)           //内存分配出错
    {
        Show_Str(30, 190, 240, 16, "内存分配失败!", 16, 0);
        delay_ms(200);
        LCD_Fill(30, 190, 240, 146, WHITE); //清除显示
        delay_ms(200);
    }
    VS_HD_Reset();
    VS_Soft_Reset();
    vsset.mvol = 220;                   //默认设置音量为220.
    mp3_vol_show((vsset.mvol - 100) / 5); //音量限制在:100~250,显示的时候,按照公式(vol-100)/5,显示,也就是0~30
    //记录索引
    res = f_opendir(&mp3dir, "0:/MUSIC"); //打开目录
    if(res == FR_OK)
    {
        curindex = 0; //当前索引为0
        while(1)//全部查询一遍
        {
            temp = mp3dir.dptr;                             //记录当前index
            res = f_readdir(&mp3dir, mp3fileinfo);          //读取目录下的一个文件
            if(res != FR_OK || mp3fileinfo->fname[0] == 0)break; //错误了/到末尾了,退出
            res = f_typetell((u8 *)mp3fileinfo->fname);
            if((res & 0XF0) == 0X40) //取高四位,看看是不是音乐文件
            {
                mp3indextbl[curindex] = temp; //记录索引
                curindex++;
            }
        }
    }
    curindex = 0;                                               //从0开始显示
    res = f_opendir(&mp3dir, (const TCHAR *)"0:/MUSIC");        //打开目录
    while(res == FR_OK) //打开成功
    {
        dir_sdi(&mp3dir, mp3indextbl[curindex]);                //改变当前目录索引
        res = f_readdir(&mp3dir, mp3fileinfo);                  //读取目录下的一个文件
        if(res != FR_OK || mp3fileinfo->fname[0] == 0)break;    //错误了/到末尾了,退出
        strcpy((char *)pname, "0:/MUSIC/");                     //复制路径(目录)
        strcat((char *)pname, (const char *)mp3fileinfo->fname); //将文件名接在后面
        LCD_Fill(30, 190, 240, 190 + 16, WHITE);                //清除之前的显示
        Show_Str(30, 190, 240 - 30, 16, (u8 *)mp3fileinfo->fname, 16, 0); //显示歌曲名字
        mp3_index_show(curindex + 1, totmp3num);
        key = mp3_play_song(pname);                             //播放这个MP3
        if(key == 2)    //上一曲
        {
            if(curindex)curindex--;
            else curindex = totmp3num - 1;
        }
        else if(key <= 1) //下一曲
        {
            curindex++;
            if(curindex >= totmp3num)curindex = 0; //到末尾的时候,自动从头开始
        }
        else break;     //产生了错误
    }
    myfree(SRAMIN, mp3fileinfo);        //释放内存
    myfree(SRAMIN, pname);              //释放内存
    myfree(SRAMIN, mp3indextbl);        //释放内存
}

//播放一曲指定的歌曲
//返回值:0,正常播放完成
//       1,下一曲
//       2,上一曲
//       0XFF,出现错误了
u8 mp3_play_song(u8 *pname)
{
    FIL *fmp3;
    u16 br;
    u8 res, rval;
    u8 *databuf;
    u16 i = 0;
    u8 key;

    rval = 0;
    fmp3 = (FIL *)mymalloc(SRAMIN, sizeof(FIL)); //申请内存
    databuf = (u8 *)mymalloc(SRAMIN, 4096); //开辟4096字节的内存区域
    if(databuf == NULL || fmp3 == NULL)rval = 0XFF ; //内存申请失败.
    if(rval == 0)
    {
        VS_Restart_Play();                      //重启播放
        VS_Set_All();                           //设置音量等信息
        VS_Reset_DecodeTime();                  //复位解码时间
        res = f_typetell(pname);                //得到文件后缀
        if(res == 0x4c) //如果是flac,加载patch
        {
            VS_Load_Patch((u16 *)vs1053b_patch, VS1053B_PATCHLEN);
        }
        res = f_open(fmp3, (const TCHAR *)pname, FA_READ); //打开文件
        if(res == 0) //打开成功.
        {
            VS_SPI_SpeedHigh(); //高速
            while(rval == 0)
            {
                res = f_read(fmp3, databuf, 4096, (UINT *)&br); //读出4096个字节
                i = 0;
                do//主播放循环
                {
                    if(VS_Send_MusicData(databuf + i) == 0) //给VS10XX发送音频数据
                    {
                        i += 32;
                    }
                    else
                    {
                        key = KEY_Scan(0);
                        switch(key)
                        {
                            case KEY0_PRES:
                                rval = 1;   //下一曲
                                break;
                            case KEY2_PRES:
                                rval = 2;   //上一曲
                                break;
                            case WKUP_PRES: //音量增加
                                if(vsset.mvol < 250)
                                {
                                    vsset.mvol += 5;
                                    VS_Set_Vol(vsset.mvol);
                                }
                                else vsset.mvol = 250;
                                mp3_vol_show((vsset.mvol - 100) / 5); //音量限制在:100~250,显示的时候,按照公式(vol-100)/5,显示,也就是0~30
                                break;
                            case KEY1_PRES: //音量减
                                if(vsset.mvol > 100)
                                {
                                    vsset.mvol -= 5;
                                    VS_Set_Vol(vsset.mvol);
                                }
                                else vsset.mvol = 100;
                                mp3_vol_show((vsset.mvol - 100) / 5); //音量限制在:100~250,显示的时候,按照公式(vol-100)/5,显示,也就是0~30
                                break;
                        }
                        mp3_msg_show(fmp3->obj.objsize);//显示信息
                    }
                }
                while(i < 4096); //循环发送4096个字节
                if(br != 4096 || res != 0)
                {
                    rval = 0;
                    break;//读完了.
                }
            }
            f_close(fmp3);
        }
        else rval = 0XFF; //出现错误
    }
    myfree(SRAMIN, databuf);
    myfree(SRAMIN, fmp3);
    return rval;
}




























