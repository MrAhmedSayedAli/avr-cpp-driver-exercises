/*
By : Ahmed Elsayed Abdulrahman Ali
Email : mrahmedsayedali@gmail.com
github : https://github.com/MrAhmedSayedAli
*/

#include "dio.h"

namespace DIO {

//TODO::DELETE
    PinConfig pins[] = {
            //PORTA
            {Direction::OUTPUT, STD_LevelType::LOW},
            {Direction::OUTPUT, STD_LevelType::LOW},
            {Direction::OUTPUT, STD_LevelType::LOW},
            {Direction::OUTPUT, STD_LevelType::LOW},
            {Direction::OUTPUT, STD_LevelType::LOW},
            {Direction::OUTPUT, STD_LevelType::LOW},
            {Direction::OUTPUT, STD_LevelType::LOW},
            {Direction::OUTPUT, STD_LevelType::LOW},

            //PORTB
            {Direction::OUTPUT, STD_LevelType::LOW},
            {Direction::OUTPUT, STD_LevelType::LOW},
            {Direction::OUTPUT, STD_LevelType::LOW},
            {Direction::OUTPUT, STD_LevelType::LOW},
            {Direction::OUTPUT, STD_LevelType::LOW},
            {Direction::OUTPUT, STD_LevelType::LOW},
            {Direction::OUTPUT, STD_LevelType::LOW},
            {Direction::OUTPUT, STD_LevelType::LOW},

            //PORTC
            {Direction::OUTPUT, STD_LevelType::LOW},
            {Direction::OUTPUT, STD_LevelType::LOW},
            {Direction::OUTPUT, STD_LevelType::LOW},
            {Direction::OUTPUT, STD_LevelType::LOW},
            {Direction::OUTPUT, STD_LevelType::LOW},
            {Direction::OUTPUT, STD_LevelType::LOW},
            {Direction::OUTPUT, STD_LevelType::LOW},
            {Direction::OUTPUT, STD_LevelType::LOW},

            //PORTD
            {Direction::OUTPUT, STD_LevelType::LOW},
            {Direction::OUTPUT, STD_LevelType::LOW},
            {Direction::OUTPUT, STD_LevelType::LOW},
            {Direction::OUTPUT, STD_LevelType::LOW},
            {Direction::OUTPUT, STD_LevelType::LOW},
            {Direction::OUTPUT, STD_LevelType::LOW},
            {Direction::OUTPUT, STD_LevelType::LOW},
            {Direction::OUTPUT, STD_LevelType::LOW}
    };

    //----------------------------------------------------------->
    //TODO::DELETE
    void Dio::init() {

        uint8 count = 0;

        Port port;
        Channel BitNo;
        for (count = static_cast<uint8>(Channel::A0); count < PIN_COUNT; count++) {
            port = static_cast<Port>(count / 8);
            BitNo = static_cast<Channel>(count % 8);

            switch (port) {
                case Port::A:
                    if (pins[count].PinDir == Direction::OUTPUT) {

                        setBit(DDRA_Reg, static_cast<uint8>(BitNo));
                        if (pins[count].Level == STD_LevelType::HIGH)
                            setBit(PORTA_Reg, static_cast<uint8>(BitNo));
                    } else {
                        clearBit(DDRA_Reg, static_cast<uint8>(BitNo));
                    }
                    break;
                case Port::B:
                    if (pins[count].PinDir == Direction::OUTPUT) {
                        setBit(DDRB_Reg, static_cast<uint8>(BitNo));
                        if (pins[count].Level == STD_LevelType::HIGH)
                            setBit(PORTB_Reg, static_cast<uint8>(BitNo));
                    } else {
                        clearBit(DDRB_Reg, static_cast<uint8>(BitNo));
                    }
                    break;
                case Port::C:
                    if (pins[count].PinDir == Direction::OUTPUT) {
                        setBit(DDRC_Reg, static_cast<uint8>(BitNo));
                        if (pins[count].Level == STD_LevelType::HIGH)
                            setBit(PORTC_Reg, static_cast<uint8>(BitNo));
                    } else {
                        clearBit(DDRC_Reg, static_cast<uint8>(BitNo));
                    }
                    break;
                case Port::D:
                    if (pins[count].PinDir == Direction::OUTPUT) {
                        setBit(DDRD_Reg, static_cast<uint8>(BitNo));
                        if (pins[count].Level == STD_LevelType::HIGH)
                            setBit(PORTD_Reg, static_cast<uint8>(BitNo));
                    } else {
                        clearBit(DDRD_Reg, static_cast<uint8>(BitNo));
                    }
                    break;

                default:
                    break;
            }
        }
    }
    //----------------------------------------------------------->
    void Dio::writeChannel(Channel ChannelId, STD_LevelType Level) {


        auto ports = static_cast<Port>(static_cast<uint8>(ChannelId) / 8);
        auto BitNo = static_cast<Channel>(static_cast<uint8>(ChannelId) % 8);

        switch (ports) {
            case Port::A:
                if (Level == STD_LevelType::HIGH) {
                    setBit(PORTA_Reg, static_cast<uint8>(BitNo));
                } else {
                    clearBit(PORTA_Reg, static_cast<uint8>(BitNo));
                }
                break;
            case Port::B:
                if (Level == STD_LevelType::HIGH) {
                    setBit(PORTB_Reg, static_cast<uint8>(BitNo));
                } else {
                    clearBit(PORTB_Reg, static_cast<uint8>(BitNo));
                }
                break;
            case Port::C:
                if (Level == STD_LevelType::HIGH) {
                    setBit(PORTC_Reg, static_cast<uint8>(BitNo));
                } else {
                    clearBit(PORTC_Reg, static_cast<uint8>(BitNo));
                }
                break;
            case Port::D:
                if (Level == STD_LevelType::HIGH) {
                    setBit(PORTD_Reg, static_cast<uint8>(BitNo));
                } else {
                    clearBit(PORTD_Reg, static_cast<uint8>(BitNo));
                }
                break;
            default:
                break;
        }
    }
    //----------------------------------------------------------->
    STD_LevelType Dio::readChannel(Channel ChannelId) {

        auto Ports = static_cast<Port>(static_cast<uint8>(ChannelId) / 8);
        auto BitNo = static_cast<Channel>(static_cast<uint8>(ChannelId) % 8);

        int BitValue = static_cast<uint8>(STD_LevelType::LOW);
        switch (Ports) {
            case Port::A:
                BitValue = getBit(PINA_Reg, static_cast<uint8>(BitNo));
                break;
            case Port::B:
                BitValue = getBit(PINB_Reg, static_cast<uint8>(BitNo));
                break;
            case Port::C:
                BitValue = getBit(PINC_Reg, static_cast<uint8>(BitNo));
                break;
            case Port::D:
                BitValue = getBit(PIND_Reg, static_cast<uint8>(BitNo));
                break;
            default:
                break;
        }
        return static_cast<STD_LevelType>(BitValue);
    }
    //----------------------------------------------------------->
    void Dio::writeDirection(Channel ChannelId, Direction dir) {

        auto port = static_cast<Port>(static_cast<uint8>(ChannelId) / 8);
        auto BitNo = static_cast<Channel>(static_cast<uint8>(ChannelId) % 8);

        switch (port) {
            case Port::A:
                if (dir == Direction::OUTPUT) {
                    setBit(DDRA_Reg, static_cast<uint8>(BitNo));
                } else {
                    clearBit(DDRA_Reg, static_cast<uint8>(BitNo));
                }
                break;
            case Port::B:
                if (dir == Direction::OUTPUT) {
                    setBit(DDRB_Reg, static_cast<uint8>(BitNo));
                } else {
                    clearBit(DDRB_Reg, static_cast<uint8>(BitNo));
                }
                break;
            case Port::C:
                if (dir == Direction::OUTPUT) {
                    setBit(DDRC_Reg, static_cast<uint8>(BitNo));
                } else {
                    clearBit(DDRC_Reg, static_cast<uint8>(BitNo));
                }
                break;
            case Port::D:
                if (dir == Direction::OUTPUT) {
                    setBit(DDRD_Reg, static_cast<uint8>(BitNo));
                } else {
                    clearBit(DDRD_Reg, static_cast<uint8>(BitNo));
                }
                break;

            default:
                break;
        }

    }
    //----------------------------------------------------------->
    uint8 Dio::readPort(Port port) {
        switch (port) {
            case Port::A:
                return PORTA_Reg;
            case Port::B:
                return PORTB_Reg;
            case Port::C:
                return PORTC_Reg;
            case Port::D:
                return PORTD_Reg;
            default:
                return 0;
        }
    }
    //----------------------------------------------------------->
    void Dio::writePort(Port port, uint8 value) {
        switch (port) {
            case Port::A:
                PORTA_Reg = value;
                break;
            case Port::B:
                PORTB_Reg = value;
                break;
            case Port::C:
                PORTC_Reg = value;
                break;
            case Port::D:
                PORTD_Reg = value;
                break;
            default:
                return;
        }
    }
} // DIO