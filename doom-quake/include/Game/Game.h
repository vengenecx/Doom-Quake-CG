//
// Created by Lennert Steyaert on 30/04/2022.
//

#ifndef DOOM_QUAKE_GAME_H
#define DOOM_QUAKE_GAME_H

enum GameState {
    ROOM_A,
    ROOM_B,
    ROOM_C,
    ROOM_D,
    ROOM_E
};

class Game
{
public:
//    // game state
    Game();
    void setStateRoomA();
    void setStateRoomB();
    void setStateRoomC();
    void setStateRoomD();
    void setStateRoomE();

    GameState getState();

    bool changed();

    void reset();

private:
    GameState    state;
    bool change;
};



#endif //DOOM_QUAKE_GAME_H
