/*
By : Ahmed Elsayed Abdulrahman Ali
Email : mrahmedsayedali@gmail.com
github : https://github.com/MrAhmedSayedAli
*/

#ifndef DIO_TEST_BITMATH_H
#define DIO_TEST_BITMATH_H

#define setBit(REG, BIT)        (REG |= (1<<BIT))
#define getBit(REG, BIT)        ((REG>>BIT) & 1)
#define toggleBit(REG, BIT)        (REG ^= (1<<BIT))
#define clearBit(REG, BIT)        (REG &=~(1<<BIT))


#endif //DIO_TEST_BITMATH_H
