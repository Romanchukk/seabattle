//
// Created by anton on 02.03.2020.
//

#ifndef SEABATTLE_DISPLAY_GAME_H
#define SEABATTLE_DISPLAY_GAME_H

#include <stdio.h>
#include <stdlib.h>

char **createGameField(int size);
void deleteGameField(char **game_field);

void displayField(char **game_field, char **enemies_field);
void displayScores(int pl, int en);
void drawFirstScreen();

#endif //SEABATTLE_DISPLAY_GAME_H
