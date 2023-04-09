// Copyright 2023 Vikman Fernandez-Castro
// April 9, 2023

#pragma once

#include <random>

class Player {
  public:
    Player();
    bool playTurn();

    unsigned number = 0;
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

    static std::mt19937 generator;
    static std::uniform_int_distribution<> distribution;
};
