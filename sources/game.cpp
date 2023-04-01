#include "game.hpp"

using namespace ariel;

ariel::Game::Game(ariel::Player &p1, ariel::Player &p2): p1(p1),p2(p2){
    generateDeck();
    shuffleDeck();
    vector<Card> player1Deck(getDeck().begin(), getDeck().begin() + this->playerDeckSize);
    std::vector<Card> player2Deck(getDeck().begin() + this->playerDeckSize, getDeck().end());
    this->p1.setDeck(player1Deck);
    this->p2.setDeck(player2Deck);
};
ariel::Game::~Game() {};

void ariel::Game::playAll() {};

void ariel::Game::playTurn() {};

void ariel::Game::printLastTurn() {};

void ariel::Game::printLog() {};

void ariel::Game::printStats() {};

void ariel::Game::printWiner() {};

void Game::generateDeck() {
    vector<Card> deck;
    for (int i=0;i<13;i++){
        for (int j=0;j<4;j++){
            Card c(cardValue(i+1),cardPic(j+1));
            deck.push_back(c);
        }
    }
    setDeck(deck);
}
const Player &Game::getP1() const {
    return p1;
}
const Player &Game::getP2() const {
    return p2;
}
const vector<Card> &Game::getDeck() const {
    return deck;
}
void Game::setDeck(const vector<Card> &newdeck) {
    Game::deck = newdeck;
}
void Game::shuffleDeck() {
    random_device rand;
    mt19937 g(rand());// random number generator
    shuffle(deck.begin(), deck.end(), g);
}
