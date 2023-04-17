#include "game.hpp"

using namespace ariel;

/**
 * Game constructor
 * @param player1 the first player reference
 * @param player2 the second player reference
 */
Game::Game(Player &player1, Player &player2) : player1(player1), player2(player2), numOfTurns(0),
                                               winner(NoWinner) {

    generateDeck();
    shuffleDeck(this->deck);
    vector<Card> player1Deck(getDeck().begin(), getDeck().begin() + this->playerDeckSize);
    vector<Card> player2Deck(getDeck().begin() + this->playerDeckSize, getDeck().end());
    this->player1.setDeck(player1Deck);
    this->player2.setDeck(player2Deck);
}

/**
 * Play the game until the end
 * @throws logic_error if the game has ended already
 */
void Game::playAll() {
    if (winner == Player1Win || winner == Player2Win) throw std::logic_error("The game is finished");
    while (winner == NoWinner) {
        this->playTurn();
    }
}

/**
 * Play a single turn in the game
 * each card thrown is stored in throws1 and throws2 for player 1 and player 2
 * if there is a draw the players will play war
 * removing 2 cards from their decks the last card of each player that have been drawn will be
 * checked against one another repeat this if there is a tie again
 * special cases:
 * if both players don't have enough cards to player war after a tie (1 or 0 cards left)
 * and there have been no wars before they just take the cards back as cardsTaken and the game ends
 * if there have been wars before put all the cards in thrown1/2 reshuffle and end the turn
 *
 * @throw logic_error if both players are the same or if the players are already in another game
 */
void Game::playTurn() {
    if (&player1 == &player2) throw std::logic_error("The same player can't play VS himself");
    if (player1.getIsPlaying() || player2.getIsPlaying())
        throw std::logic_error("Player can't play more than a one game at the same time");
    if (this->winner != NoWinner) throw std::logic_error("the game ended... can't play another turn");
    this->numOfTurns++;
    int countDraw = 0;
    vector<Card> throws1;
    vector<Card> throws2;
    whoWins temp = checkTurn();
    throws1.push_back(this->player1.getDeck().back());
    throws2.push_back(this->player2.getDeck().back());
    this->player1.throwCardFromDeck();
    this->player2.throwCardFromDeck();
    while (temp == Draw) {
        if (this->player1.stacksize() < 2 || this->player2.stacksize() < 2) {
            if (countDraw > 0) {
                for (size_t i = 0; i < this->player1.getDeck().size() && i < this->player2.getDeck().size(); i++) {
                    throws1.push_back(this->player1.getDeck().at(i));
                    throws2.push_back(this->player2.getDeck().at(i));
                }
                Game::shuffleDeck(throws1);
                Game::shuffleDeck(throws2);
                this->player1.setDeck(throws1);
                this->player2.setDeck(throws2);
                throws1.clear();
                throws2.clear();
                continue;
            } else if (this->player1.getDeck().size() == 1 || this->player2.getDeck().size() == 1) {
                this->player1.addTaken(2);
                this->player2.addTaken(2);
                this->determineWinner();
                return;
            } else if (this->player1.getDeck().empty() || this->player2.getDeck().empty()) {
                this->player1.addTaken(1);
                this->player2.addTaken(1);
                this->determineWinner();
                return;
            }
        }
        countDraw++;
        this->player1.setDrawRate(numOfTurns); // increase number of draws for each player
        this->player2.setDrawRate(numOfTurns);
        throws1.push_back(this->player1.getDeck().back());
        throws2.push_back(this->player2.getDeck().back());
        this->player1.throwCardFromDeck();
        this->player2.throwCardFromDeck();
        temp = checkTurn();
        throws1.push_back(this->player1.getDeck().back());
        throws2.push_back(this->player2.getDeck().back());
        this->player1.throwCardFromDeck();
        this->player2.throwCardFromDeck();
    }
    if (temp == Player1Win) {
        this->player1.addTaken((int) (throws2.size() + throws1.size()));
        this->player2.setWinRate(numOfTurns, false);
        this->player1.setWinRate(numOfTurns, true);
    }
    if (temp == Player2Win) {

        this->player2.addTaken((int) (throws2.size() + throws1.size()));
        this->player2.setWinRate(numOfTurns, true);
        this->player1.setWinRate(numOfTurns, false);
    }
    if (this->player1.getDeck().empty() && this->player2.getDeck().empty()) this->determineWinner();
}

/**
 * Print the last turn that happened in the game
 * checks if the the previous entry in turns ended in a draw if it did concat it
 * @throws logic_error if there were no games played this turn
 */
void Game::printLastTurn() {
    if (this->numOfTurns == 0) throw std::logic_error("There were no turns yet in this game");
    std::string strTemp = this->turns.back();
    for (int i = (int) this->turns.size() - 2; i >= 0; i--) {
        if (turns.at((size_t) i).find("Draw.") == std::string::npos) {
            break;
        } else strTemp.insert(0, this->turns.at((size_t) i));
    }
    std::cout << strTemp << std::endl;
}


/**
 * Print all the turns that happened in the game
 * checks if the the current entry is a draw if it is concat it to as a part of this turn
 * @throws logic_error if there have been no turns this game
 */
void Game::printLog() {
    if (this->numOfTurns == 0) throw std::logic_error("There were no turns yet in this game");
    string strTemp;
    for (const string &thisTurn: turns) {
        if (thisTurn.find("Draw.") == string::npos) {
            strTemp += thisTurn;
            std::cout << strTemp << std::endl;
            strTemp = "";
        } else strTemp += thisTurn;
    }
}

/**
 * Prints the string representation of the the 2 players
 */
void Game::printStats() {
    cout << "Printing game stats:" << endl;
    cout << "Player 1 stats: " << player1.toString() << endl;
    cout << "Player 2 stats: " << player2.toString() << endl;
}

/**
 * Print the winner of the game
 */
void Game::printWiner() {
    if (winner == Player1Win) cout << player1.getName() << " is the winner" << endl;
    else if (winner == Player2Win) cout << player2.getName() << " is the winner" << endl;
    else if (winner == Draw) cout << "the game ends in a draw" << endl;
    else cout << "there is no winner yet" << endl;
}

/**
 * generates a 52 cards deck at the start of the game
 * 13 types of cards (A,2,3,...,J,Q,K)
 * 4 of each picture (Hearts, Clubs, Spades, Diamonds)
 */
void Game::generateDeck() {
    vector<Card> newDeck;
    for (int i = 0; i < 13; i++) {
        for (int j = 0; j < 4; j++) {
            Card c(cardValue(i + 1), cardPic(j + 1));
            newDeck.push_back(c);
        }
    }
    Game::setDeck(newDeck);
}

/**
 * @return player1 reference
 */
const Player &Game::getP1() const {
    return player1;
}

/**
 * @return player2 reference
 */
const Player &Game::getP2() const {
    return player2;
}

/**
 * @return the game's deck
 */
const vector<Card> &Game::getDeck() const {
    return deck;
}

/**
 * sets a new deck for the game
 * @param newDeck
 */
void Game::setDeck(const vector<Card> &newDeck) {
    Game::deck = newDeck;
}

/**
 * Shuffles a deck randomly using the built in c++ functions
 * @param deckToShuffle
 */
void Game::shuffleDeck(vector<Card> &deckToShuffle) {
    random_device rand;
    mt19937 g(rand());// random number generator
    shuffle(deckToShuffle.begin(), deckToShuffle.end(), g);
}

/**
 * check both players card at the top of the deck (back) and compare it
 * builds a log of what happen and insert it into the turns vector
 * @return the state of who won this turn
 */
whoWins Game::checkTurn() {
    string res;
    whoWins turnWinner = this->player1.getDeck().back().compare(player2.getDeck().back());
    if (turnWinner == Player1Win)
        res = this->player1.getName() + " wins";
    else if (turnWinner == Player2Win)
        res = this->player2.getName() + " wins";
    else res = "Draw. ";
    string lastTurn = this->player1.getName() + " played " + this->player1.getDeck().back().toString() +
                      this->player2.getName() + " played " + this->player2.getDeck().back().toString() + ". " + res;
    this->turns.push_back(lastTurn);
    return turnWinner;
}

/**
 * Check who is the winner of the game
 * clear both decks in case the last turn ended in a Tie
 */
void Game::determineWinner() {
    player1.clearDeck();
    player2.clearDeck();
    if (this->player1.cardesTaken() > this->player2.cardesTaken()) this->winner = Player1Win;
    else if (this->player1.cardesTaken() < this->player2.cardesTaken()) this->winner = Player2Win;
    else this->winner = Draw;
}
