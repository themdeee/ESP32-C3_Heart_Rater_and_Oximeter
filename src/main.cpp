#include "main.h"

void setup()
{
	Wire.begin(7,6);
	Serial.begin(115200);

	while (false == max30102.begin())
	{
		Serial.println("init fail!");
		delay(1000);
	}
	Serial.println("init success!");
	Serial.println("start measuring...");
	max30102.sensorStartCollect();

	lcd.init(240, 240);
	lcd.setRotation(0);
	lcd.fillScreen(background_Color);
	
	lcd_brightness(100);

	lcd_show_chinese_sentence(20, 15, "心率", font_Color);

	lcd_show_chinese_character(120, 65, "次", font_Color);
	lcd_show_punctuation(160, 65, "/", font_Color);
	lcd_show_chinese_character(180, 65, "分", font_Color);

	lcd_show_chinese_sentence(20, 135, "血氧饱和度", font_Color);

	lcd_show_punctuation(200, 185, "%", font_Color);
}

void loop()
{
	max30102.getHeartbeatSPO2();
	heart_rate = max30102._sHeartbeatSPO2.Heartbeat;
	spo2 = max30102._sHeartbeatSPO2.SPO2;

	Serial.print("SPO2 is : ");
	Serial.print(heart_rate);
	Serial.println("%");
	Serial.print("heart rate is : ");
	Serial.print(spo2);
	Serial.println("Times/min");
	Serial.print("Temperature value of the board is : ");
	Serial.print(max30102.getTemperature_C());
	Serial.println(" ℃");
	
	if (heart_rate > 0)
	{
		sprintf(heart_rate_100, "%d", heart_rate / 100);
		sprintf(heart_rate_10, "%d", heart_rate / 10 % 10);
		sprintf(heart_rate_1, "%d", heart_rate % 10);

		if (heart_rate / 100 > 0)
		{
			lcd_show_num(40, 65, heart_rate_100, font_Color);
			lcd_show_num(65, 65, heart_rate_10, font_Color);
			lcd_show_num(90, 65, heart_rate_1, font_Color);
		}
		else
		{
			lcd.fillRect(40, 65, 20, 40, background_Color);
			
			if (heart_rate / 10 % 10 > 0)
			{
				lcd_show_num(65, 65, heart_rate_10, font_Color);
				lcd_show_num(90, 65, heart_rate_1, font_Color);
			}
			else
			{
				lcd.fillRect(65, 65, 20, 40, background_Color);

				lcd_show_num(90, 65, heart_rate_1, font_Color);
			}
		}
	}
	else
	{
		lcd.fillRect(40, 65, 70, 40, background_Color);
	}

	if (spo2 > 0)
	{
		sprintf(spo2_100, "%d", spo2 / 100);
		sprintf(spo2_10, "%d", spo2 / 10 % 10);
		sprintf(spo2_1, "%d", spo2 % 10);
		
		if (spo2 / 100 > 0)
		{
			lcd_show_num(120, 185, spo2_100, font_Color);
			lcd_show_num(145, 185, spo2_10, font_Color);
			lcd_show_num(170, 185, spo2_1, font_Color);
		}
		else
		{
			lcd.fillRect(120, 185, 20, 40, background_Color);
			
			if (spo2 / 10 % 10 > 0)
			{
				lcd_show_num(145, 185, spo2_10, font_Color);
				lcd_show_num(170, 185, spo2_1, font_Color);
			}
			else
			{
				lcd.fillRect(145, 185, 20, 40, background_Color);

				lcd_show_num(170, 185, spo2_1, font_Color);
			}
		}
	}
	else
	{
		lcd.fillRect(120, 185, 70, 40, background_Color);
	}

	heart_rate, spo2 = 0;

	// The sensor updates the data every 4 seconds
	// 3500 ms delay
	for (int i = 100; i > 30; i--)
	{
		lcd_brightness(i);
		delay(25);
	}
	for (int i = 30; i < 100; i++)
	{
		lcd_brightness(i);
		delay(25);
	}
}
