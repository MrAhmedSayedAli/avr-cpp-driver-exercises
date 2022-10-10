/*
By : Ahmed Elsayed Abdulrahman Ali
Email : mrahmedsayedali@gmail.com
github : https://github.com/MrAhmedSayedAli
*/

#include "led.h"

namespace HAL {
    Led::Led(DIO::Channel ChannelID,STD_LevelType level) {
        ChannelId = ChannelID;

        dio.writeDirection(ChannelId,DIO::Direction::OUTPUT);
        dio.writeChannel(ChannelId,level);

    }
    //----------------------------------------------->
    void Led::on() {
        dio.writeChannel(ChannelId,STD_LevelType::HIGH);
    }
    //----------------------------------------------->
    void Led::off() {
    dio.writeChannel(ChannelId,STD_LevelType::LOW);
    }
    //----------------------------------------------->
    void Led::toggle() {
        if (dio.readChannel(ChannelId) == STD_LevelType::HIGH){
            off();
        }else{
            on();
        }
    }
    //----------------------------------------------->

} // HAL