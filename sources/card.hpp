//
// Created by or on 3/21/23.
//

#ifndef CARDWAR_A_MAIN_CARD_H
#define CARDWAR_A_MAIN_CARD_H

#include "iostream"

using namespace std;
namespace ariel{

class Card {
private: // data members
    string value; // holds the value of the card (A,2,3,...,J,Q,K)
    string pic; // holds the picture of the card (Hearts, Clubs, Spades, Diamonds)
public:
    Card(string value, string pic); // constructor
    ~Card(); // destructor
};

}

#endif //CARDWAR_A_MAIN_CARD_H
