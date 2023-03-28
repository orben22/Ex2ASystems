#include "game.hpp"

using namespace ariel;

ariel::Game::Game(ariel::Player &p1, ariel::Player &p2): p1(p1),p2(p2){};
ariel::Game::~Game() {};

void ariel::Game::playAll() {};

void ariel::Game::playTurn() {};

void ariel::Game::printLastTurn() {};

void ariel::Game::printLog() {};

void ariel::Game::printStats() {};

void ariel::Game::printWiner() {};
