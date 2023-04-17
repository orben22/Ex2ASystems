//
// Created by or on 3/23/23.
//
#include "sources/player.hpp"
#include "sources/game.hpp"
#include "doctest.h"

using namespace ariel;

TEST_CASE("Before the game started") {
    Player p1("Alice");
    Player p2("Bob");
    Game game1(p1, p1);
    CHECK_THROWS(game1.playTurn());
    Game game(p1, p2);
    CHECK_THROWS(game.printLastTurn());
    CHECK_NOTHROW(game.printWiner());
    CHECK_THROWS(game.printLog());
    CHECK_NOTHROW(game.printStats());
    CHECK(((p1.stacksize() == 26) && (p2.stacksize() == 26)));
    CHECK(((p1.cardesTaken() == 0) && (p2.cardesTaken() == 0)));
    CHECK_NOTHROW(game.playTurn());
}

TEST_CASE("During the game") {
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    CHECK_THROWS(game.printLog());
    game.playTurn();
    CHECK_NOTHROW(game.printWiner());
    CHECK_NOTHROW(game.printLastTurn());
    CHECK(((p1.cardesTaken() > 0) || (p2.cardesTaken() > 0)));
    CHECK(((p1.stacksize() < 26) && (p2.stacksize() < 26)));
    int x1 = p1.stacksize();
    int x2 = p2.stacksize();
    game.playTurn();
    CHECK(((x1 > p1.stacksize()) && (x2 > p2.stacksize())));
    CHECK_NOTHROW(game.printStats());
    CHECK_NOTHROW(game.playTurn());
    CHECK_NOTHROW(game.playAll());
}

TEST_CASE("After the game finished") {
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    game.playAll();
    CHECK_THROWS(game.playTurn());
    CHECK_THROWS(game.playAll());
    CHECK(((p1.stacksize() == 0) && (p2.stacksize() == 0)));
    CHECK(((p1.cardesTaken() <= 52) && (p2.cardesTaken() <= 52) && (p1.cardesTaken() >= 0) && (p2.cardesTaken() >= 0)));
    CHECK_NOTHROW((game.printWiner()));
    CHECK_NOTHROW((game.printLastTurn()));
    CHECK_NOTHROW((game.printStats()));
    CHECK_NOTHROW((game.printLog()));
}