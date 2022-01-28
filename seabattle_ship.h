//
// Created by anton on 02.03.2020.
//

#ifndef SEABATTLE_SEABATTLE_SHIP_H
#define SEABATTLE_SEABATTLE_SHIP_H

typedef struct tagDocks
{
    int pos_x;
    int pos_y;
}Docks;  // Структура координат доков

typedef struct tagShip
{
    int isAlive;
    int size;
    int laydown;

    Docks begin_pos;

}Ship;

char **drawShip(char **game_field, int pos_x, int pos_y, int laydown, Ship current_ship);
char **strikeShipDraw(char **back_game_field, char **game_field, int pos_x, int pos_y);

// Проверки на ввод координат
int isOK_in_init(char **game_field, int pos_x, int pos_y,int laydown, Ship current_ship);
int isContinue(char **back_game_field, int pos_x, int pos_y);
int sideChek(char **game_field, int pos_x, int pos_y, int layout, Ship current_ship); // Проверят поля вокруг ( под вопросом )

//Проверки кораблей
int chekShip(char **game_field, Ship current_ship, char type);
char **drawDeadShip(char **game_field, Ship current_ship);


void TESTERS_CONFIG_SHIP(Ship current_ship); // TEST TOOLS

#endif //SEABATTLE_SEABATTLE_SHIP_H
