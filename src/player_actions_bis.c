/*
** EPITECH PROJECT, 2022
** player
** File description:
** actions bis
*/

#include "source.h"

void stop_map(game_t *game)
{
    int x = game->play->map->pos.x;
    int y = game->play->map->pos.y;
    if (x > 0)
        game->play->map->pos.x -= 10;
    if (x < -160)
        game->play->map->pos.x += 10;
    if (y > 0)
        game->play->map->pos.y -= 10;
    if (y < -1000)
        game->play->map->pos.y += 10;
}

int pnj_colision(game_t *game)
{
    pnj_t *pnj = game->play->pnj;
    player_t *player = game->play->player;
    int x = player->ent->pos.x;
    int y = player->ent->pos.y;
    int difx = pnj->ent->pos.x - x;
    int dify = pnj->ent->pos.y - y;
    int len = 0;

    if (difx < 40)
        len++;
    if (difx > -30)
        len++;
    if (dify > -225)
        len++;
    if (dify < -30)
        len++;
    if (len == 4)
        return 0;
    return 1;
}
