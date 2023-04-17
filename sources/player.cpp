#include "player.hpp"

using namespace ariel;

/**
 * Player Constructor
 * @param name the name of the player
 */
Player::Player(std::string name) : name(std::move(name)), taken(0), wins(0), draw(0), isPlaying(false),
                                   winRate(0),
                                   drawRate(0) {}

/**
 * @return the amount of cards the player won in the game
 */
int Player::cardesTaken() const { return this->taken; }

/**
 * @return the amount of cards the player have left in the deck
 */
int Player::stacksize() const { return (int) this->deck.size(); }

/**
 * @return the player's name
 */
const string &Player::getName() const {
    return name;
}

/**
 * @return the player's deck
 */
vector<Card> Player::getDeck() {
    return deck;
}

/**
 * set a new deck for the player
 * @param newDeck
 */
void Player::setDeck(const vector<Card> &newDeck) {
    Player::deck = newDeck;
}

/**
 * cleans the player deck
 * mainly used at the end of the game
 */
void Player::clearDeck() {
    this->deck.clear();
}

/**
 * increase the number of wins of the player by one
 */
void Player::increaseWins() {
    this->wins++;
}

/**
 * increase the number of draws of the player by one
 */
void Player::increaseDraw() {
    Player::draw++;
}

/**
 * check if the player is in a game or not
 * @return true/false
 */
bool Player::getIsPlaying() const {
    return isPlaying;
}

/**
 * calculate the win rate of the player
 * calls increaseWins() first
 * @param numOfTurns that happened in a game
 * @param won if the player won this turn or not
 */
void Player::setWinRate(int numOfTurns, bool won) {
    if (won) this->increaseWins();
    if (numOfTurns != 0) Player::winRate = 100 * (((double) this->wins) / numOfTurns);
    else Player::winRate = 0;
}

/**
 * calculate the win draw of the player
 * calls increaseDraw() first
 * @param numOfTurns that happened in a game
 */
void Player::setDrawRate(int numOfTurns) {
    increaseDraw();
    if (numOfTurns != 0) Player::drawRate = 100 * (((double) this->draw) / numOfTurns);
    else Player::drawRate = 0;
}

/**
 * a string representation of the Player class
 * @return a string
 */
string Player::toString() const {
    string playerData;
    playerData = this->getName() + " has: " + to_string(this->wins) + " wins,with " + to_string(this->winRate) +
                 "% win rate and " +
                 to_string(this->draw) + " draws,with " +
                 to_string(this->drawRate) + "% draw rate, earned " +
                 to_string(this->taken) + " cards";
    return playerData;
}

/**
 * removes the top card from the deck
 */
void Player::throwCardFromDeck() {
    this->deck.pop_back();
}

/**
 * increase the amount of cards taken
 * @param amountToAdd
 */
void Player::addTaken(int amountToAdd) {
    this->taken += amountToAdd;
}


