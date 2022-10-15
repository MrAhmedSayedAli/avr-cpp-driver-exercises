/*
By : Ahmed Elsayed Abdulrahman Ali
Email : mrahmedsayedali@gmail.com
github : https://github.com/MrAhmedSayedAli
*/

#ifndef DIO_CPP_HW_H
#define DIO_CPP_HW_H

#include "STD_Types.h"

#define ADCMUX_REFS1_Bit (7)
#define ADCMUX_REFS0_Bit (6)

#define ADCSRA_ADPS0_Bit (0)
#define ADCSRA_ADPS1_Bit (1)
#define ADCSRA_ADPS2_Bit (2)
#define ADCSRA_ADIF_Bit  (4)
#define ADCSRA_ADSC_Bit	 (6)
#define ADCSRA_ADEN_Bit  (7)

#define ADMUX_Reg (*(volatile uint8 *)0x27)
#define ADCSRA_Reg (*(volatile uint8 *)0x26)
#define ADCH_Reg (*(volatile uint8 *)0x25)
#define ADCL_Reg (*(volatile uint8 *)0x24)

namespace MCAL{

    enum class ADC_Channel{
        CH0=0,
        CH1,
        CH2,
        CH3,
        CH4,
        CH5,
        CH6,
        CH7

    };
}


#endif //DIO_CPP_HW_H
