//
// Created by anton on 02.03.2020.
//

#include "seabattle_ship.h"
#include "display_game.h"
char **drawShip(char **game_field, int pos_x, int pos_y, int laydown, Ship current_ship)
{
    if (laydown == 1)
    {
        while (pos_x + current_ship.size > 10)
        {
            pos_x--;
        }

        for (int i = 0; i < current_ship.size; ++i)
        {
            game_field[pos_x + 1][pos_y + 1] = '#';
            pos_x++;
        }
    } else
    {
        while (pos_y + current_ship.size > 10)
        {
            pos_y--;
        }

        for (int i = 0; i < current_ship.size; ++i)
        {
            game_field[pos_x + 1][pos_y + 1] = '#';
            pos_y++;
        }
    }

    return game_field;
}

int sideChek(char **game_field, int pos_x, int pos_y, int layout, Ship current_ship)
{
    int isClear = 0;
    if (layout != 1)
    {
        if (game_field[pos_x][pos_y] != '#' && game_field[pos_x + 1][pos_y] != '#' && game_field[pos_x + 2][pos_y] != '#')
        {
            isClear = 0;
        }
        else
        {
            isClear = 1;
            return isClear;
        }

        for (int i = 0; i < current_ship.size; ++i)
        {
            if(game_field[pos_x][pos_y + 1] != '#' && game_field[pos_x + 2][pos_y + 1] != '#')
            {
                isClear = 0;
                pos_y++;
            } else
            {
                isClear = 1;
                break;
            }
        }

        if (isClear == 1)
        {
            return isClear;
        }

        if (pos_y < 11)
        {
            if (game_field[pos_x][pos_y + 1] != '#' && game_field[pos_x + 1][pos_y + 1]!= '#'
                && game_field[pos_x + 2][pos_y + 1] != '#')
            {
                isClear = 0;
            }
            else
            {
                isClear = 1;
                return isClear;
            }
        }
    }
    else
    {
        if (game_field[pos_x][pos_y] != '#' && game_field[pos_x][pos_y + 1] != '#'
            && game_field[pos_x][pos_y + 2] != '#')
        {
            isClear = 0;
        }
        else
        {
            isClear = 1;
            return isClear;
        }

        for (int i = 0; i < current_ship.size; ++i)
        {
            if(game_field[pos_x + 1][pos_y] != '#' && game_field[pos_x + 1][pos_y + 2] != '#')
            {
                isClear = 0;
                pos_x++;
            } else
            {
                isClear = 1;
                break;
            }
        }

        if (isClear == 1)
        {
            return 1;
        }

        if (pos_x < 11)
        {
            if (game_field[pos_x + 1][pos_y] != '#' && game_field[pos_x + 1][pos_y + 1] != '#'
                && game_field[pos_x + 1][pos_y + 2] != '#')
            {
                isClear = 0;
            }
            else
            {
                isClear = 1;
                return isClear;
            }
        }
    }

    return isClear;
}


int isOK_in_init(char **game_field, int pos_x, int pos_y,int laydown, Ship current_ship)
{
    int isHashHere = 0;

    if (laydown == 1)
    {
        while (pos_x + current_ship.size > 10)
        {
            pos_x--;
        }

        isHashHere = sideChek(game_field, pos_x, pos_y, laydown, current_ship);

        for (int i = 0; i < current_ship.size; ++i)
        {
            if (game_field[pos_x + 1][pos_y + 1] == '#')
            {
                isHashHere = 1;
            }
            pos_x++;
        }

    } else {
        while (pos_y + current_ship.size > 10) {
            pos_y--;
        }

        isHashHere = sideChek(game_field, pos_x, pos_y, laydown, current_ship);

        for (int i = 0; i < current_ship.size; ++i) {
            if (game_field[pos_x + 1][pos_y + 1] == '#') {
                isHashHere = 1;
            }
            pos_y++;
        }
    }
    if (isHashHere == 1)
    {
        return 1;
    } else
    {
        return 0;
    }
}

char **strikeShipDraw(char **back_game_field, char **game_field, int pos_x, int pos_y)
{
    if (back_game_field[pos_x + 1][pos_y + 1] == '#' || back_game_field[pos_x + 1][pos_y + 1] == '>'
        || back_game_field[pos_x + 1][pos_y + 1] == 'V')
    {
        game_field[pos_x + 1][pos_y + 1] = '*';
    } else if (back_game_field[pos_x + 1][pos_y + 1] != '*')
    {
        game_field[pos_x + 1][pos_y + 1] = '.';
    }

    return game_field;
}

char **drawDeadShip(char **game_field, Ship current_ship)
{
    int pos_x = current_ship.begin_pos.pos_x;
    int pos_y = current_ship.begin_pos.pos_y;

    if (current_ship.laydown == 1)
    {
        game_field[pos_x][pos_y] = '.';
        game_field[pos_x][pos_y + 1] = '.';
        game_field[pos_x][pos_y + 2] = '.';

        for (int i = 0; i < current_ship.size; ++i)
        {
            game_field[pos_x + 1][pos_y] = '.';
            game_field[pos_x + 1][pos_y + 2] = '.';

            pos_x++;
        }

        game_field[pos_x + 1][pos_y] = '.';
        game_field[pos_x + 1][pos_y + 1] = '.';
        game_field[pos_x + 1][pos_x + 2] = '.';
    }
    else
    {
        game_field[pos_x][pos_y] = '.';
        game_field[pos_x + 1][pos_y] = '.';
        game_field[pos_x + 2][pos_y] = '.';

        for (int i = 0; i < current_ship.size; ++i)
        {
            game_field[pos_x][pos_y + 1] = '.';
            game_field[pos_x + 2][pos_y + 1] = '.';

            pos_y++;
        }

        game_field[pos_x][pos_y + 1] = '.';
        game_field[pos_x + 1][pos_y + 1] = '.';
        game_field[pos_x + 2][pos_y + 1] = '.';
    }

    return game_field;
}

int isContinue(char **back_game_field, int pos_x, int pos_y)
{
    int isTrue = 0;
    if (back_game_field[pos_x + 1][pos_y + 1] == '#')
    {
        isTrue = 1;
    }

    return isTrue;
}

int chekShip(char **game_field, Ship current_ship, char type)
{
    if (current_ship.isAlive != 0)
    {
        int pos_x = current_ship.begin_pos.pos_x;
        int pos_y = current_ship.begin_pos.pos_y;

        int rezult = 0;

        if (current_ship.laydown == 1 )
        {
            for (int i = 0; i < current_ship.size; ++i)
            {
                if(game_field[pos_x + 1][pos_y + 1] == type)
                {
                    rezult = 1;
                    break;
                } else
                {
                    pos_x++;
                }
            }
        } else
        {
            for (int i = 0; i < current_ship.size; ++i)
            {
                if(game_field[pos_x + 1][pos_y + 1] == type)
                {
                    rezult = 1;
                    break;
                } else
                {
                    pos_y++;
                }
            }
        }

        return rezult;
    }
    else
    {
        return current_ship.isAlive;
    }
}

void TESTERS_CONFIG_SHIP(Ship current_ship)
{
    printf("IS ALIVE:%d\nSIZE:%d\nLAYDOWN:%d\n", current_ship.isAlive, current_ship.size, current_ship.laydown);
    printf("X:%d Y:%d", current_ship.begin_pos.pos_x, current_ship.begin_pos.pos_y);
}