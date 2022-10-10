/*
By : Ahmed Elsayed Abdulrahman Ali
Email : mrahmedsayedali@gmail.com
github : https://github.com/MrAhmedSayedAli
*/

#ifndef DIO_CPP_KEYPAD_H
#define DIO_CPP_KEYPAD_H
#include "dio/dio.h"
namespace HAL {

    class Keypad {
    public:
        Keypad(DIO::Channel rowZero,DIO::Channel rowOne,DIO::Channel rowTow,DIO::Channel rowThree,DIO::Channel colZero,DIO::Channel colOne,DIO::Channel colTow,DIO::Channel colThree);
        uint8 getKey();

    private:
        DIO::Channel keypadRow[4];
        DIO::Channel keypadCol[4];

        uint8 keypadChars[4][4];

        DIO::Dio dio;
    };

} // HAL

#endif //DIO_CPP_KEYPAD_H
