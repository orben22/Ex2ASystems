#include "player.hpp"
#include <utility>

using namespace ariel;

ariel::Player::Player(std::string name) : name(std::move(name)), taken(0), wins(0), draw(0), isplaying(false),
                                          winrate(0),
                                          drawrate(0) {};

int ariel::Player::cardesTaken() const { return this->taken; };

int ariel::Player::stacksize() const { return (int) this->deck.size(); };

const string &Player::getName() const {
    return name;
};

vector <Card> Player::getDeck() {
    return deck;
};

void Player::setDeck(const vector <Card> &newdeck) {
    Player::deck = newdeck;
};

void Player::settaken(const int newtaken) {
    this->taken = newtaken;
}

void Player::clearDeck() {
    this->deck.clear();
}

int Player::gettaken() const {
    return this->taken;
}

void Player::increaseWins() {
    this->wins++;
}

int Player::getWins() const {
    return wins;
}

int Player::getDraw() const {
    return draw;
}

void Player::increaseDraw() {
    Player::draw++;
}

bool Player::getIsplaying() const {
    return isplaying;
}

void Player::setIsplaying() {
    Player::isplaying = !Player::isplaying;
}

double Player::getWinrate() const {
    return winrate;
}

void Player::setWinrate(int numofturns, bool won) {
    if (won) this->increaseWins();
    if (numofturns != 0) Player::winrate = 100 * (((double) this->wins) / numofturns);
    else Player::winrate = 0;
}

double Player::getDrawrate() const {
    return drawrate;
}

void Player::setDrawrate(int numofturns) {
    increaseDraw();
    if (numofturns != 0) Player::drawrate = 100 * (((double) this->draw) / numofturns);
    else Player::drawrate = 0;
}

string Player::toString() const {
    string playerdata;
    playerdata = this->getName() + " has: " + to_string(this->wins) + " wins,with " + to_string(this->winrate) +
                 "% win rate and " +
                 to_string(this->draw) + " draws,with " +
                 to_string(this->drawrate) + "% draw rate, earned " +
                 to_string(this->taken) + " cards";
    return playerdata;
}

void Player::throwCardFromDeck() {
    this->deck.pop_back();
}

void Player::addtaken(int newtaken) {
    this->taken += newtaken;
};


