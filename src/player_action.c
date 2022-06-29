/*
** EPITECH PROJECT, 2022
** player_actions
** File description:
** my_rpg
*/

#include "source.h"

void move_map2(game_t *game)
{
    stop_map(game);
    launch_fight(game);
    sfSprite_setPosition(game->play->player->ent->sprite,
    game->play->player->ent->pos);
    sfSprite_setPosition(game->play->map->sprite, game->play->map->pos);
    sfSprite_setPosition(game->play->map_col->sprite, game->play->map->pos);
}

void move_map(game_t *game)
{
    int x = game->play->player->ent->pos.x;
    int y = game->play->player->ent->pos.y;

    if (x < 100) {
        game->play->map->pos.x += 10;
        game->play->player->ent->pos.x += 10;
    }
    if (x > 1700) {
        game->play->map->pos.x -= 10;
        game->play->player->ent->pos.x -= 10;
    }
    if (y < 60) {
        game->play->map->pos.y += 10;
        game->play->player->ent->pos.y += 10;
    }
    if (y > 870) {
        game->play->map->pos.y -= 10;
        game->play->player->ent->pos.y -= 10;
    }
    move_map2(game);
}

game_t *move_pers2(game_t *game)
{
    if (game->event.key.code == sfKeyDown) {
        game->play->player->ent->rect.top = 0;
        game->play->player->ent->pos.y += 10;
        if (pnj_colision(game) == 0)
            game->play->player->ent->pos.y -= 10;
    }
    if (game->event.key.code == sfKeyRight) {
        game->play->player->ent->rect.top = 125;
        game->play->player->ent->pos.x += 10;
        if (pnj_colision(game) == 0)
            game->play->player->ent->pos.x -= 10;
    }
    game->play->pnj->dial->pos = (sfVector2f) {-1000, -10000};
    sfSprite_setPosition(game->play->pnj->dial->sprite,
    game->play->pnj->dial->pos);
    move_map(game);
    return (game);
}

void which_movement(game_t *game)
{
    if (game->event.key.code == sfKeyUp) {
        game->play->player->ent->rect.top = 190;
        game->play->player->ent->pos.y -= 10;
        if (pnj_colision(game) == 0)
            game->play->player->ent->pos.y += 10;
    }
    if (game->event.key.code == sfKeyLeft) {
        game->play->player->ent->rect.top = 65;
        game->play->player->ent->pos.x -= 10;
        if (pnj_colision(game) == 0)
            game->play->player->ent->pos.x += 10;
    }
}

game_t *move_pers(game_t *game)
{
    if (game->event.type == sfEvtKeyPressed) {
        which_movement(game);
        return (move_pers2(game));
    }
    return game;
}
