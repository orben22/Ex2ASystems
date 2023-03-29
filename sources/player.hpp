//
// Created by or on 3/21/23.
//

#ifndef CARDWAR_A_MAIN_PLAYER_H
#define CARDWAR_A_MAIN_PLAYER_H

#include "iostream"
#include "card.hpp"
using namespace std;
namespace ariel{

class Player {
private: // data members
    string name; // the name of the Player
    Card *deck; // the player's cards deck
public:
    Player(string name); // constructor
    ~Player(); // // destructor
    int stacksize();
    int cardesTaken();
};

}


#endif //CARDWAR_A_MAIN_PLAYER_H
