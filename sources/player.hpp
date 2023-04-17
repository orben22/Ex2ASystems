//
// Created by or on 3/21/23.
//

#ifndef CARDWAR_A_MAIN_PLAYER_H
#define CARDWAR_A_MAIN_PLAYER_H

#include "iostream"
#include "card.hpp"
#include "vector"

using namespace std;
namespace ariel {

    class Player {
    private: // data members
        string name; // the name of the Player
        vector<Card> deck; // the player's cards deck
        int taken;
        int wins;
        int draw;
        double winRate;
        double drawRate;
        bool isPlaying;
    public:
        explicit Player(string name); // constructor

        int stacksize() const;

        int cardesTaken() const;

        const string &getName() const;

        vector<Card> getDeck();

        void setDeck(const vector<Card> &newDeck);

        void addTaken(int amountToAdd);


        bool getIsPlaying() const;

        void setWinRate(int numOfTurns, bool won);

        void setDrawRate(int numOfTurns);

        string toString() const;

        void throwCardFromDeck();

        void clearDeck();

    private:
        void increaseWins();

        void increaseDraw();

    };

}
#endif //CARDWAR_A_MAIN_PLAYER_H
