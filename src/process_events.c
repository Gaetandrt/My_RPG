/*
** EPITECH PROJECT, 2022
** process
** File description:
** rpg
*/

#include "source.h"

void event_menu(game_t *game)
{
    if (game->event.type == sfEvtMouseButtonReleased) {
        if (game->event.mouseButton.button == sfMouseLeft)
            check_button_pressed(game, menu_buttons, NB_M_BUTTONS);
    }
}

void event_play(game_t *game)
{
    if (game->event.type == sfEvtKeyPressed) {
        move_pers(game);

        if (game->event.key.code == sfKeyEscape)
            set_pause(game);
        if (game->event.key.code == sfKeyA && pnj_colision(game) == 1) {
            game->play->pnj->dial->pos = (sfVector2f) {900, 100};
            sfSprite_setPosition(game->play->pnj->dial->sprite,
            game->play->pnj->dial->pos);
            sfRenderWindow_drawSprite(game->window,
            game->play->pnj->dial->sprite, NULL);
        }
    }
}

void event_fight(game_t *game)
{
    fight_t *fight = game->fight;
    if (game->event.type == sfEvtKeyPressed)
        if (game->event.key.code == sfKeyA)
            beam_attack(fight->attack, game->play->delta);
}

void event_pause(game_t *game)
{
    if (game->event.type == sfEvtMouseButtonReleased) {
        if (game->event.mouseButton.button == sfMouseLeft)
            check_button_pressed(game, pause_buttons, NB_P_BUTTONS);
    }
}

int process_events(game_t *game)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        if (game->isfight)
            event_fight(game);
        if (game->ismenu)
            event_menu(game);
        if (game->isplay)
            event_play(game);
        if (game->ispause)
            event_pause(game);
        if (game->isopt)
            event_opt(game);
        if (game->event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
    }
    return 0;
}
