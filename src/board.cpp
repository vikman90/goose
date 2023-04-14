// Copyright 2023 Vikman Fernandez-Castro
// April 9, 2023

#include "board.hpp"

using namespace std;

Board::Board(unsigned nPlayers)
    : activePlayers(_activePlayers), _activePlayers(nPlayers) {
    for (auto i = 0u; i < nPlayers; i++) {
        _players.push_back(Player(i + 1, *this));
    }
}

unsigned Board::playGame() {
    auto winner = 0u;
    bool gameOver;

    while (_activePlayers > 0) {
        for (auto it = _players.begin(); it != _players.end(); ++it) {
            auto &player = *it;

            if (player.finished) {
                continue;
            }

            while (player.playTurn()) {
                continue;
            }

            if (player.finished) {
                if (winner == 0) {
                    winner = player.number;
                }

                _activePlayers--;
            }
        }
    };

    return winner;
}

void Board::releaseFromWell() {
    for (auto player = _players.begin(); player != _players.end(); ++player) {
        if (player->square == 31) {
            player->release();
        }
    }
}

void Board::reset() {
    for (auto player = _players.begin(); player != _players.end(); ++player) {
        player->reset();
    }

    _activePlayers = _players.size();
}
