#ifndef LED_FUNTION
#define LED_FUNTION

#include <Arduino.h>

enum LED_COLOR
{
    RED = 0,    // 红色
    GREEN,      // 绿色
    BLUE,       // 蓝色
    PINK,       // 粉色
    PURPLE,     // 紫色
    YELLOW,     // 黄色
    ORANGE,     // 橙色
    WHITE,      // 白色
    CYAN,       // 青色
    MAGENTA,    // 洋红色
    LIME,       // 酸橙色
    TEAL,       // 鸭绿色
    GOLD,       // 金色
    SILVER,     // 银色
    TURQUOISE,  // 绿宝石色
};

class LEDs
{
public:
    LEDs()
    {
        ledcSetup(R_Channel,5000,8);
        ledcAttachPin(R_Pin,R_Channel);
        
        ledcSetup(G_Channel,5000,8);
        ledcAttachPin(G_Pin,G_Channel);

        ledcSetup(B_Channel,5000,8);
        ledcAttachPin(B_Pin,B_Channel);
        ledcWrite(R_Channel,255);
        ledcWrite(G_Channel,255);
        ledcWrite(B_Channel,255);
    }

    void LED_Work(uint8_t Color)
    {
        uint8_t Temp[3] = {0};
        switch(Color)
        {
            case RED:       Temp[0] = 255;Temp[1] = 0;Temp[2] = 0; break;
            case GREEN:     Temp[0] = 0;Temp[1] = 255;Temp[2] = 0; break;
            case BLUE:      Temp[0] = 0;Temp[1] = 0;Temp[2] = 255; break;
            case PINK:      Temp[0] = 255; Temp[1] = 192; Temp[2] = 203; break;
            case PURPLE:    Temp[0] = 128; Temp[1] = 0; Temp[2] = 128; break;
            case YELLOW:    Temp[0] = 255; Temp[1] = 255; Temp[2] = 0; break;
            case ORANGE:    Temp[0] = 255; Temp[1] = 165; Temp[2] = 0; break;
            case WHITE:     Temp[0] = 255; Temp[1] = 255; Temp[2] = 255; break;
            case CYAN:      Temp[0] = 0; Temp[1] = 255; Temp[2] = 255; break;
            case MAGENTA:   Temp[0] = 255; Temp[1] = 0; Temp[2] = 255; break;
            case LIME:      Temp[0] = 0; Temp[1] = 255; Temp[2] = 0; break;
            case TEAL:      Temp[0] = 0; Temp[1] = 128; Temp[2] = 128; break;
            case GOLD:      Temp[0] = 255; Temp[1] = 215; Temp[2] = 0; break;
            case SILVER:    Temp[0] = 192; Temp[1] = 192; Temp[2] = 192; break;
            case TURQUOISE: Temp[0] = 64; Temp[1] = 224; Temp[2] = 208; break;
            default:Temp[0] = 255; Temp[1] = 192; Temp[2] = 203; break;
        }
        Set_Led_Light(Temp[0],Temp[1],Temp[2]);
    }
    void LED_Work(uint8_t Color,float Lightness)
    {
        uint8_t Temp[3] = {0};
        switch(Color)
        {
            case RED:       Temp[0] = Lightness*255;Temp[1] = 0;Temp[2] = 0; break;
            case GREEN:     Temp[0] = 0;Temp[1] = Lightness*255;Temp[2] = 0; break;
            case BLUE:      Temp[0] = 0;Temp[1] = 0;Temp[2] = Lightness*255; break;
            case PINK:      Temp[0] = Lightness*255; Temp[1] = Lightness*192; Temp[2] = Lightness*203; break;
            case PURPLE:    Temp[0] = Lightness*128; Temp[1] = 0; Temp[2] = Lightness*128; break;
            case YELLOW:    Temp[0] = Lightness*255; Temp[1] = Lightness*255; Temp[2] = 0; break;
            case ORANGE:    Temp[0] = Lightness*255; Temp[1] = Lightness*44; Temp[2] = 0; break;
            case WHITE:     Temp[0] = Lightness*255; Temp[1] = Lightness*255; Temp[2] = Lightness*255; break;
            case CYAN:      Temp[0] = 0; Temp[1] = Lightness*255; Temp[2] = Lightness*255; break;
            case MAGENTA:   Temp[0] = Lightness*255; Temp[1] = 0; Temp[2] = Lightness*255; break;
            case LIME:      Temp[0] = 0; Temp[1] = Lightness*255; Temp[2] = 0; break;
            case TEAL:      Temp[0] = 0; Temp[1] = Lightness*128; Temp[2] = Lightness*128; break;
            case GOLD:      Temp[0] = Lightness*255; Temp[1] = Lightness*215; Temp[2] = 0; break;
            case SILVER:    Temp[0] = Lightness*192; Temp[1] = Lightness*192; Temp[2] = Lightness*192; break;
            case TURQUOISE: Temp[0] = Lightness*64; Temp[1] = Lightness*224; Temp[2] = Lightness*208; break;
            default:Temp[0] = Lightness*255; Temp[1] = Lightness*192; Temp[2] = Lightness*203; break;
        }
        Set_Led_Light(Temp[0],Temp[1],Temp[2]);
    }



private:
    uint8_t R_Channel = 0;
    uint8_t G_Channel = 1;
    uint8_t B_Channel = 2;
    uint8_t R_Pin   = 6;
    uint8_t G_Pin = 4;
    uint8_t B_Pin  = 5;
    
    void Set_Led_Light(uint8_t R,uint8_t G,uint8_t B)
    {
        ledcWrite(R_Channel,255 - R);
        ledcWrite(G_Channel,255 - G);
        ledcWrite(B_Channel,255 - B);
    }

};
#endif