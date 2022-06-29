/*
** EPITECH PROJECT, 2022
** menuactions
** File description:
** rpg
*/

#include "source.h"

void set_play(game_t *game)
{
    game->play = init_play(game);
    game->ismenu = sfFalse;
    game->ispause = sfFalse;
    game->isfight = sfFalse;
    game->isplay = sfTrue;
}

void set_pause(game_t *game)
{
    game->pause = init_pause(game);
    game->ismenu = sfFalse;
    game->ispause = sfTrue;
    game->isplay = sfFalse;
    game->isfight = sfFalse;
}

void set_menu(game_t *game)
{
    clear_play(game);
    game->menu = init_menu(game);
    game->ismenu = sfTrue;
    game->ispause = sfFalse;
    game->isplay = sfFalse;
    game->isfight = sfFalse;
    game->isopt = sfFalse;
}

void resume_game(game_t *game)
{
    game->ismenu = sfFalse;
    game->ispause = sfFalse;
    game->isplay = sfTrue;
    game->isfight = sfFalse;
}

void quit_game(game_t *game)
{
    if (game->play)
        clear_play(game);
    game->ismenu = sfFalse;
    game->ispause = sfFalse;
    game->isfight = sfFalse;
    game->isplay = sfFalse;
    sfMusic_destroy(game->sounds->over_button);
    sfMusic_destroy(game->sounds->levelup);
    free(game->sounds);
    sfRenderWindow_close(game->window);
}
