#include "player.hpp"

using namespace ariel;

ariel::Player::Player(std::string name) : name(name){};
ariel::Player::~Player() {};

int ariel::Player::cardesTaken() {return 1;};

int ariel::Player::stacksize() {return 1;};