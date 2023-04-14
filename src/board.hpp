// Copyright 2023 Vikman Fernandez-Castro
// April 9, 2023

#pragma once

#include "player.hpp"
#include <vector>

class Board {
  public:
    Board(unsigned nPlayers);
    unsigned playGame();
    void releaseFromWell();
    void reset();

    const unsigned &activePlayers;

  private:
    std::vector<Player> _players;
    unsigned _activePlayers;
};
