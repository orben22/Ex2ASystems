#include "card.hpp"

using namespace ariel;

string picArr[4] = {"Hearts", "Clubs", "Spades", "Diamonds"};
string valueArr[13] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen",
                       "King"};

/**
 * Constructor
 * @param value holds the value of the card (A,2,3,...,J,Q,K)
 * @param pic holds the picture of the card (Hearts, Clubs, Spades, Diamonds)
 */
Card::Card(cardValue value, cardPic pic) : value(value), pic(pic) {}

/**
 * Compares 2 cards to each other
 * Ace wins everything but 2
 * @param other the card to compare to
 * @return enum of the state of this turn Draw/Player1Win/Player2Win
 */
whoWins Card::compare(Card other) const {
    if (this->value == Ace && other.value != Two) return Player1Win; // Ace beats any card except 2
    if (this->value != Two && other.value == Ace) return Player2Win;
    if (this->value > other.value) return Player1Win;
    if (this->value < other.value) return Player2Win;
    return Draw;
}

int Card::getintValue() {
    return this->value;
}

/**
 * get the string value of the card pic
 * @return a string representation of the pic
 */

string Card::getPic() {
    return picArr[this->pic - 1];
}

/**
 * get the string value of the card value
 * @return a string representation of the value
 */
string Card::getStringValue() {
    return valueArr[this->value - 1];
}


/**
 *
 * @return a string representation of the card class
 */
string Card::toString() {
    return getStringValue() + " of " + getPic() + " ";
}


