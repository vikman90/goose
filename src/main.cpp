// Copyright 2023 Vikman Fernandez-Castro
// April 9, 2023

#include "board.hpp"
#include <chrono>
#include <cstdlib>
#include <iostream>

#define DEFAULT_PLAYERS 2

using namespace std;
using namespace std::chrono;

int main(int argc, char **argv) {
    auto players = argc > 1 ? strtoul(argv[1], nullptr, 10) : DEFAULT_PLAYERS;
    auto board = Board(players);

    cout << "Players: " << players;

    auto start = high_resolution_clock::now();
    auto winner = board.playGame();
    auto stop = high_resolution_clock::now();

    cout << "\n════════════════════════════════════════════════════════════════"
         << "\nWinner: Player " << winner << endl;

    auto duration = duration_cast<microseconds>(stop - start);
    cerr << "Time: " << duration.count() / 1000. << " ms.\n";

    return EXIT_SUCCESS;
}
