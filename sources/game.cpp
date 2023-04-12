#include "game.hpp"

using namespace ariel;

ariel::Game::Game(ariel::Player &player1, ariel::Player &player2) : player1(player1), player2(player2), numOfTurns(0),
                                                                    winner(NoWinner) {

    generateDeck();
    shuffleDeck(this->deck);
    vector <Card> player1Deck(getDeck().begin(), getDeck().begin() + this->playerDeckSize);
    vector <Card> player2Deck(getDeck().begin() + this->playerDeckSize, getDeck().end());
    this->player1.setDeck(player1Deck);
    this->player2.setDeck(player2Deck);
};

void ariel::Game::playAll() {
    if (winner == Player1Win || winner == Player2Win) throw std::logic_error("The game is finished");
    while (winner == NoWinner) {
        this->playTurn();
    }
};

void ariel::Game::playTurn() {
    if (&player1 == &player2) throw std::logic_error("The same player can't play VS himself");
    if (player1.getIsplaying() || player2.getIsplaying())
        throw std::logic_error("Player can't play more than a one game at the same time");
    if (this->winner != NoWinner) throw std::logic_error("the game ended... can't play another turn");
    this->numOfTurns++;
    int countDraw = 0;
    vector <Card> throws1;
    vector <Card> throws2;
    whowins temp = checkturn();
    throws1.push_back(this->player1.getDeck().back());
    throws2.push_back(this->player2.getDeck().back());
    this->player1.throwCardFromDeck();
    this->player2.throwCardFromDeck();
    while (temp == Draw) {
        countDraw++;
        if (this->player1.getDeck().size() < 2 || this->player2.getDeck().size() < 2) {
            if (countDraw > 0) {
                for (size_t i = 0; i < this->player1.getDeck().size() && i < this->player2.getDeck().size(); i++) {
                    throws1.push_back(this->player1.getDeck().at(i));
                    throws2.push_back(this->player2.getDeck().at(i));
                }
                this->shuffleDeck(throws1);
                this->shuffleDeck(throws2);
                this->player1.setDeck(throws1);
                this->player2.setDeck(throws2);
            } else {
                this->player1.addtaken(2);
                this->player2.addtaken(2);
                this->player1.getDeck().clear();
                this->player2.getDeck().clear();
                this->determineWinner();
                return;
            }
        }
        this->player1.setDrawrate(numOfTurns); // increase number of draws for each player
        this->player2.setDrawrate(numOfTurns);
        throws1.push_back(this->player1.getDeck().back());
        throws2.push_back(this->player2.getDeck().back());
        this->player1.throwCardFromDeck();
        this->player2.throwCardFromDeck();
        temp = checkturn();
        throws1.push_back(this->player1.getDeck().back());
        throws2.push_back(this->player2.getDeck().back());
        this->player1.throwCardFromDeck();
        this->player2.throwCardFromDeck();
    }
    if (temp == Player1Win) {
        this->player1.addtaken((int) (throws2.size() + throws1.size()));
        this->player2.setWinrate(numOfTurns, false);
        this->player1.setWinrate(numOfTurns, true);
    }
    if (temp == Player2Win) {
        this->player2.addtaken((int) (throws2.size() + throws1.size()));
        this->player2.setWinrate(numOfTurns, true);
        this->player1.setWinrate(numOfTurns, false);
    }
    if (this->player1.getDeck().empty() && this->player2.getDeck().empty()) this->determineWinner();
};

void ariel::Game::printLastTurn() {
    if (this->numOfTurns == 0) throw std::logic_error("There were no turns yet in this game");
    string strtemp = this->turns.back();
    for (int i = this->turns.size() - 2; i >= 0; i--) {
        if (turns.at((size_t) i).find("draw") == string::npos) break;
        else strtemp.insert(0, this->turns.at((size_t) i));
    }
    cout << strtemp << endl;
};

void ariel::Game::printLog() {
    if (this->numOfTurns == 0) throw std::logic_error("There were no turns yet in this game");
    string strtemp;
    for (const string &thisturn: turns) {
        if (thisturn.find("Draw") == string::npos) {
            strtemp += thisturn;
            cout << strtemp << endl;
            strtemp = "";
        } else strtemp += thisturn;
    }
};

void ariel::Game::printStats() {
    cout << "Printing game stats:" << endl;
    cout << "Player 1 stats: " << player1.toString() << endl;
    cout << "Player 2 stats: " << player2.toString() << endl;
};

void ariel::Game::printWiner() {
    if (winner == Player1Win) cout << player1.getName() << " is the winner" << endl;
    else if (winner == Player2Win) cout << player2.getName() << " is the winner" << endl;
    else if (winner == Draw) cout << "the game ends in a draw" << endl;
    else cout << "their is no winner yet" << endl;
};

void Game::generateDeck() {
    vector <Card> deck;
    for (int i = 0; i < 13; i++) {
        for (int j = 0; j < 4; j++) {
            Card c(cardValue(i + 1), cardPic(j + 1));
            deck.push_back(c);
        }
    }
    setDeck(deck);
}

const Player &Game::getP1() const {
    return player1;
}

const Player &Game::getP2() const {
    return player2;
}

const vector <Card> &Game::getDeck() const {
    return deck;
}

void Game::setDeck(const vector <Card> &newdeck) {
    Game::deck = newdeck;
}

void Game::shuffleDeck(vector <Card> decktoshuff) {
    random_device rand;
    mt19937 g(rand());// random number generator
    shuffle(decktoshuff.begin(), decktoshuff.end(), g);
}

whowins Game::getWinner() const {
    return winner;
}

void Game::setWinner(whowins newwinner) {
    Game::winner = newwinner;
}

whowins Game::checkturn() {
    string res;
    if (this->player1.getDeck().back().compare(this->player2.getDeck().back()) == Player1Win)
        res = this->player1.getName() + " wins";
    else if (this->player1.getDeck().back().compare(this->player2.getDeck().back()) == Player2Win)
        res = this->player2.getName() + " wins";
    else res = "Draw";
    string lastturn = this->player1.getName() + " played " + this->player1.getDeck().back().toString() +
                      this->player2.getName() + " played " + this->player2.getDeck().back().toString() + ". " + res;
    this->turns.push_back(lastturn);
    return this->player1.getDeck().back().compare(player2.getDeck().back());
}

void Game::determineWinner() {
    player1.getDeck().clear();
    player2.getDeck().clear();
    if (this->player1.gettaken() > this->player2.gettaken()) this->winner = Player1Win;
    else if (this->player1.gettaken() < this->player2.gettaken()) this->winner = Player2Win;
    else this->winner = Draw;
}
