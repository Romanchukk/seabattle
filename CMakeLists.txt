cmake_minimum_required(VERSION 3.15)
project(SeaBattle C)

set(CMAKE_C_STANDARD 99)

add_executable(SeaBattle main.c display_game.c display_game.h seabattle_ship.c seabattle_ship.h ai_bot.c ai_bot.h)