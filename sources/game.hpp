//
// Created by or on 3/21/23.
//

#ifndef CARDWAR_A_MAIN_GAME_H
#define CARDWAR_A_MAIN_GAME_H

#include "player.hpp"
#include "card.hpp"
#include "vector"
#include <algorithm>
#include <random>
#include "iostream"

using namespace std;
namespace ariel{
class Game {
private: // data members
    Player p1;
    Player p2;
    vector<Card> deck;
    int const playerDeckSize=26;
public:
    Game(Player &p1, Player &p2); // constructor
    ~Game(); // destructor

    void playTurn();

    void printLastTurn();

    void playAll();

    void printWiner();

    void printLog();

    void printStats();

    void generateDeck();

    const Player &getP1() const;

    const Player &getP2() const;

    const vector<Card> &getDeck() const;

    void setDeck(const vector<Card> &deck);

    void shuffleDeck();
};

}

#endif //CARDWAR_A_MAIN_GAME_H
