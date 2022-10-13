/*
By : Ahmed Elsayed Abdulrahman Ali
Email : mrahmedsayedali@gmail.com
github : https://github.com/MrAhmedSayedAli
*/



#include "dio/dio.h"

#include "led/led.h"
#include "buzzer/buzzer.h"
#include "lcd/lcd.h"
#include "keypad/keypad.h"

#include "util/delay.h"



//uint8 customChar[] = {
//        0x00, 0x00, 0x0C, 0x12, 0x01, 0x3E, 0x00, 0x1C
//};

int main() {




    HAL::Led led1(DIO::Channel::C2,STD_LevelType::HIGH);

//    HAL::Led led2(DIO::Channel::C7);
//    HAL::Led led3(DIO::Channel::D3);
//
//    HAL::Buzzer buzzer(DIO::Channel::A3);

    HAL::Led led01(DIO::Channel::C6);
    HAL::Led led02(DIO::Channel::C7,STD_LevelType::HIGH);
/*
    HAL::Keypad keybad(
            DIO::Channel::D0,
            DIO::Channel::D1,
            DIO::Channel::D2,
            DIO::Channel::D3,

            DIO::Channel::D4,
            DIO::Channel::D5,
            DIO::Channel::D6,
            DIO::Channel::D7
    );
*/
    HAL::Lcd lcd(
            DIO::Channel::B1,
            DIO::Channel::B2,
            DIO::Channel::B3,
            DIO::Channel::A4,
            DIO::Channel::A5,
            DIO::Channel::A6,
            DIO::Channel::A7
    );


//    lcd.setCustomChar(0, customChar);
//    lcd.setPos(1, 1);
//    lcd.setChar(0);
//    lcd.setPos(1, 2);

    lcd.setChar('A'); //work
    lcd.setChar('H');
    lcd.setChar('M');
    lcd.setChar('E');
    lcd.setChar('D');

//    lcd.setString("Ahmed Elsayed"); //not work;
//    uint8 keypadVr = 0;
    while (1) {

        led01.toggle();
        led02.toggle();
        _delay_ms(100);

//        keypadVr = keybad.getKey();
//
//        if (keypadVr != 0) {
//            lcd.setChar(keypadVr);
//        }
/*
        led1.on();
        led2.off();
        led3.off();
        //buzzer.tone(1000,200);
        _delay_ms(100);

        led1.off();
        led2.on();
        led3.off();
        //buzzer.tone(2000,200);
        _delay_ms(100);

        led1.off();
        led2.off();
        led3.on();
        //buzzer.tone(3000,200);
        _delay_ms(100);
*/
    }

}