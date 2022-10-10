/*
By : Ahmed Elsayed Abdulrahman Ali
Email : mrahmedsayedali@gmail.com
github : https://github.com/MrAhmedSayedAli
*/

#include "lcd.h"
#include "util/delay.h"
namespace HAL {
    Lcd::Lcd(DIO::Channel RS, DIO::Channel RW, DIO::Channel E, DIO::Channel LCD_D4, DIO::Channel LCD_D5, DIO::Channel LCD_D6, DIO::Channel LCD_D7) {

        PIN_RS = RS;
        PIN_RW = RW;
        PIN_E = E;

        PIN_LCD_D4 = LCD_D4;
        PIN_LCD_D5 = LCD_D5;
        PIN_LCD_D6 = LCD_D6;
        PIN_LCD_D7 = LCD_D7;

        dio.writeDirection(PIN_RS, DIO::Direction::OUTPUT);
        dio.writeDirection(PIN_RW, DIO::Direction::OUTPUT);
        dio.writeDirection(PIN_E, DIO::Direction::OUTPUT);
        dio.writeDirection(PIN_LCD_D4, DIO::Direction::OUTPUT);
        dio.writeDirection(PIN_LCD_D5, DIO::Direction::OUTPUT);
        dio.writeDirection(PIN_LCD_D6, DIO::Direction::OUTPUT);
        dio.writeDirection(PIN_LCD_D7, DIO::Direction::OUTPUT);


        //INIT
        dio.writeChannel(PIN_RW,STD_LevelType::LOW);
        dio.writeChannel(PIN_E,STD_LevelType::HIGH);
        _delay_ms(20);

        cmd(0x33);
        _delay_us(100);
        cmd(0x32);

        cmd(0x28);//Set Function 4-Bit & 2Line & 5*8 Dots
        cmd(0x06);//Entry Mode move to right and no shift
        cmd(0x0C);//Display on & Cursor off and no blinking
        cmd(0x01);//Clear LCD

    }

    void Lcd::cmd4Bit(uint8 command) {

        STD_LevelType p7 = STD_LevelType::LOW;
        STD_LevelType p6 = STD_LevelType::LOW;
        STD_LevelType p5 = STD_LevelType::LOW;
        STD_LevelType p4 = STD_LevelType::LOW;

        if((command & 8))
            p7 = STD_LevelType::HIGH;

        if((command & 4))
            p6 = STD_LevelType::HIGH;

        if((command & 2))
            p5 = STD_LevelType::HIGH;

        if((command & 1))
            p4 = STD_LevelType::HIGH;

        dio.writeChannel(PIN_LCD_D7, p7);
        dio.writeChannel(PIN_LCD_D6, p6);
        dio.writeChannel(PIN_LCD_D5, p5);
        dio.writeChannel(PIN_LCD_D4, p4);

    }

    void Lcd::cmd(uint8 command) {

        uint8 portValue = 0;

        dio.writeChannel(PIN_RS,STD_LevelType::LOW);

        portValue = dio.readPort(LCD_DATA_PORT);
        portValue = (portValue & 0x0F) | (command & 0xF0);

        dio.writePort(LCD_DATA_PORT,portValue);
        dio.writeChannel(PIN_E,STD_LevelType::LOW);
        _delay_ms(100);
        dio.writeChannel(PIN_E,STD_LevelType::HIGH);

        _delay_ms(5);

        portValue = dio.readPort(LCD_DATA_PORT);
        portValue = (portValue & 0x0F) | (command << 4);

        dio.writePort(LCD_DATA_PORT,portValue);
        dio.writeChannel(PIN_E,STD_LevelType::LOW);
        _delay_ms(100);
        dio.writeChannel(PIN_E,STD_LevelType::HIGH);
        _delay_ms(2);

//        dio.writeChannel(PIN_RS, STD_LevelType::LOW);
//
//        cmd4Bit(command);
//
//        dio.writeChannel(PIN_E, STD_LevelType::LOW);
//        _delay_ms(100);
//        dio.writeChannel(PIN_E, STD_LevelType::HIGH);
//        _delay_ms(5);
//
//        cmd4Bit((command << 4));
//
//        dio.writeChannel(PIN_E, STD_LevelType::LOW);
//        _delay_ms(100);
//        dio.writeChannel(PIN_E, STD_LevelType::HIGH);
//        _delay_ms(2);

    }

    void Lcd::setString(char *string) {
        uint8 i = 0;
        while(string[i] != '\0' ) {
            setChar(string[i]);
            i++;
        }
    }

    void Lcd::setChar(uint8 data) {
        uint8 portValue = 0;

        dio.writeChannel(PIN_RS,STD_LevelType::HIGH);

        portValue = dio.readPort(LCD_DATA_PORT);
        portValue = (portValue & 0x0F) | (data & 0xF0);

        dio.writePort(LCD_DATA_PORT,portValue);
        dio.writeChannel(PIN_E,STD_LevelType::LOW);
        _delay_ms(100);
        dio.writeChannel(PIN_E,STD_LevelType::HIGH);

        _delay_ms(5);

        portValue = dio.readPort(LCD_DATA_PORT);
        portValue = (portValue & 0x0F) | (data << 4);

        dio.writePort(LCD_DATA_PORT,portValue);
        dio.writeChannel(PIN_E,STD_LevelType::LOW);
        _delay_ms(100);
        dio.writeChannel(PIN_E,STD_LevelType::HIGH);
        _delay_ms(2);
    }

    void Lcd::setPos(uint8 line, uint8 pos) {

        switch (line) {
            case 1:
                cmd((0x80 | (pos & 0x0F)));
                break;
            case 2:
                cmd((0xC0 | (pos & 0x0F)));
                break;
            default:
                return;
        }
    }

    void Lcd::setCharPos(uint8 line, uint8 pos, uint8 data) {
        setPos(line,pos);
        setChar(data);
    }

    void Lcd::setCustomChar(uint8 loc, uint8 *data) {
        uint8 i;
        if(loc < 8){
            cmd(0x40 + (loc*8));
            for ( i = 0; i < 8; i++) {
                setChar(data[i]);
            }
        }
    }
} // HAL