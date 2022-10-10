/*
By : Ahmed Elsayed Abdulrahman Ali
Email : mrahmedsayedali@gmail.com
github : https://github.com/MrAhmedSayedAli
*/



#ifndef DIO_TEST_TYPES_H
#define DIO_TEST_TYPES_H

namespace DIO {

    enum class Channel {
        A0 = 0,
        A1,
        A2,
        A3,
        A4,
        A5,
        A6,
        A7,

        B0,
        B1,
        B2,
        B3,
        B4,
        B5,
        B6,
        B7,

        C0,
        C1,
        C2,
        C3,
        C4,
        C5,
        C6,
        C7,

        D0,
        D1,
        D2,
        D3,
        D4,
        D5,
        D6,
        D7
    };

    enum class Port {
        A = 0,
        B,
        C,
        D
    };

    enum class Direction {
        INPUT = 0,
        OUTPUT
    };


} // DIO

#endif //DIO_TEST_TYPES_H

