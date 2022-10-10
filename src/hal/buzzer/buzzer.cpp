/*
By : Ahmed Elsayed Abdulrahman Ali
Email : mrahmedsayedali@gmail.com
github : https://github.com/MrAhmedSayedAli
*/

#define __DELAY_BACKWARD_COMPATIBLE__
#include "util/delay.h"
#include "buzzer.h"


namespace HAL {
    Buzzer::Buzzer(DIO::Channel ChannelID,STD_LevelType level) {
        ChannelId = ChannelID;
        dio.writeDirection(ChannelId,DIO::Direction::OUTPUT);
        dio.writeChannel(ChannelId,level);
    }

    //----------------------------------------------->
    void Buzzer::on() {
        dio.writeChannel(ChannelId, STD_LevelType::HIGH);
    }

    //----------------------------------------------->
    void Buzzer::off() {
        dio.writeChannel(ChannelId, STD_LevelType::LOW);
    }

    //----------------------------------------------->
    void Buzzer::tone(float frequency, float duration) {

        long int i, cycles;
        double half_period;
        float wavelength;

        wavelength = (1 / frequency) * 1000;
        cycles = duration / wavelength;
        half_period = wavelength / 2;
//
//        unsigned long startTime = millis();
//        unsigned long halfPeriod= F_CPU /frequency/2;

        for (i = 0; i < cycles; i++) {
            on();
            _delay_ms(half_period);
            off();
            _delay_ms(half_period);
        }
    }
} // HAL