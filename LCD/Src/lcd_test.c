//
// Created by Peakors on 6/23/2023.
//
#include "lcd_test.h"

/*************************************************************************************************
*	函 数 名:	LCD_Test_Clear
*
*	函数功能:	清屏测试
*************************************************************************************************/
void LCD_Test_Clear(void) {
    uint8_t i = 0;            // 计数变量

    LCD_SetTextFont(&CH_Font24);            // 设置2424中文字体,ASCII字体对应为2412
    LCD_SetColor(LCD_BLACK);                // 设置画笔颜色

    for (i = 0; i < 8; i++) {
        switch (i)        // 切换背景色
        {
            case 0:
                LCD_SetBackColor(LIGHT_RED);
                break;
            case 1:
                LCD_SetBackColor(LIGHT_GREEN);
                break;
            case 2:
                LCD_SetBackColor(LIGHT_BLUE);
                break;
            case 3:
                LCD_SetBackColor(LIGHT_YELLOW);
                break;
            case 4:
                LCD_SetBackColor(LIGHT_CYAN);
                break;
            case 5:
                LCD_SetBackColor(LIGHT_GREY);
                break;
            case 6:
                LCD_SetBackColor(LIGHT_MAGENTA);
                break;
            case 7:
                LCD_SetBackColor(LCD_WHITE);
                break;
            default:
                break;
        }
        LCD_Clear();        // 清屏
        LCD_DisplayText(13, 70, "STM32H7 LCD Test");
        LCD_DisplayText(13, 106, "Resolution:240*240");
        LCD_DisplayText(13, 142, "Driver IC:ST7789");
        HAL_Delay(1000);    // 延时
    }
}

/*************************************************************************************************
*	函 数 名:	LCD_Test_Text
*
*	函数功能:	文本显示测试
*
*	说    明:	显示文本，包括各种字体大小的中文和ASCII字符
*************************************************************************************************/
void LCD_Test_Text(void) {
    LCD_SetBackColor(LCD_BLACK);            //	设置背景色
    LCD_Clear();                                // 清屏

    LCD_SetColor(LCD_WHITE);
    LCD_SetAsciiFont(&ASCII_Font32);
    LCD_DisplayString(0, 0, "!#$'()*+,-.0123");
    LCD_SetAsciiFont(&ASCII_Font24);
    LCD_DisplayString(0, 32, "!#$'()*+,-.012345678");
    LCD_SetAsciiFont(&ASCII_Font20);
    LCD_DisplayString(0, 56, "!#$'()*+,-.0123456789:;<");
    LCD_SetAsciiFont(&ASCII_Font16);
    LCD_DisplayString(0, 76, "!#$'()*+,-.0123456789:;<=>?@AB");
    LCD_SetAsciiFont(&ASCII_Font12);
    LCD_DisplayString(0, 92, "!#$'()*+,-.0123456789:;<=>?@ABCDEFGHIJKL");

    LCD_SetColor(LCD_CYAN);
    LCD_SetAsciiFont(&ASCII_Font12);
    LCD_DisplayString(0, 104, "!#&'()*+,-.0123456789:;<=>?@ABCDEFGHIJKL");
    LCD_SetAsciiFont(&ASCII_Font16);
    LCD_DisplayString(0, 116, "!#&'()*+,-.0123456789:;<=>?@AB");
    LCD_SetAsciiFont(&ASCII_Font20);
    LCD_DisplayString(0, 132, "!#&'()*+,-.0123456789:;<");
    LCD_SetAsciiFont(&ASCII_Font24);
    LCD_DisplayString(0, 152, "!#&'()*+,-.012345678");
    LCD_SetAsciiFont(&ASCII_Font32);
    LCD_DisplayString(0, 176, "!#&'()*+,-.0123");

    LCD_SetTextFont(&CH_Font24);            // 设置2424中文字体,ASCII字体对应为2412
    LCD_SetColor(LCD_YELLOW);                // 设置画笔，黄色
    LCD_DisplayText(0, 216, "ASCII character set");

    HAL_Delay(2000);    // 延时等待
    LCD_Clear();                                // 清屏

    LCD_SetTextFont(&CH_Font12);            // 设置1212中文字体,ASCII字体对应为1206
    LCD_SetColor(0X8AC6D1);                    // 设置画笔
    LCD_DisplayText(14, 10, "1212:FANKE");

    LCD_SetTextFont(&CH_Font16);            // 设置1616中文字体,ASCII字体对应为1608
    LCD_SetColor(0XC5E1A5);                    // 设置画笔
    LCD_DisplayText(14, 30, "1616:FANKE");

    LCD_SetTextFont(&CH_Font20);            // 设置2020中文字体,ASCII字体对应为2010
    LCD_SetColor(0XFFB549);                    // 设置画笔
    LCD_DisplayText(14, 60, "2020:FANKE");

    LCD_SetTextFont(&CH_Font24);            // 设置2424中文字体,ASCII字体对应为2412
    LCD_SetColor(0XFF585D);                    // 设置画笔
    LCD_DisplayText(14, 90, "2424:FANKE");

    LCD_SetTextFont(&CH_Font32);            // 设置3232中文字体,ASCII字体对应为3216
    LCD_SetColor(0xFFB6B9);                    // 设置画笔
    LCD_DisplayText(14, 130, "3232:FANKE");

    LCD_SetTextFont(&CH_Font24);            // 设置2424中文字体,ASCII字体对应为2412
    LCD_SetColor(LCD_WHITE);
    LCD_DisplayText(14, 180, "Chinese display");

    HAL_Delay(2000);    // 延时等待
}

/************************************************************************************************
*	函 数 名:	LCD_Test_Variable
*
*	函数功能:	变量显示，包括整数和小数
*************************************************************************************************/
void LCD_Test_Variable(void) {
    uint16_t i;                    // 计数变量
    int32_t a = 0;            // 定义整数变量，用于测试
    int32_t b = 0;            // 定义整数变量，用于测试
    int32_t c = 0;            // 定义整数变量，用于测试

    double p = 3.1415926;    // 定义浮点数变量，用于测试
    double f = -1234.1234;    // 定义浮点数变量，用于测试

    LCD_SetBackColor(LCD_BLACK);            //	设置背景色
    LCD_Clear();                                // 清屏

    LCD_SetTextFont(&CH_Font24);
    LCD_SetColor(LIGHT_CYAN);                    // 设置画笔，蓝绿色
    LCD_DisplayText(0, 10, "positive number:");
    LCD_DisplayText(0, 40, "negative number:");

    LCD_SetColor(LIGHT_YELLOW);                // 设置画笔，亮黄色
    LCD_DisplayText(0, 80, "fill in the blanks:");
    LCD_DisplayText(0, 110, "filling 0:");

    LCD_SetColor(LIGHT_RED);                    // 设置画笔	，亮红色
    LCD_DisplayText(0, 150, "positive decimal:");
    LCD_DisplayText(0, 180, "negative decimal:");

    for (i = 0; i < 100; i++) {
        LCD_SetColor(LIGHT_CYAN);                                // 设置画笔	，蓝绿色
        LCD_ShowNumMode(Fill_Space);                            // 多余位填充空格
        LCD_DisplayNumber(80, 10, b + i * 10, 4);                // 显示变量
        LCD_DisplayNumber(80, 40, c - i * 10, 4);                // 显示变量

        LCD_SetColor(LIGHT_YELLOW);                                // 设置画笔，亮黄色

        LCD_ShowNumMode(Fill_Space);                                // 多余位填充 空格
        LCD_DisplayNumber(130, 80, a + i * 150, 8);                // 显示变量

        LCD_ShowNumMode(Fill_Zero);                                // 多余位填充0
        LCD_DisplayNumber(130, 110, b + i * 150, 8);                // 显示变量

        LCD_SetColor(LIGHT_RED);                                    // 设置画笔，亮红色
        LCD_ShowNumMode(Fill_Space);                                // 多余位填充空格
        LCD_DisplayDecimals(100, 150, p + i * 0.1, 6, 3);        // 显示小数
        LCD_DisplayDecimals(100, 180, f + i * 0.01, 11, 4);        // 显示小数

        HAL_Delay(15);
    }
    HAL_Delay(2500);
}

/*************************************************************************************************
*	函 数 名:	LCD_Test_Color
*
*	函数功能:	颜色测
*************************************************************************************************/
void LCD_Test_Color(void) {
    uint16_t i;                    // 计数变量
    uint16_t y;
// 颜色测试>>>>>
    LCD_SetBackColor(LCD_BLACK); //设置背景色
    LCD_Clear(); //清屏，刷背景色

    LCD_SetTextFont(&CH_Font20);            // 设置字体
    LCD_SetColor(LCD_WHITE);                // 设置画笔颜色
    LCD_DisplayText(0, 0, "RGB Trichromatic:");

    //使用画线函数绘制三基色色条
    for (i = 0; i < 240; i++) {
        LCD_SetColor(LCD_RED - (i << 16));
        LCD_DrawLine_V(0 + i, 20, 10);
    }
    for (i = 0; i < 240; i++) {
        LCD_SetColor(LCD_GREEN - (i << 8));
        LCD_DrawLine_V(0 + i, 35, 10);
    }
    for (i = 0; i < 240; i++) {
        LCD_SetColor(LCD_BLUE - i);
        LCD_DrawLine_V(0 + i, 50, 10);
    }

    y = 70;
    LCD_SetColor(LIGHT_CYAN);
    LCD_FillRect(150, y + 5, 90, 10);
    LCD_DisplayString(0, y, "LIGHT_CYAN");
    LCD_SetColor(LIGHT_MAGENTA);
    LCD_FillRect(150, y + 20 * 1 + 5, 90, 10);
    LCD_DisplayString(0, y + 20 * 1, "LIGHT_MAGENTA");
    LCD_SetColor(LIGHT_YELLOW);
    LCD_FillRect(150, y + 20 * 2 + 5, 90, 10);
    LCD_DisplayString(0, y + 20 * 2, "LIGHT_YELLOW");
    LCD_SetColor(LIGHT_GREY);
    LCD_FillRect(150, y + 20 * 3 + 5, 90, 10);
    LCD_DisplayString(0, y + 20 * 3, "LIGHT_GREY");

    LCD_SetColor(DARK_CYAN);
    LCD_FillRect(150, y + 20 * 4 + 5, 90, 10);
    LCD_DisplayString(0, y + 20 * 4, "DARK_CYAN");
    LCD_SetColor(DARK_MAGENTA);
    LCD_FillRect(150, y + 20 * 5 + 5, 90, 10);
    LCD_DisplayString(0, y + 20 * 5, "DARK_MAGENTA");
    LCD_SetColor(DARK_YELLOW);
    LCD_FillRect(150, y + 20 * 6 + 5, 90, 10);
    LCD_DisplayString(0, y + 20 * 6, "DARK_YELLOW");
    LCD_SetColor(DARK_GREY);
    LCD_FillRect(150, y + 20 * 7 + 5, 90, 10);
    LCD_DisplayString(0, y + 20 * 7, "DARK_GREY");

    HAL_Delay(2000);
}

/*************************************************************************************************
*	函 数 名:	LCD_Test_Grahic
*
*	函数功能:	2D图形绘制
*************************************************************************************************/
void LCD_Test_Graphic(void) {
    LCD_SetBackColor(LCD_BLACK); //设置背景色
    LCD_Clear(); //清屏，刷背景色

    LCD_SetColor(LCD_WHITE);
    LCD_DrawRect(0, 0, 240, 240);            //绘制矩形

    LCD_SetColor(LCD_RED);
    LCD_FillCircle(140, 50, 30);        //填充圆形
    LCD_SetColor(LCD_GREEN);
    LCD_FillCircle(170, 50, 30);
    LCD_SetColor(LCD_BLUE);
    LCD_FillCircle(200, 50, 30);

    LCD_SetColor(LCD_YELLOW);
    LCD_DrawLine(26, 26, 113, 64);                //画直线
    LCD_DrawLine(35, 22, 106, 81);                //画直线
    LCD_DrawLine(45, 20, 93, 100);                //画直线
    LCD_DrawLine(52, 16, 69, 108);                //画直线
    LCD_DrawLine(62, 16, 44, 108);                //画直线

    LCD_SetColor(LIGHT_CYAN);
    LCD_DrawCircle(120, 170, 30);            //绘制圆形
    LCD_DrawCircle(120, 170, 20);

    LCD_SetColor(LIGHT_RED);
    LCD_DrawEllipse(120, 170, 90, 40);    //绘制椭圆
    LCD_DrawEllipse(120, 170, 70, 40);    //绘制椭圆
    LCD_SetColor(LIGHT_MAGENTA);
    LCD_DrawEllipse(120, 170, 100, 50);    //绘制椭圆
    LCD_DrawEllipse(120, 170, 110, 60);

    HAL_Delay(2000);
}

/*************************************************************************************************
*	函 数 名:	LCD_Test_Image
*
*	函数功能:	图片显示测试
*************************************************************************************************/
void LCD_Test_Image(void) {
    LCD_SetBackColor(LCD_BLACK);            //	设置背景色
    LCD_Clear();                                // 清屏

    LCD_SetColor(0xffF6E58D);
    LCD_DrawImage(19, 21, 83, 83, Image_Android_83x83);       // 显示图片

    LCD_SetColor(0xffDFF9FB);
    LCD_DrawImage(141, 21, 83, 83, Image_Message_83x83);    // 显示图片

    LCD_SetColor(0xff9DD3A8);
    LCD_DrawImage(19, 140, 83, 83, Image_Toys_83x83);        // 显示图片

    LCD_SetColor(0xffFF8753);
    LCD_DrawImage(141, 140, 83, 83, Image_Video_83x83);        // 显示图片

    HAL_Delay(2000);
}

/*************************************************************************************************
*	函 数 名:	LCD_Test_Direction
*
*	函数功能:	更换显示方向
*************************************************************************************************/
void LCD_Test_Direction(void) {
    for (int i = 0; i < 4; i++) {
        LCD_SetBackColor(LCD_BLACK);            //	设置背景色
        LCD_Clear();                                // 清屏
        LCD_SetTextFont(&CH_Font24);
        LCD_SetColor(0xffDFF9FB);
        switch (i)        // 切换背景色
        {
            case 0:
                LCD_SetDirection(Direction_V);
                LCD_DisplayText(20, 20, "Direction_V");
                break;

            case 1:
                LCD_SetDirection(Direction_H);
                LCD_DisplayText(20, 20, "Direction_H");
                break;

            case 2:
                LCD_SetDirection(Direction_V_Flip);
                LCD_DisplayText(20, 20, "Direction_V_Flip");
                break;
            case 3:
                LCD_SetDirection(Direction_H_Flip);
                LCD_DisplayText(20, 20, "Direction_H_Flip");
                break;

            default:
                break;
        }
        LCD_SetColor(0xffF6E58D);
        LCD_DrawImage(19, 80, 83, 83, Image_Android_83x83);       // 显示图片
        LCD_SetTextFont(&CH_Font32);
        LCD_SetColor(0xff9DD3A8);
        LCD_DisplayText(130, 90, "FANKE");
        LCD_DisplayText(130, 130, "technology");

        HAL_Delay(1000);    // 延时
    }
}