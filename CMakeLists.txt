cmake_minimum_required(VERSION 3.17)
project(PDCURSES)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(PDCURSES
        game.cpp
        game.h
        main.cpp
        point.cpp
        point.h
        player.cpp
        player.h
        direction.h
        direction.cpp
       )
target_link_libraries( PDCURSES ${PROJECT_SOURCE_DIR}/pdcurses.a)