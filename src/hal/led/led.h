/*
By : Ahmed Elsayed Abdulrahman Ali
Email : mrahmedsayedali@gmail.com
github : https://github.com/MrAhmedSayedAli
*/

#ifndef DIO_TEST_LED_H
#define DIO_TEST_LED_H

#include "dio/dio.h"

namespace HAL {

    class Led {
    public:
        explicit Led(DIO::Channel ChannelID,STD_LevelType level = STD_LevelType::LOW);
        void on();
        void off();
        void toggle();

    private:
        DIO::Dio dio;
        DIO::Channel ChannelId;
    };

} // HAL

#endif //DIO_TEST_LED_H
