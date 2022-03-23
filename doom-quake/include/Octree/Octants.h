//
// Created by Lennert Steyaert on 21/03/2022.
//

#ifndef DOOM_QUAKE_OCTANTS_H
#define DOOM_QUAKE_OCTANTS_H
enum class Octants : unsigned char{
    Q1 = 0x01,
    Q2 = 0x02,
    Q3 = 0x04,
    Q4 = 0x08,
    Q5 = 0x10,
    Q6 = 0x20,
    Q7 = 0x40,
    Q8 = 0x80
};
#endif //DOOM_QUAKE_OCTANTS_H
