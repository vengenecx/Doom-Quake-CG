//
// Created by Lennert Steyaert on 21/03/2022.
//

#ifndef DOOM_QUAKE_OCTANTS_H
#define DOOM_QUAKE_OCTANTS_H
enum class Octants : unsigned char{
    FRONTUPLEFT = 0,
    FRONTUPRIGHT = 1,
    FRONTBOTTOMRIGHT = 2,
    FRONTBOTTOMLEFT = 3,
    BACKUPLEFT = 4,
    BACKUPRIGHT = 5,
    BACKBOTTOMRIGHT = 6,
    BACKBOTTOMLEFT = 7
};
#endif //DOOM_QUAKE_OCTANTS_H
