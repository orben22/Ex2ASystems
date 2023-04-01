#include "player.hpp"

using namespace ariel;

ariel::Player::Player(std::string name) : name(name){};
ariel::Player::~Player() {};

int ariel::Player::cardsTaken() {return 1;};

int ariel::Player::stacksize() {return 1;};

const string &Player::getName() const {
    return name;
}

const vector<Card> &Player::getDeck() const {
    return deck;
}

void Player::setDeck(const vector<Card> &newdeck) {
    Player::deck = newdeck;
}
