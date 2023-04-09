// Copyright 2023 Vikman Fernandez-Castro
// April 9, 2023

#include "board.hpp"

using namespace std;

Board::Board(unsigned nPlayers) : _players(vector<Player>(nPlayers)) {
    for (auto i = 0u; i < nPlayers; i++) {
        _players[i].number = i + 1;
    }
}

unsigned Board::playGame() {
    auto winner = 0u;
    bool gameOver;

    do {
        gameOver = true;

        for (auto it = _players.begin(); it != _players.end(); ++it) {
            auto &player = *it;

            if (player.finished) {
                continue;
            }

            while (player.playTurn()) {
                continue;
            }

            if (player.finished && winner == 0) {
                winner = player.number;
            }

            gameOver = false;
        }
    } while (!gameOver);

    return winner;
}
