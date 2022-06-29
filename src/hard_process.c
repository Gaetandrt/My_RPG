/*
** EPITECH PROJECT, 2022
** hard process
** File description:
** rpg
*/

#include "source.h"

void process_play(game_t *game)
{
    play_t *play = game->play;
    sfRenderWindow_drawSprite(game->window, play->map->sprite, NULL);
    if (play->enemies)
        process_enemy(game);
    if (play->pnj)
        process_pnj(game);
    if (play->player)
        process_player(game);
    if (play->xp)
        process_xp(game);
}

void pause_allmusic(game_t *game)
{
    if (game->ismusic == sfFalse) {
        game->ismusic = sfTrue;
        return;
    }
    if (game->ismusic == sfTrue) {
        destroy_entity(game->opt->music);
        game->ismusic = sfFalse;
    }
}

void process_opt(game_t *game)
{
    sfVector2f scale = {0.5, 0.5};
    sfVector2f pos = {50, 50};
    sfIntRect rect = {0, 0, 400, 400};
    sfRenderWindow_drawSprite(game->window, game->opt->bg->sprite, NULL);
    game->opt->music = init_entity("assets/note.png", pos, rect);
    game->opt->nomusic = init_entity("assets/nonote.png", pos, rect);
    sfSprite_setScale(game->opt->music->sprite, scale);
    sfSprite_setScale(game->opt->nomusic->sprite, scale);
    if (game->ismusic == sfTrue)
        sfRenderWindow_drawSprite(game->window, game->opt->music->sprite, NULL);
    if (game->ismusic == sfFalse)
        sfRenderWindow_drawSprite(game->window,
        game->opt->nomusic->sprite, NULL);
}

void process_menu(game_t *game)
{
    menu_t *menu = game->menu;
    sfRectangleShape *rect = NULL;
    sfText *text = NULL;

    sfRenderWindow_drawSprite(game->window, menu->bg->sprite, NULL);
    sfRenderWindow_drawText(game->window, menu->title, NULL);
    for (unsigned int i = 0; i < NB_M_BUTTONS; i++) {
        rect = sfRectangleShape_create();
        text = init_text(sfYellow, 50, menu_buttons[i].pos);
        sfText_setString(text, menu_buttons[i].title);
        sfRectangleShape_setPosition(rect, menu_buttons[i].pos);
        sfRectangleShape_setSize(rect, menu_buttons[i].size);
        if (button_is_hover(game->window, menu_buttons[i]))
            sfText_setColor(text, sfGreen);
        sfRectangleShape_setFillColor(rect, (sfColor){0, 0, 0, 0});
        sfRenderWindow_drawRectangleShape(game->window, rect, NULL);
        sfRenderWindow_drawText(game->window, text, NULL);
        sfRectangleShape_destroy(rect);
    }
}

void process_pause(game_t *game)
{
    pause_t *pause = game->pause;
    sfRectangleShape *rect = NULL;
    sfText *text = NULL;

    sfRenderWindow_drawSprite(game->window, pause->bg->sprite, NULL);
    sfRenderWindow_drawText(game->window, pause->pause, NULL);
    for (unsigned int i = 0; i < NB_P_BUTTONS; i++) {
        rect = sfRectangleShape_create();
        text = init_text(sfYellow, 50, pause_buttons[i].pos);
        sfText_setString(text, pause_buttons[i].title);
        sfRectangleShape_setPosition(rect, pause_buttons[i].pos);
        sfRectangleShape_setSize(rect, pause_buttons[i].size);
        if (button_is_hover(game->window, pause_buttons[i]))
            sfText_setColor(text, sfGreen);
        sfRectangleShape_setFillColor(rect, (sfColor){0, 0, 0, 0});
        sfRenderWindow_drawRectangleShape(game->window, rect, NULL);
        sfRenderWindow_drawText(game->window, text, NULL);
        sfRectangleShape_destroy(rect);
    }
}

