//
// Created by anton on 02.03.2020.
//

#include "display_game.h"
#include "seabattle_ship.h"

void drawFirstScreen()
{
    printf("____________________________####____________________\n"
           "_____________________###______##____####____________\n"
           "____________________########_____#____##____________\n"
           "__________________##_____##______#_#_____#__________\n"
           "_______________#####____###____####_____##__________\n"
           "_____________##__#########################__________\n"
           "__________###_#_##_______##______#_______#__####____\n"
           "_________##_#__##________#_______#_______#____#_____\n"
           "_______##__#__#_#_______#####__####_____###____#____\n"
           "_____##__#___#_##_______################_#_____#____\n"
           "____#___#___#_##_________#_______#_______#______#___\n"
           "__##########__#_______####_______#_______#_______#__\n"
           "________####__#_##########_____####____###_______##_\n"
           "______________###################################___\n"
           "_______________################################_____\n"
           "____________________________________________________\n"
           "____________________SEA BATTLE v0.1_________________\n");

    getchar();
    system("cls");
}

// BLOCK OF CREATION
char **createGameField(int size)
{
    char **game_field = (char **)malloc(sizeof(char *) * size);
    for (int i = 0; i < size; ++i)
    {
        game_field[i] = (char *)malloc(sizeof(char) * size);
    }

    game_field[0][0] = ' ';

    int ASCII_letters = 48;
    for (int i = 1; i < size - 1; ++i)
    {
        game_field[0][i] = (char)ASCII_letters;
        ASCII_letters = ASCII_letters + 1;
    }

    ASCII_letters = 48;
    for (int i = 1; i < size - 1; ++i)
    {
        game_field[i][0] = (char)ASCII_letters;
        ASCII_letters = ASCII_letters + 1;
    }

    for (int i = 1; i < size - 1; ++i)
    {
        for (int j = 1; j < size - 1; ++j)
        {
            game_field[i][j] = ' ';
        }
    }

    for (int i = 0; i < 12; ++i)
    {
        game_field[11][i] = ' ';
    }

    for (int i = 0; i < 12; ++i)
    {
        game_field[i][11] = ' ';
    }
    
    return game_field;
}

void deleteGameField(char **game_field)
{
    for (int i = 0; i < 12; i++)
    {
        free(game_field[i]);
    }
    free(game_field);
}

//BLOCK OF PRINTING
void displayField(char **game_field, char **enemies_field)
{
    game_field[0][0] = ' ';

    int ASCII_letters = 48;
    for (int i = 1; i < 12 - 1; ++i)
    {
        game_field[0][i] = (char)ASCII_letters;
        ASCII_letters = ASCII_letters + 1;
    }

    ASCII_letters = 48;
    for (int i = 1; i < 12 - 1; ++i)
    {
        game_field[i][0] = (char)ASCII_letters;
        ASCII_letters = ASCII_letters + 1;
    }

    for (int i = 0; i < 12; ++i)
    {
        game_field[11][i] = ' ';
    }

    for (int i = 0; i < 12; ++i)
    {
        game_field[i][11] = ' ';
    }

    enemies_field[0][0] = ' ';

    ASCII_letters = 48;
    for (int i = 1; i < 12 - 1; ++i)
    {
        enemies_field[0][i] = (char)ASCII_letters;
        ASCII_letters = ASCII_letters + 1;
    }

    ASCII_letters = 48;
    for (int i = 1; i < 12 - 1; ++i)
    {
        enemies_field[i][0] = (char)ASCII_letters;
        ASCII_letters = ASCII_letters + 1;
    }

    for (int i = 0; i < 12; ++i)
    {
        enemies_field[11][i] = ' ';
    }

    for (int i = 0; i < 12; ++i)
    {
        enemies_field[i][11] = ' ';
    }

    for (int i = 0; i < 12; ++i)
    {
        for (int j = 0; j < 12; ++j)
        {
            printf("%c ", game_field[i][j]);
        }

        printf(" ");
        for (int j = 0; j < 12; ++j)
        {
            printf("%c ", enemies_field[i][j]);
        }


        printf("\n");
    }
}

void displayScores(int pl, int en)
{
    printf("PLAYER:%d | ENEMY:%d\n", pl, en);
}