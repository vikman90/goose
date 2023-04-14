// Copyright 2023 Vikman Fernandez-Castro
// April 9, 2023

#pragma once

#include <random>

class Board;

class Player {
  public:
    Player(unsigned number, Board &board);
    Player(const Player &other);
    bool playTurn();
    void release();
    void reset();

    unsigned number;
    const unsigned &square;
    const bool &finished;

  private:
    void rollDice();
    bool goose();
    bool bridge();
    bool hotel();
    bool well();
    bool dice();
    bool maze();
    bool prison();
    bool death();
    bool end();

    unsigned _square = 1;
    unsigned _stayTurns = 0;
    bool _finished = false;
    Board &_board;

    static std::mt19937 generator;
    static std::uniform_int_distribution<> distribution;
};
