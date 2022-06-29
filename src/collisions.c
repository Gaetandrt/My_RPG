/*
** EPITECH PROJECT, 2022
** collisions
** File description:
** collisions
*/

#include "source.h"

void detect_collisions(game_t *game)
{
    player_t *player = game->play->player;
    int x = player->ent->pos.x;
    int y = player->ent->pos.y;
    int mx = game->play->map->pos.x;
    int my = game->play->map->pos.y;

    int a = y + mx / (1 * 3);
    int b = x + my / (1 * 3);

    if (game->play->col[a][b] != '0') {
        game->play->map->pos.y += 0;
        game->play->map->pos.x += 0;
    }
}

