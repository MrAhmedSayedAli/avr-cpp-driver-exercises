/*
By : Ahmed Elsayed Abdulrahman Ali
Email : mrahmedsayedali@gmail.com
github : https://github.com/MrAhmedSayedAli
*/

#ifndef DIO_CPP_ADC_H
#define DIO_CPP_ADC_H
#include "dio/dio.h"
namespace MCAL {

    class ADC {
    public:
        ADC() = default;
        void init();
        int16 read(DIO::Channel ChannelId);

    };

} // MCAL

#endif //DIO_CPP_ADC_H
