/*
** EPITECH PROJECT, 2022
** player
** File description:
** rpg
*/

#include "source.h"

void process_player(game_t *game)
{
    player_t *tmp = game->play->player;
    while (tmp) {
        sfRenderWindow_drawSprite(game->window, tmp->ent->sprite, NULL);
        sfRenderWindow_drawSprite(game->window,
        game->play->map_col->sprite, NULL);
        move_player(tmp->ent, game->play->delta);
        tmp = tmp->next;
    }
}

void move_player(entity_t *player, float timer)
{
    player->timer += timer * 10;
    if (player->timer >= 2) {
        move_rect(player, 65, 240);
        player->timer = 0;
    }
}

void player_pb(player_t **player, game_t *game UNUSED , char *filename)
{
    player_t *nplayer = malloc(sizeof(player_t));
    sfVector2f pos = {500, 500};
    sfIntRect rect =  {200, 0, 50, 75};
    nplayer->ent = init_entity(filename, pos, rect);
    sfSprite_setScale(nplayer->ent->sprite, (sfVector2f) {1.5, 1.5});
    nplayer->next = NULL;
    if (!(*player)) {
        (*player) = nplayer;
        return;
    }
}

player_t *init_player(game_t *game, char *filename)
{
    player_t *playerb = NULL;

    player_pb(&playerb, game, filename);
    return playerb;
}
