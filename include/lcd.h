#include "Adafruit_ST7789.h"
#include "font.h"

#define LCD_SCL     0
#define LCD_SDA     1
#define LCD_RES     2
#define LCD_DC      3
#define LCD_CS      4
#define LCD_BLK     5

#define CN_Font             CN_Font_40
#define NUM_Font            NUM_Font_40
#define punctuation_Font    PUNCTUATION_Font_40

#define background_Color    ST77XX_BLACK
#define font_Color          ST77XX_WHITE

extern Adafruit_ST7789 lcd;

void lcd_brightness(uint8_t brightness_level);
void lcd_show_chinese_character(uint8_t x, uint8_t y, const char c[3], uint16_t color);
void lcd_show_chinese_sentence(uint8_t x, uint8_t y, const char str[], uint16_t color);
void lcd_show_num(uint8_t x, uint8_t y, const char c[1], uint16_t color);
void lcd_show_nums(uint8_t x, uint8_t y, const char str[], uint16_t color);
void lcd_show_punctuation(uint8_t x, uint8_t y, const char c[1], uint16_t color);
