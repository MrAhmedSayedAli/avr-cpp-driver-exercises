/*
By : Ahmed Elsayed Abdulrahman Ali
Email : mrahmedsayedali@gmail.com
github : https://github.com/MrAhmedSayedAli
*/

#ifndef DIO_CPP_LCD_H
#define DIO_CPP_LCD_H
#include "dio/dio.h"


//TODO::USE PINS
#define LCD_DATA_PORT DIO::Port::A

namespace HAL {



    class Lcd {
    public:
        Lcd(DIO::Channel RS,DIO::Channel RW,DIO::Channel E,DIO::Channel LCD_D4,DIO::Channel LCD_D5,DIO::Channel LCD_D6,DIO::Channel LCD_D7);
        void setString(const char *string);
        void setChar(uint8 data);
        void setPos(uint8 line,uint8 pos);
        void setCharPos(uint8 line,uint8 pos,uint8 data);
        void setCustomChar(uint8 loc,uint8 *data);
    private:
        //Functions
        void cmd(uint8 command);
        void cmd4Bit(uint8 command);

        //
        DIO::Channel PIN_RS;
        DIO::Channel PIN_RW;
        DIO::Channel PIN_E;

        DIO::Channel PIN_LCD_D4;
        DIO::Channel PIN_LCD_D5;
        DIO::Channel PIN_LCD_D6;
        DIO::Channel PIN_LCD_D7;

        DIO::Dio dio;
    };

} // HAL

#endif //DIO_CPP_LCD_H
