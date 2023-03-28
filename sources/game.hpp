//
// Created by or on 3/21/23.
//

#ifndef CARDWAR_A_MAIN_GAME_H
#define CARDWAR_A_MAIN_GAME_H

#include "player.hpp"
#include "card.hpp"
#include "iostream"

using namespace std;
namespace ariel{
class Game {
private: // data members
    Player p1;
    Player p2;
    Card *card;
public:
    Game(Player &p1, Player &p2); // constructor
    ~Game(); // destructor

    void playTurn();

    void printLastTurn();

    void playAll();

    void printWiner();

    void printLog();

    void printStats();
};

}

#endif //CARDWAR_A_MAIN_GAME_H
