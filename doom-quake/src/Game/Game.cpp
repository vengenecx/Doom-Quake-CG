//
// Created by Lennert Steyaert on 30/04/2022.
//

#include "Game/Game.h"


Game::Game() :state(ROOM_A), change(false) {}


void Game::setStateRoomA() {
    state = ROOM_A;
    change = true;
}

void Game::setStateRoomB() {
    state = ROOM_B;
    change = true;
}

void Game::setStateRoomC() {
    state = ROOM_C;
    change = true;
}

void Game::setStateRoomD() {
    state = ROOM_D;
    change = true;
}

void Game::setStateRoomE() {
    state = ROOM_E;
    change = true;
}

GameState Game::getState(){
    return state;
}


bool Game::changed() {
    return change;
}

void Game::reset() {
    change = false;
}

