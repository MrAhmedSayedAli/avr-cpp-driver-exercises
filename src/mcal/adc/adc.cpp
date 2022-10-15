/*
By : Ahmed Elsayed Abdulrahman Ali
Email : mrahmedsayedali@gmail.com
github : https://github.com/MrAhmedSayedAli
*/

#include "adc.h"
#include "hw.h"


namespace MCAL {
    void ADC::init() {
        setBit(ADMUX_Reg,ADCMUX_REFS1_Bit);//Internal Vref
        setBit(ADMUX_Reg,ADCMUX_REFS0_Bit);
        setBit(ADCSRA_Reg,ADCSRA_ADPS0_Bit);//F_CPU/128
        setBit(ADCSRA_Reg,ADCSRA_ADPS1_Bit);
        setBit(ADCSRA_Reg,ADCSRA_ADPS2_Bit);
        setBit(ADCSRA_Reg,ADCSRA_ADEN_Bit);//Enable ADC
    }

    int16 ADC::read(DIO::Channel ChannelId) {
        int16 temp = 0;
        ADMUX_Reg = (ADMUX_Reg & 0xE0) | (static_cast<uint8>(ChannelId) & 0x1F);
        setBit(ADCSRA_Reg,ADCSRA_ADSC_Bit);
        while(getBit(ADCSRA_Reg,ADCSRA_ADIF_Bit) == 0);//wait finish conversion
        setBit(ADCSRA_Reg,ADCSRA_ADIF_Bit);//clear the flag
        temp = ADCL_Reg;
        temp |= (ADCH_Reg << 8);
        return temp;
    }
} // MCAL