//
// Created by Peakors on 6/23/2023.
//

#ifndef STM32H730IBK6Q_TEST_LCD_TEST_H
#define STM32H730IBK6Q_TEST_LCD_TEST_H

#include "lcd_spi_154.h"

// LCD测试函数，函数定义在底部
void LCD_Test_Clear(void);            // 清屏测试
void LCD_Test_Text(void);               // 文本测试
void LCD_Test_Variable(void);       // 变量显示，包括整数和小数
void LCD_Test_Color(void);            // 矩形填充测试
void LCD_Test_Graphic(void);           // 2D图形绘制
void LCD_Test_Image(void);            // 图片显示
void LCD_Test_Direction(void);       // 更换显示方向

#endif //STM32H730IBK6Q_TEST_LCD_TEST_H
