#ifndef DISP_T
#define DISP_T

#include <Arduino.h>
#include <U8g2lib.h>
#include "Data.hpp"
#include "WiFi.h"

#define U8X8_NO_HW_SPI


U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE, /* clock=*/ 6, /* data=*/ 7);
class Disp_t
{
public:
    Disp_t()
    {
        xTaskCreatePinnedToCore([](void*param)->void
                                {
                                    Disp_t *I = static_cast<Disp_t*>(param);
                                    I->Disp_Task();
                                },
                                "Disp_Task", 
                                60*1024, 
                                this, 
                                2, 
                                NULL, 
                                1);        
    }

    char* FtoC(float Input)
    {
        float Temp_Num = Input;
        snprintf(Temp_Data, sizeof(Temp_Data), "%f", Temp_Num);
        return Temp_Data;
    }
    void drawLogo(void)
    {
        u8g2.setFontMode(1);	// Transparent
        u8g2.setFontDirection(0);
        u8g2.setFont(u8g2_font_inb24_mf);
        u8g2.drawStr(30, 30, "CAR");
        
        u8g2.drawHLine(2, 35, 37);
        u8g2.drawHLine(3, 36, 37);
        u8g2.drawVLine(20, 32, 17);
        u8g2.drawVLine(21, 33, 17);
    }
    void drawURL(void)
    {
        u8g2.setFont(u8g2_font_7x13_tr);
        u8g2.drawStr(25,48,"github.com");
        u8g2.drawStr(30,61,"/mr_cheng/Car");
    }
    void drawFloat(uint8_t x , uint8_t y,float Num)
    {
        FtoC(Num);
        u8g2.drawStr(x,y,Temp_Data);
    }
    void showImuData(void)
    {

    }
    void Disp_Task(void)
    {
        
        u8g2.begin();
        for(uint32_t i = 0; i < 127 ; i++)
        {
            u8g2.clearBuffer();
            this->drawLogo();
            this->drawURL();
            u8g2.drawBox(0,63,i,1);
            u8g2.sendBuffer();
        }
        while(1)
        {
            
            u8g2.clearBuffer();
            drawFloat(0,10,Imu_Data.temp);
            switch(WiFi.status())
            {
                case 255 : u8g2.drawStr(0,20,"WL_NO_SHIELD");break;
                case 0   : u8g2.drawStr(0,20,"WL_IDLE_STATUS");break;
                case 1   : u8g2.drawStr(0,20,"WL_NO_SSID_AVAIL");break;
                case 2   : u8g2.drawStr(0,20,"WL_SCAN_COMPLETED");break;
                case 3   : u8g2.drawStr(0,20,"WL_CONNECTED");break;
                case 4   : u8g2.drawStr(0,20,"WL_CONNECT_FAILED");break;
                case 5   : u8g2.drawStr(0,20,"WL_CONNECTION_LOST");break;
                case 6   : u8g2.drawStr(0,20,"WL_DISCONNECTED");break;
            }

            switch()
            {
                
            }
            u8g2.sendBuffer();
            vTaskDelay(1);
        }
    }


    char Temp_Data[20];
    
};





























#endif