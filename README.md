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
[P1] 6: 1 → 7
[P2] 6: 1 → 7
[P3] 2: 1 → 3
[P1] 2: 7 → 9: From goose to goose, faster than a moose → 14 (↵)
[P1] 6: 14 → 20
[P2] 3: 7 → 10
[P3] 1: 3 → 4
[P1] 5: 20 → 25
[P2] 2: 10 → 12: From bridge to bridge, I roll as I reach → 6 (↵)
[P2] 1: 6 → 7
[P3] 4: 4 → 8
[P1] 4: 25 → 29
[P2] 4: 7 → 11
[P3] 4: 8 → 12: From bridge to bridge, I roll as I reach → 6 (↵)
[P3] 4: 6 → 10
[P1] 5: 29 → 34
[P2] 3: 11 → 14: From goose to goose, faster than a moose → 18 (↵)
[P2] 6: 18 → 24
[P3] 4: 10 → 14: From goose to goose, faster than a moose → 18 (↵)
[P3] 5: 18 → 23: From goose to goose, faster than a moose → 27 (↵)
[P3] 1: 27 → 28
[P1] 5: 34 → 39
[P2] 5: 24 → 29
[P3] 4: 28 → 32: From goose to goose, faster than a moose → 36 (↵)
[P3] 4: 36 → 40
[P1] 5: 39 → 44
[P2] 5: 29 → 34
[P3] 1: 40 → 41: From goose to goose, faster than a moose → 45 (↵)
[P3] 3: 45 → 48
[P1] 2: 44 → 46
[P2] 2: 34 → 36: From goose to goose, faster than a moose → 41 (↵)
[P2] 2: 41 → 43
[P3] 6: 48 → 54: From goose to goose, faster than a moose → 59 (↵)
[P3] 4: 59 → 63: End ──────────────────────────────────────────
[P1] 5: 46 → 51
[P2] 1: 43 → 44
[P1] 6: 51 → 57
[P2] 6: 44 → 50: From goose to goose, faster than a moose → 54 (↵)
[P2] 5: 54 → 59: From goose to goose, faster than a moose → 63 (↵)
[P2] 6: 63 → 57
[P1] 5: 57 → 62
[P2] 3: 57 → 60
[P1] 3: 62 → 61
[P2] 6: 60 → 60
[P1] 1: 61 → 62
[P2] 6: 60 → 60
[P1] 3: 62 → 61
[P2] 2: 60 → 62
[P1] 1: 61 → 62
[P2] 1: 62 → 63: End ──────────────────────────────────────────
[P1] 5: 62 → 59: From goose to goose, faster than a moose → 63 (↵)
[P1] 3: 63 → 60
[P1] 3: 60 → 63: End ──────────────────────────────────────────
════════════════════════════════════════════════════════════════
Winner: Player 3
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
