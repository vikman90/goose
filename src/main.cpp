// Copyright 2023 Vikman Fernandez-Castro
// April 9, 2023

#include "board.hpp"
#include <chrono>
#include <cstdlib>
#include <iostream>

#define DEFAULT_PLAYERS 2
#define DEFAULT_GAMES 1

using namespace std;
using namespace std::chrono;

int main(int argc, char **argv) {
    auto players = argc > 1 ? strtoul(argv[1], nullptr, 10) : DEFAULT_PLAYERS;
    auto games = argc > 2 ? strtoul(argv[2], nullptr, 10) : DEFAULT_GAMES;
    auto board = Board(players);

    cout << "Players: " << players << endl;

    auto start = high_resolution_clock::now();

    for (auto i = 1ul; i <= games; i++) {
        cout << "\nGame: " << i
             << "\n════════════════════════════════════════════════════════════"
                "════";

        board.reset();
        auto winner = board.playGame();

        cout << "\n════════════════════════════════════════════════════════════"
                "════\nWinner: Player "
             << winner << endl;
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cerr << "\nTime: " << duration.count() / 1000. << " ms.\n";

    return EXIT_SUCCESS;
}
