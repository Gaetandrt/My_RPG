/*
** EPITECH PROJECT, 2022
** set ennemi
** File description:
** position
*/

#include "source.h"

void set_pos(game_t *game, enemy_t *enemy)
{
    int mapx = game->play->map->pos.x;
    int mapy = game->play->map->pos.y;
    int enx = enemy->ent->pos.x;
    int eny = enemy->ent->pos.y;
    sfVector2f pos = {0 + mapx + enx, 0 + mapy + eny};
    sfSprite_setPosition(enemy->ent->sprite, pos);
}
