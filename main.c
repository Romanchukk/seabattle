#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "display_game.h"
#include "seabattle_ship.h"

#define SIZE_FIELD 12

int main()
{
    srand(time(NULL));

    Ship player_FD_ship;
    player_FD_ship.isAlive = 1;
    player_FD_ship.size = 4;

    Ship player_TD_ship[2];
    for (int i = 0; i < 2; ++i)
    {
        player_TD_ship[i].isAlive = 1;
        player_TD_ship[i].size = 3;
    }
    Ship player_TWD_ship[3];
    for (int i = 0; i < 3; ++i)
    {
        player_TWD_ship[i].isAlive = 1;
        player_TWD_ship[i].size = 2;
    }

    Ship player_OD_ship[4];
    for (int i = 0; i < 4; ++i)
    {
        player_OD_ship[i].isAlive = 1;
        player_OD_ship[i].size = 1;
    }

    Ship enemies_FD_ship;
    enemies_FD_ship.isAlive = 1;
    enemies_FD_ship.size = 4;

    Ship enemies_TD_ship[2];
    for (int i = 0; i < 2; ++i)
    {
        enemies_TD_ship[i].isAlive = 1;
        enemies_TD_ship[i].size = 3;
    }
    Ship enemies_TWD_ship[3];
    for (int i = 0; i < 3; ++i)
    {
        enemies_TWD_ship[i].isAlive = 1;
        enemies_TWD_ship[i].size = 2;
    }

    Ship enemies_OD_ship[4];
    for (int i = 0; i < 4; ++i)
    {
        enemies_OD_ship[i].isAlive = 1;
        enemies_OD_ship[i].size = 1;
    }

    //creation
    char **players_filed = createGameField(SIZE_FIELD);
    char **enemies_field = createGameField(SIZE_FIELD);
    char **back_enemies_field = createGameField(SIZE_FIELD);

    int coordinates_pos_x = 0;
    int coordinates_pos_y = 0;
    int laydown_pos = 0;

    drawFirstScreen();

    displayField(players_filed, enemies_field);

    // GAME BEGIN
    printf("CONSOLE:\n select position to your ships\n you have:\n #### - 1\n ### - 2\n ## - 3\n # - 4\n");

    getchar();
    system("cls");

    displayField(players_filed, enemies_field);

    printf("Place your four-dock ship ( ENTER BEGIN COORDINATES, AND LAYDOWN)\n");
    printf("x->");
    scanf("%d", &coordinates_pos_x);
    while (coordinates_pos_x > 9 || coordinates_pos_x < 0)
    {
        printf("TRY AGAIN! x->");
        scanf("%d", &coordinates_pos_x);
    }
    printf("y->");
    scanf("%d", &coordinates_pos_y);
    while (coordinates_pos_y > 9 || coordinates_pos_y < 0)
    {
        printf("TRY AGAIN! y->");
        scanf("%d", &coordinates_pos_y);
    }
    printf("laydownd 1 - vertical, 0 - horizontal ->");
    scanf("%d", &laydown_pos);

    player_FD_ship.laydown = laydown_pos;
    player_FD_ship.begin_pos.pos_x = coordinates_pos_x;
    player_FD_ship.begin_pos.pos_y = coordinates_pos_y;

    //creation of 4docks ship ( PLAYER )
    players_filed = drawShip(players_filed, coordinates_pos_x, coordinates_pos_y, laydown_pos, player_FD_ship);
    system("cls");
    displayField(players_filed, enemies_field);

    for (int i = 0; i < 2; ++i)
    {
        printf("Place your three-dock ship ( ENTER BEGIN COORDINATES, AND LAYDOWN)\n");
        printf("x->");
        scanf("%d", &coordinates_pos_x);
        while (coordinates_pos_x > 9 || coordinates_pos_x < 0)
        {
            printf("TRY AGAIN! x->");
            scanf("%d", &coordinates_pos_x);
        }
        printf("y->");
        scanf("%d", &coordinates_pos_y);
        while (coordinates_pos_y > 9 || coordinates_pos_y < 0)
        {
            printf("TRY AGAIN! y->");
            scanf("%d", &coordinates_pos_y);
        }
        printf("laydownd 1 - vertical, 0 - horizontal ->");
        scanf("%d", &laydown_pos);

        while (isOK_in_init(players_filed, coordinates_pos_x, coordinates_pos_y, laydown_pos, player_TD_ship[i]) != 0)
        {
            printf("TRY AGAIN!");
            printf("x->");
            scanf("%d", &coordinates_pos_x);
            while (coordinates_pos_x > 9 || coordinates_pos_x < 0)
            {
                printf("TRY AGAIN! x->");
                scanf("%d", &coordinates_pos_x);
            }
            printf("y->");
            scanf("%d", &coordinates_pos_y);
            while (coordinates_pos_y > 9 || coordinates_pos_y < 0)
            {
                printf("TRY AGAIN! y->");
                scanf("%d", &coordinates_pos_y);
            }
            printf("laydownd 1 - vertical, 0 - horizontal ->");
            scanf("%d", &laydown_pos);
        }

        player_TD_ship[i].begin_pos.pos_x = coordinates_pos_x;
        player_TD_ship[i].begin_pos.pos_y = coordinates_pos_y;
        player_TD_ship[i].laydown = laydown_pos;

        players_filed = drawShip(players_filed, coordinates_pos_x, coordinates_pos_y, laydown_pos, player_TD_ship[i]);

        system("cls");
        displayField(players_filed, enemies_field);
    }

    for (int i = 0; i < 3; ++i) {
        printf("Place your two-dock ship ( ENTER BEGIN COORDINATES, AND LAYDOWN)\n");
        printf("x->");
        scanf("%d", &coordinates_pos_x);
        while (coordinates_pos_x > 9 || coordinates_pos_x < 0) {
            printf("TRY AGAIN! x->");
            scanf("%d", &coordinates_pos_x);
        }
        printf("y->");
        scanf("%d", &coordinates_pos_y);
        while (coordinates_pos_y > 9 || coordinates_pos_y < 0) {
            printf("TRY AGAIN! y->");
            scanf("%d", &coordinates_pos_y);
        }
        printf("laydownd 1 - vertical, 0 - horizontal ->");
        scanf("%d", &laydown_pos);

        while (isOK_in_init(players_filed, coordinates_pos_x, coordinates_pos_y, laydown_pos, player_TWD_ship[i]) != 0)
        {
            printf("TRY AGAIN!");
            printf("x->");
            scanf("%d", &coordinates_pos_x);
            while (coordinates_pos_x > 9 || coordinates_pos_x < 0) {
                printf("TRY AGAIN! x->");
                scanf("%d", &coordinates_pos_x);
            }
            printf("y->");
            scanf("%d", &coordinates_pos_y);
            while (coordinates_pos_y > 9 || coordinates_pos_y < 0) {
                printf("TRY AGAIN! y->");
                scanf("%d", &coordinates_pos_y);
            }
            printf("laydownd 1 - vertical, 0 - horizontal ->");
            scanf("%d", &laydown_pos);
        }

        player_TWD_ship[i].begin_pos.pos_x = coordinates_pos_x;
        player_TWD_ship[i].begin_pos.pos_y = coordinates_pos_y;
        player_TWD_ship[i].laydown = laydown_pos;

        players_filed = drawShip(players_filed, coordinates_pos_x, coordinates_pos_y, laydown_pos, player_TWD_ship[i]);

        system("cls");
        displayField(players_filed, enemies_field);
    }

    for (int i = 0; i < 4; ++i)
    {
        printf("Place your one-dock ship ( ENTER BEGIN COORDINATES, AND LAYDOWN)\n");
        printf("x->");
        scanf("%d", &coordinates_pos_x);
        while (coordinates_pos_x > 9 || coordinates_pos_x < 0)
        {
            printf("TRY AGAIN! x->");
            scanf("%d", &coordinates_pos_x);
        }
        printf("y->");
        scanf("%d", &coordinates_pos_y);
        while (coordinates_pos_y > 9 || coordinates_pos_y < 0)
        {
            printf("TRY AGAIN! y->");
            scanf("%d", &coordinates_pos_y);
        }
        printf("laydownd 1 - vertical, 0 - horizontal ->");
        scanf("%d", &laydown_pos);

        while (isOK_in_init(players_filed, coordinates_pos_x, coordinates_pos_y, laydown_pos, player_OD_ship[i]) != 0)
        {
            printf("TRY AGAIN!");
            printf("x->");
            scanf("%d", &coordinates_pos_x);
            while (coordinates_pos_x > 9 || coordinates_pos_x < 0)
            {
                printf("TRY AGAIN! x->");
                scanf("%d", &coordinates_pos_x);
            }
            printf("y->");
            scanf("%d", &coordinates_pos_y);
            while (coordinates_pos_y > 9 || coordinates_pos_y < 0)
            {
                printf("TRY AGAIN! y->");
                scanf("%d", &coordinates_pos_y);
            }
            printf("laydownd 1 - vertical, 0 - horizontal ->");
            scanf("%d", &laydown_pos);
        }

        player_OD_ship[i].begin_pos.pos_x = coordinates_pos_x;
        player_OD_ship[i].begin_pos.pos_y = coordinates_pos_y;
        player_OD_ship[i].laydown = laydown_pos;

        players_filed = drawShip(players_filed, coordinates_pos_x, coordinates_pos_y, laydown_pos, player_OD_ship[i]);
        system("cls");
        displayField(players_filed, enemies_field);
    }

    printf("YOUR FIELD IS DONE!\n");
    getchar();
    getchar();

    system("cls");
    printf("WAIT STILL ENEMY WILL BE READY...");

    coordinates_pos_x = rand() % 9;
    coordinates_pos_y = rand() % 9;
    laydown_pos = rand() % 1;

    enemies_FD_ship.begin_pos.pos_x = coordinates_pos_x;
    enemies_FD_ship.begin_pos.pos_y = coordinates_pos_y;
    enemies_FD_ship.laydown = laydown_pos;

    back_enemies_field = drawShip(back_enemies_field, coordinates_pos_x, coordinates_pos_y, laydown_pos, enemies_FD_ship);

    for (int i = 0; i < 2; i++)
    {
        coordinates_pos_x = rand() % 9;
        coordinates_pos_y = rand() % 9;
        if (i % 2 == 0)
        {
            laydown_pos = 0;
        } else
        {
            laydown_pos = 1;
        }

        while (isOK_in_init(back_enemies_field, coordinates_pos_x, coordinates_pos_y, laydown_pos, enemies_TD_ship[i]) != 0)
        {
            coordinates_pos_x = rand() % 9;
            coordinates_pos_y = rand() % 9;
        }

        enemies_TD_ship[i].begin_pos.pos_x = coordinates_pos_x;
        enemies_TD_ship[i].begin_pos.pos_y = coordinates_pos_y;
        enemies_TD_ship[i].laydown = laydown_pos;

        back_enemies_field = drawShip(back_enemies_field, coordinates_pos_x, coordinates_pos_y, laydown_pos, enemies_TD_ship[i]);
    }

    for (int i = 0; i < 3; i++)
    {
        coordinates_pos_x = rand() % 9;
        coordinates_pos_y = rand() % 9;
        if (i % 2 == 0)
        {
            laydown_pos = 0;
        } else
        {
            laydown_pos = 1;
        }

        while (isOK_in_init(back_enemies_field, coordinates_pos_x, coordinates_pos_y, laydown_pos, enemies_TWD_ship[i]) != 0)
        {
            coordinates_pos_x = rand() % 9;
            coordinates_pos_y = rand() % 9;
        }

        enemies_TWD_ship[i].begin_pos.pos_x = coordinates_pos_x;
        enemies_TWD_ship[i].begin_pos.pos_y = coordinates_pos_y;
        enemies_TWD_ship[i].laydown = laydown_pos;

        back_enemies_field = drawShip(back_enemies_field, coordinates_pos_x, coordinates_pos_y, laydown_pos, enemies_TWD_ship[i]);
    }

    for (int i = 0; i < 4; i++)
    {
        coordinates_pos_x = rand() % 9;
        coordinates_pos_y = rand() % 9;
        if (i % 2 == 0)
        {
            laydown_pos = 0;
        } else
        {
            laydown_pos = 1;
        }

        while (isOK_in_init(back_enemies_field, coordinates_pos_x, coordinates_pos_y, laydown_pos, enemies_OD_ship[i]) != 0)
        {
            coordinates_pos_x = rand() % 10;
            coordinates_pos_y = rand() % 10;
        }

        enemies_OD_ship[i].begin_pos.pos_x = coordinates_pos_x;
        enemies_OD_ship[i].begin_pos.pos_y = coordinates_pos_y;
        enemies_OD_ship[i].laydown = laydown_pos;

        back_enemies_field = drawShip(back_enemies_field, coordinates_pos_x, coordinates_pos_y, laydown_pos, enemies_OD_ship[i]);
    }

    system("cls");
    displayField(players_filed, enemies_field); // SWAP TO enemies_field! LATER

    getchar();
    getchar();

    int playerRezult = 0;
    int enemyRezult = 0;

    int enemiesScore = 0;
    int playersScore = 0;

    while (playerRezult != 1 || enemyRezult != 1)
    {
        int isShot = 1;
        while (isShot == 1)
        {
            system("cls");
            displayField(players_filed, enemies_field);
            displayScores(playersScore, enemiesScore);

            printf("PLAYER'S TURN\n");
            printf("PEINT COORDS FOR STRIKE ( X AND Y )\n");
            printf("x->");
            scanf("%d", &coordinates_pos_x);
            while (coordinates_pos_x > 9 || coordinates_pos_x < 0)
            {
                printf("TRY AGAIN! x->");
                scanf("%d", &coordinates_pos_x);
            }
            printf("y->");
            scanf("%d", &coordinates_pos_y);
            while (coordinates_pos_y > 9 || coordinates_pos_y < 0)
            {
                printf("TRY AGAIN! y->");
                scanf("%d", &coordinates_pos_y);
            }

            isShot = isContinue(back_enemies_field, coordinates_pos_x, coordinates_pos_y);
            enemies_field = strikeShipDraw(back_enemies_field, enemies_field, coordinates_pos_x, coordinates_pos_y);

            enemies_FD_ship.isAlive = chekShip(enemies_field, enemies_FD_ship, ' ');
            if (enemies_FD_ship.isAlive == 0)
            {
                enemies_field = drawDeadShip(enemies_field, enemies_FD_ship);
            }

            for (int i = 0; i < 2; ++i)
            {
                enemies_TD_ship[i].isAlive = chekShip(enemies_field, enemies_TD_ship[i], ' ');
                if (enemies_TD_ship[i].isAlive == 0)
                {
                    enemies_field = drawDeadShip(enemies_field, enemies_TD_ship[i]);
                }
            }

            for (int i = 0; i < 3; ++i)
            {
                enemies_TWD_ship[i].isAlive = chekShip(enemies_field, enemies_TWD_ship[i], ' ');
                if (enemies_TWD_ship[i].isAlive == 0)
                {
                    enemies_field = drawDeadShip(enemies_field, enemies_TWD_ship[i]);
                }
            }

            for (int i = 0; i < 4; ++i)
            {
                enemies_OD_ship[i].isAlive = chekShip(enemies_field, enemies_OD_ship[i], ' ');
                if (enemies_OD_ship[i].isAlive == 0)
                {
                    enemies_field = drawDeadShip(enemies_field, enemies_OD_ship[i]);
                }
            }

            playersScore += isShot;
        }

        printf("BOT'S TURN");
        getchar();

        isShot = 1;
        while (isShot == 1) // BOT'S TURN
        {
            coordinates_pos_x = rand() % 9;
            coordinates_pos_y = rand() % 9;

            isShot = isContinue(players_filed, coordinates_pos_x, coordinates_pos_y);
            players_filed = strikeShipDraw(players_filed, players_filed, coordinates_pos_x, coordinates_pos_y);

            player_FD_ship.isAlive = chekShip(players_filed, player_FD_ship, '#');
            if (player_FD_ship.isAlive == 0)
            {
                players_filed = drawDeadShip(players_filed, player_FD_ship);
            }

            for (int i = 0; i < 2; ++i)
            {
                player_TD_ship[i].isAlive = chekShip(players_filed, player_TD_ship[i], '#');
                if (player_TD_ship[i].isAlive == 0)
                {
                    players_filed = drawDeadShip(players_filed, player_TD_ship[i]);
                }
            }

            for (int i = 0; i < 3; ++i)
            {
                player_TWD_ship[i].isAlive = chekShip(players_filed, player_TWD_ship[i], '#');
                if (player_TWD_ship[i].isAlive == 0)
                {
                    players_filed = drawDeadShip(players_filed, player_TWD_ship[i]);
                }
            }

            for (int i = 0; i < 4; ++i)
            {
                player_OD_ship[i].isAlive = chekShip(players_filed, player_OD_ship[i], '#');
                if (player_OD_ship[i].isAlive == 0)
                {
                    players_filed = drawDeadShip(players_filed, player_OD_ship[i]);
                }
            }

            enemiesScore += isShot;
        }

        if (playersScore == 20)
        {
            playerRezult = 1;
            break;
        }

        if (enemiesScore == 20)
        {
            enemyRezult = 1;
            break;
        }
    }

    if (playerRezult == 1)
    {
        system("cls");
        displayField(players_filed, enemies_field);
        printf("PLAYER WIN!");
    }
    else
    {
        system("cls");
        displayField(players_filed, enemies_field);
        printf("ENEMY WIN!");
    }

    getchar();

    //exit game
    deleteGameField(players_filed);
    deleteGameField(enemies_field);
    deleteGameField(back_enemies_field);
    return 0;
}