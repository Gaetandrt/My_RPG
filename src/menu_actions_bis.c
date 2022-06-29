/*
** EPITECH PROJECT, 2022
** menuaction2
** File description:
** rpg
*/

#include "source.h"

void clear_menu(game_t *game)
{
    sfMusic_pause(game->menu->music);
    sfMusic_destroy(game->menu->music);
    destroy_entity(game->menu->bg);
    sfText_destroy(game->menu->title);
    free(game->menu);
}

void clear_pause(game_t *game)
{
    destroy_entity(game->pause->bg);
    sfText_destroy(game->pause->pause);
    free(game->pause);
}

void clear_play(game_t *game)
{
    sfMusic_pause(game->play->music);
    sfMusic_destroy(game->play->music);
    free(game->play);
}

void set_opt(game_t *game)
{
    game->opt = init_opt(game);
    game->ismenu = sfFalse;
    game->ispause = sfFalse;
    game->isfight = sfFalse;
    game->isplay = sfFalse;
    game->isopt = sfTrue;
}
