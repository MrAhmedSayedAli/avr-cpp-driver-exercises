/*
By : Ahmed Elsayed Abdulrahman Ali
Email : mrahmedsayedali@gmail.com
github : https://github.com/MrAhmedSayedAli
*/

#include "keypad.h"
#include "util/delay.h"

namespace HAL {
    Keypad::Keypad(DIO::Channel rowZero, DIO::Channel rowOne, DIO::Channel rowTow, DIO::Channel rowThree, DIO::Channel colZero, DIO::Channel colOne, DIO::Channel colTow, DIO::Channel colThree) {

        dio.writeDirection(rowZero, DIO::Direction::OUTPUT);
        dio.writeDirection(rowOne, DIO::Direction::OUTPUT);
        dio.writeDirection(rowTow, DIO::Direction::OUTPUT);
        dio.writeDirection(rowThree, DIO::Direction::OUTPUT);

        dio.writeDirection(colZero, DIO::Direction::INPUT);
        dio.writeDirection(colOne, DIO::Direction::INPUT);
        dio.writeDirection(colTow, DIO::Direction::INPUT);
        dio.writeDirection(colThree, DIO::Direction::INPUT);

        keypadRow[0] = rowZero;
        keypadRow[1] = rowOne;
        keypadRow[2] = rowTow;
        keypadRow[3] = rowThree;


        keypadCol[0] = colZero;
        keypadCol[1] = colOne;
        keypadCol[2] = colTow;
        keypadCol[3] = colThree;


        keypadChars[0][0] = '1';
        keypadChars[0][1] = '2';
        keypadChars[0][2] = '3';
        keypadChars[0][3] = 'A';

        keypadChars[1][0] = '4';
        keypadChars[1][1] = '5';
        keypadChars[1][2] = '6';
        keypadChars[1][3] = 'B';

        keypadChars[2][0] = '7';
        keypadChars[2][1] = '8';
        keypadChars[2][2] = '9';
        keypadChars[2][3] = 'C';

        keypadChars[3][0] = '*';
        keypadChars[3][1] = '0';
        keypadChars[3][2] = '#';
        keypadChars[3][3] = 'D';


    }

    uint8 Keypad::getKey() {
        //test
        //return keypadChars[3][2];

        for (uint8 i = 0; i < 4; i++) {
            dio.writeChannel(keypadRow[i], STD_LevelType::HIGH);//output 5v
            dio.writeChannel(keypadCol[i], STD_LevelType::HIGH);//Pull up Res.
        }


        for (uint8 i = 0; i < 4; i++) {

            dio.writeChannel(keypadRow[i], STD_LevelType::LOW);

            for (uint8 j = 0; j < 4; j++) {


                //TODO::FIX_LED_BTN
                if(j == 2) continue;

                if (dio.readChannel(keypadCol[j]) == STD_LevelType::LOW) {
                    while (dio.readChannel(keypadCol[j]) == STD_LevelType::LOW){
                        return keypadChars[i][j];
                    }

                }
            }

            dio.writeChannel(keypadRow[i], STD_LevelType::HIGH);

        }
        return 0;
    }
} // HAL