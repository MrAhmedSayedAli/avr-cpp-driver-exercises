/*
By : Ahmed Elsayed Abdulrahman Ali
Email : mrahmedsayedali@gmail.com
github : https://github.com/MrAhmedSayedAli
*/

#ifndef DIO_TEST_DIO_H
#define DIO_TEST_DIO_H

#define PIN_COUNT 32

#include "BitMath.h"
#include "STD_Types.h"
#include "hw.h"
#include "types.h"

namespace DIO {

    typedef struct
    {
        Direction PinDir;
        STD_LevelType Level;

    }PinConfig;

    class Dio {
    public:
        void init();
        void writeChannel(Channel ChannelId,STD_LevelType Level);
        STD_LevelType readChannel(Channel ChannelId);
        void writeDirection(Channel ChannelId,Direction dir);

        uint8 readPort(Port port);
        void writePort(Port port, uint8 value);

    };

} // DIO

#endif //DIO_TEST_DIO_H
