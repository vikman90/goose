# The Game of the Goose

[![Build](https://github.com/vikman90/goose/actions/workflows/cmake.yml/badge.svg)](https://github.com/vikman90/goose/actions/workflows/cmake.yml)

This project is an implementation of the [Game of the Goose](https://en.wikipedia.org/wiki/Game_of_the_Goose) for N players.

## How to play

```shell
goose [PLAYERS]
```

|Option|Description|Range|Default|
|---|---|---|---|
|`PLAYERS`|Number of players|0 < `PLAYERS` ≤ 4294967295|2|

<details><summary><h3>Gameplay example</h3></summary>

```shell
goose-game 3
```

```
Players: 3
[P1] 4: 1 → 5: From goose to goose, faster than a moose → 9 (↵)
[P1] 4: 9 → 13
[P2] 2: 1 → 3
[P3] 4: 1 → 5: From goose to goose, faster than a moose → 9 (↵)
[P3] 1: 9 → 10
[P1] 5: 13 → 18: From goose to goose, faster than a moose → 23 (↵)
[P1] 6: 23 → 29
[P2] 5: 3 → 8
[P3] 4: 10 → 14: From goose to goose, faster than a moose → 18 (↵)
[P3] 6: 18 → 24
[P1] 3: 29 → 32: From goose to goose, faster than a moose → 36 (↵)
[P1] 3: 36 → 39
[P2] 2: 8 → 10
[P3] 2: 24 → 26: From dice to dice, I roll to win the prize → 53 (↵)
[P3] 5: 53 → 58: The death → 1
[P1] 6: 39 → 45: From goose to goose, faster than a moose → 50 (↵)
[P1] 3: 50 → 53: From dice to dice, I roll to win the prize → 26 (↵)
[P1] 4: 26 → 30
[P2] 4: 10 → 14: From goose to goose, faster than a moose → 18 (↵)
[P2] 6: 18 → 24
[P3] 6: 1 → 7
[P1] 4: 30 → 34
[P2] 6: 24 → 30
[P3] 6: 7 → 13
[P1] 2: 34 → 36: From goose to goose, faster than a moose → 41 (↵)
[P1] 4: 41 → 45: From goose to goose, faster than a moose → 50 (↵)
[P1] 2: 50 → 52: The prison: Stay for three turns
[P2] 5: 30 → 35
[P3] 3: 13 → 16
[P1] -: 52: Hold on (3)
[P2] 2: 35 → 37
[P3] 2: 16 → 18: From goose to goose, faster than a moose → 23 (↵)
[P3] 5: 23 → 28
[P1] -: 52: Hold on (2)
[P2] 5: 37 → 42: Lost in the Maze → 30
[P3] 3: 28 → 31: The well: Stay for two turns
[P1] -: 52: Hold on (1)
[P2] 1: 30 → 31: The well: Stay for two turns
    [P3] Released
[P3] 1: 31 → 32: From goose to goose, faster than a moose → 36 (↵)
[P3] 4: 36 → 40
[P1] 5: 52 → 57
[P2] -: 31: Hold on (2)
[P3] 3: 40 → 43
[P1] 3: 57 → 60
[P2] -: 31: Hold on (1)
[P3] 2: 43 → 45: From goose to goose, faster than a moose → 50 (↵)
[P3] 6: 50 → 56
[P1] 2: 60 → 62
[P2] 5: 31 → 36: From goose to goose, faster than a moose → 41 (↵)
[P2] 6: 41 → 47
[P3] 2: 56 → 58: The death → 1
[P1] 2: 62 → 62
[P2] 3: 47 → 50: From goose to goose, faster than a moose → 54 (↵)
[P2] 1: 54 → 55
[P3] 5: 1 → 6: From bridge to bridge, I roll as I reach → 12 (↵)
[P3] 6: 12 → 18: From goose to goose, faster than a moose → 23 (↵)
[P3] 3: 23 → 26: From dice to dice, I roll to win the prize → 53 (↵)
[P3] 3: 53 → 56
[P1] 1: 62 → 63: End ──────────────────────────────────────────
[P2] 5: 55 → 60
[P3] 5: 56 → 61
[P2] 2: 60 → 62
[P3] 5: 61 → 60
[P2] 1: 62 → 63: End ──────────────────────────────────────────
[P3] 2: 60 → 62
[P3] 1: 62 → 63: End ──────────────────────────────────────────
════════════════════════════════════════════════════════════════
Winner: Player 1
Time: 0.022 ms.
```

</details>

### Output format

> [P1] 2: 7 → 9: From goose to goose, faster than a moose → 14 (↵)

|Part|Explanation|
|---|---|
|_[P1]_|Turn for player 1|
|_2_|The die roll was 2|
|_7 → 9_|The piece moves from square 7 to 9 (7+2)|
|_From goose to goose, faster than a moose → 14_|Move the piece to square 14|
|_(↵)_|Roll again|

## Setup

### Requirements

- C++ compiler (gcc or clang)
- CMake 3.22 or above

#### Setup on Ubuntu 22.04

```shell
sudo apt install -y clang cmake
```

### Build

```shell
cmake -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build
```

### Install

```shell
sudo cmake --install build
```

### Uninstall

```shell
sudo xargs rm -v < build/install_manifest.txt
```

## License

Copyright © 2023 Vikman Fernandez-Castro.

Distributed under the [MIT License](LICENSE).
