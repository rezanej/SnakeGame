cmake_minimum_required(VERSION 3.17)
project(SNAKE_GAME)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(SNAKE_GAME
        game.cpp
        game.h
        main.cpp
        point.cpp
        point.h
        player.cpp
        player.h
        direction.h
        direction.cpp
        goal.cpp
        goal.h
        score.cpp
        score.h
        gameover.cpp
        gameover.h
       )
target_link_libraries( SNAKE_GAME ${PROJECT_SOURCE_DIR}/pdcurses.a)