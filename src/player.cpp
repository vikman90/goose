// Copyright 2023 Vikman Fernandez-Castro
// April 9, 2023

#include "player.hpp"
#include <iostream>

#define DIE_MIN 1
#define DIE_MAX 6

using namespace std;

std::mt19937 Player::generator(random_device{}());
std::uniform_int_distribution<> Player::distribution(DIE_MIN, DIE_MAX);

Player::Player()
    : number(0), finished(_finished), _square(1), _stayTurns(0),
      _finished(false) {}

bool Player::playTurn() {
    if (_stayTurns > 0) {
        cout << "\n[P" << number << "] -: " << _square << ": Hold on ("
             << _stayTurns << ")";
        _stayTurns--;
        return false;
    }

    rollDice();

    switch (_square) {
    case 0:
    case 1:
        cerr << "\nERROR: Player " << number << "went to square " << _square
             << endl;
        abort();
    case 5: return goose();
    case 6: return bridge();
    case 9: return goose();
    case 12: return bridge();
    case 14: return goose();
    case 18: return goose();
    case 19: return hotel();
    case 23: return goose();
    case 26: return dice();
    case 27: return goose();
    case 31: return well();
    case 32: return goose();
    case 36: return goose();
    case 41: return goose();
    case 42: return maze();
    case 45: return goose();
    case 50: return goose();
    case 52: return prison();
    case 53: return dice();
    case 54: return goose();
    case 58: return death();
    case 59: return goose();
    case 63: return end();
    default: return false;
    }
}

void Player::rollDice() {
    auto roll = distribution(generator);
    auto next = _square + roll;
    next = next > 63 ? 126 - next : next;

    cout << "\n[P" << number << "] " << roll << ": " << _square << " → "
         << next;

    _square = next;
}

bool Player::goose() {
    cout << ": From goose to goose, faster than a moose";

    switch (_square) {
    case 1: _square = 5; break;
    case 5: _square = 9; break;
    case 9: _square = 14; break;
    case 14: _square = 18; break;
    case 18: _square = 23; break;
    case 23: _square = 27; break;
    case 27: _square = 32; break;
    case 32: _square = 36; break;
    case 36: _square = 41; break;
    case 41: _square = 45; break;
    case 45: _square = 50; break;
    case 50: _square = 54; break;
    case 54: _square = 59; break;
    case 59: _square = 63; break;
    default: cerr << "\nERROR: The player is not in a goose square.\n"; abort();
    }

    cout << " → " << _square << " (↵)";
    return true;
}

bool Player::bridge() {
    cout << ": From bridge to bridge, I roll as I reach";

    switch (_square) {
    case 6: _square = 12; break;
    case 12: _square = 6; break;
    default:
        cerr << "\nERROR: The player is not in a bridge square.\n";
        abort();
    }

    cout << " → " << _square << " (↵)";
    return true;
}

bool Player::hotel() {
    cout << ": The hotel: Stay for one turn";
    _stayTurns = 1;

    return false;
}

bool Player::well() {
    cout << ": The well: Stay for two turns";
    _stayTurns = 2;
    return false;
}

bool Player::dice() {
    cout << ": From dice to dice, I roll to win the prize";

    switch (_square) {
    case 26: _square = 53; break;
    case 53: _square = 26; break;
    default: cerr << "\nERROR: The player is not in a dice square.\n"; abort();
    }

    cout << " → " << _square << " (↵)";
    return true;
}

bool Player::maze() {
    cout << ": Lost in the Maze → 30";
    _square = 30;
    return false;
}

bool Player::prison() {
    cout << ": The prison: Stay for three turns";
    _stayTurns = 3;
    return false;
}

bool Player::death() {
    cout << ": The death → 1";
    _square = 1;

    return false;
}

bool Player::end() {
    cout << ": End ──────────────────────────────────────────";
    _finished = true;

    return false;
}
