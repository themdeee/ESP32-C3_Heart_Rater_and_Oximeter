#include "lcd.h"

Adafruit_ST7789 lcd = Adafruit_ST7789(LCD_CS, LCD_DC, LCD_SDA, LCD_SCL, LCD_RES);

/*
    屏幕亮度调节函数
    brightness_level：屏幕亮度数值
                      0~100之间的整数
*/
void lcd_brightness(uint8_t brightness_level)
{
    int freq = 5000;
    int channel = 0;
    int resolution = 10;

    ledcSetup(channel, freq, resolution);
    ledcAttachPin(LCD_BLK, channel);

    ledcWrite(channel, pow(2, resolution) * brightness_level / 100);
}

/*
    //
*/
void lcd_show_chinese_character(uint8_t x, uint8_t y, const char c[3], uint16_t foreground_color)
{
    uint8_t number = 14;    //总共要显示的字符个数

    for (int i = 0; i < number; i++)
    {
        if (CN_Font[i].index[0] == c[0] && CN_Font[i].index[1] == c[1] &&CN_Font[i].index[2] == c[2])
        {
            lcd.drawBitmap(x, y, CN_Font[i].data, CN_Font[i].width, CN_Font[i].height, foreground_color, background_Color);
        }
    }
}

/*
    //
*/
void lcd_show_chinese_sentence(uint8_t x, uint8_t y, const char str[], uint16_t foreground_color)
{
    uint8_t x_temp = x;

    for (int i = 0; i < strlen(str); i += 3)
    {
        lcd_show_chinese_character(x_temp, y, str + i, foreground_color);
        
        x_temp = x_temp + CN_Font[i].width;
    }
}

/*
    //
*/
void lcd_show_num(uint8_t x, uint8_t y, const char c[1], uint16_t foreground_color)
{
    uint8_t number = 10;    //总共要显示的字符个数

    for (int i = 0; i < number; i++)
    {
        if (NUM_Font[i].index[0] == c[0])
        {
            lcd.drawBitmap(x, y, NUM_Font[i].data, NUM_Font[i].width, NUM_Font[i].height, foreground_color, background_Color);
        }
    }
}

/*
    //
*/
void lcd_show_nums(uint8_t x, uint8_t y, const char str[], uint16_t foreground_color)
{
    uint8_t x_temp = x;

    for (int i = 0; i < strlen(str); i += 1)
    {
        lcd_show_num(x_temp, y, str + i, foreground_color);
        
        x_temp = x_temp + NUM_Font[i].width + 5;
    }
}

/*
    //
*/
void lcd_show_punctuation(uint8_t x, uint8_t y, const char c[1], uint16_t foreground_color)
{
    uint8_t number = 2;    //总共要显示的字符个数

    for (int i = 0; i < number; i++)
    {
        if (punctuation_Font[i].index[0] == c[0])
        {
            lcd.drawBitmap(x, y, punctuation_Font[i].data, punctuation_Font[i].width, punctuation_Font[i].height, foreground_color, background_Color);
        }
    }
}
