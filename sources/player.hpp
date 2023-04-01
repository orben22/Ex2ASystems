//
// Created by or on 3/21/23.
//

#ifndef CARDWAR_A_MAIN_PLAYER_H
#define CARDWAR_A_MAIN_PLAYER_H

#include "iostream"
#include "card.hpp"
#include "vector"
using namespace std;
namespace ariel{

class Player {
private: // data members
    string name; // the name of the Player
    vector<Card> deck; // the player's cards deck
public:
    Player(string name); // constructor
    ~Player(); // destructor
    int stacksize();
    int cardsTaken();

    const string &getName() const;

    void setName(const string &name);

    const vector<Card> &getDeck() const;

    void setDeck(const vector<Card> &deck);
};

}


#endif //CARDWAR_A_MAIN_PLAYER_H
