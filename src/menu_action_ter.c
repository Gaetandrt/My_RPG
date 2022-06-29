/*
** EPITECH PROJECT, 2022
** menuaction3
** File description:
** rpg
*/

#include "source.h"

void return_menu(game_t *game)
{
    if (game->isopt)
        clear_opt(game->opt);
    game->menu = init_menu(game);
    game->ismenu = sfTrue;
    game->ispause = sfFalse;
    game->isfight = sfFalse;
    game->isplay = sfFalse;
    game->isopt = sfFalse;
}

void clear_opt(opt_t *opt)
{
    destroy_entity(opt->bg);
    destroy_entity(opt->music);
    free(opt);
}
