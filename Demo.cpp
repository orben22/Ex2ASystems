
#include "sources/player.hpp"
#include "sources/game.hpp"
#include <iostream>

using namespace std;
using namespace ariel;

int main() {

    Player p1("Alice");
    Player p2("Bob");

    Game game(p1, p2);

    cout << "Start of the game details" << endl;
    game.printStats(); //should be "default values 0"

    game.playTurn();
    game.playAll();
    game.printLastTurn();

    if (p1.cardesTaken() == game.getP1().cardesTaken()) {
        cout << "It's the same player1 checking for reference" << endl;
    }
    if (p2.cardesTaken() == game.getP2().cardesTaken()) {
        cout << "It's the same player2 checking for reference" << endl;
    }

    game.printLog();

    game.printStats();
    //should be the same
    cout << "Printing the players" << endl;
    cout << p1.toString() << endl;
    cout << p2.toString() << endl;

    game.printWiner();
}