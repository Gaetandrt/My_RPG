/*
** EPITECH PROJECT, 2022
** init stats
** File description:
** rpg
*/

#include "source.h"

opt_t *init_opt(game_t *game UNUSED)
{
    opt_t *opt = malloc(sizeof(opt_t));
    sfVector2f pos_bg = {0, 0};
    sfIntRect bg_rect = {0, 0, 1920, 1080};

    opt->bg = init_entity("assets/bgm.png", pos_bg, bg_rect);

    return opt;
}

game_t *init_game(void)
{
    game_t *game = malloc(sizeof(game_t));
    sfVideoMode mode = {1920, 1080, 32};
    char *ttle = "Titan Quest";

    game->window = sfRenderWindow_create(mode, ttle, sfResize | sfClose, NULL);
    game->ismusic = sfTrue;
    game->menu = init_menu(game);
    game->fight = init_fight(game);
    game->play = NULL;
    game->ismenu = sfTrue;
    game->ispause = sfFalse;
    game->isplay = sfFalse;
    game->isfight = sfFalse;
    game->sounds = init_sounds(game);
    return game;
}

void init_scene(game_t *game)
{
    sfTime delta;

    while (sfRenderWindow_isOpen(game->window)) {
        process_events(game);
        sfRenderWindow_clear(game->window, sfBlack);
        if (game->isopt)
            process_opt(game);
        if (game->ismenu)
            process_menu(game);
        if (game->isplay) {
            delta_time(game, delta);
            process_play(game);
        }
        if (game->ispause)
            process_pause(game);
        if (game->isfight)
            process_fight(game);
        sfRenderWindow_display(game->window);
    }
}

void clear_game(game_t *game)
{
    sfRenderWindow_destroy(game->window);
    free(game);
}

void event_opt(game_t *game)
{
    if (game->event.type == sfEvtKeyPressed) {
        if (game->event.key.code == sfKeyEscape)
            return_menu(game);
        if (game->event.key.code == sfKeyM)
            pause_allmusic(game);
    }
}
