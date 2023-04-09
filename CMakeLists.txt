cmake_minimum_required(VERSION 3.22)

project(Goose CXX)

add_executable(goose-game
    src/board.cpp
    src/main.cpp
    src/player.cpp
)

install(TARGETS goose-game DESTINATION bin)
