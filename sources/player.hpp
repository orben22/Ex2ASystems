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
        double winrate;
        double drawrate;
        bool isplaying;
    public:
        explicit Player(string name); // constructor

        int stacksize() const;

        int cardesTaken() const;

        const string &getName() const;

        vector<Card> getDeck();

        int gettaken() const;

        void setDeck(const vector<Card> &deck);

        void settaken(int newtaken);

        void addtaken(int newtaken);

        void increaseWins();

        int getWins() const;

        int getDraw() const;

        void increaseDraw();

        bool getIsplaying() const;

        void setIsplaying();

        double getWinrate() const;

        void setWinrate(int numofturns, bool won);

        double getDrawrate() const;

        void setDrawrate(int numofturns);

        string toString() const;

        void throwCardFromDeck();
    };

}
#endif //CARDWAR_A_MAIN_PLAYER_H
