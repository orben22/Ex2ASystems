//
// Created by or on 3/21/23.
//

#ifndef CARDWAR_A_MAIN_GAME_H
#define CARDWAR_A_MAIN_GAME_H

#include "player.hpp"
#include "card.hpp"
#include <vector>
#include <algorithm>
#include <random>
#include <iostream>

using namespace std;
namespace ariel {
    class Game {
    private: // data members
        Player &player1;
        Player &player2;
        vector<Card> deck;
        int const playerDeckSize = 26;
        vector<string> turns;
        int numOfTurns;
        enum whoWins winner;

    public:
        Game(Player &player1, Player &player2); // constructor

        void playTurn();

        void printLastTurn();

        void playAll();

        void printWiner();

        void printLog();

        void printStats();

        const Player &getP1() const;

        const Player &getP2() const;

    private:
        void generateDeck();

        void determineWinner();

        whoWins checkTurn();

        static void shuffleDeck(vector<Card> &deckToShuffle);

        const vector<Card> &getDeck() const;

        void setDeck(const vector<Card> &newDeck);


    };

}

#endif //CARDWAR_A_MAIN_GAME_H
