//
// Created by or on 3/21/23.
//

#ifndef CARDWAR_A_MAIN_CARD_H
#define CARDWAR_A_MAIN_CARD_H

#include "iostream"

using namespace std;
namespace ariel{
    enum cardPic {
        Hearts = 1, Clubs = 2, Spades = 3, Diamonds = 4
    };
    enum cardValue {
        A = 1,
        Two = 2,
        Three = 3,
        Four = 4,
        Five = 5,
        Six = 6,
        Seven = 7,
        Eight = 8,
        Nine = 9,
        Ten = 10,
        J = 11,
        Q = 12,
        K = 13
    };
class Card {
private: // data members
    cardValue value; // holds the value of the card (A,2,3,...,J,Q,K)
    cardPic pic; // holds the picture of the card (Hearts, Clubs, Spades, Diamonds)
public:
    Card(cardValue value, cardPic pic); // constructor
    ~Card(); // destructor
};

}

#endif //CARDWAR_A_MAIN_CARD_H
