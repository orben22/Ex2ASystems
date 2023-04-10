#include "card.hpp"

using namespace ariel;
string picArr[4]={"Hearts", "Clubs" , "Spades" , "Diamonds" };
string valueArr[13]={"Ace","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Jack","Queen","King"};
ariel::Card::Card(cardValue value, cardPic pic):value(value),pic(pic){};

const whowins Card::compare(Card other) const{
    if (this->value==Ace && other.value!=Two) return Player1Win; // Ace beats any card except 2
    if (this->value!=Two && other.value==Ace) return Player2Win;
    if (this->value>other.value) return Player1Win;
    if (this->value<other.value) return Player2Win;
    return Draw;
}

int Card::getintValue() {
    return this->value;
}

string Card::getPic() {
    return picArr[this->pic-1];
}

string Card::getstringValue() {
    return valueArr[this->value-1];
}

string Card::toString() {
    return getstringValue()+" of "+getPic()+" ";
}


