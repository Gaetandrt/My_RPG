/*
** EPITECH PROJECT, 2022
** buttons
** File description:
** rpg
*/

#include "source.h"

int button_is_hover(sfRenderWindow *window, button_t btn)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(window);

    if (pos.x >= btn.pos.x && pos.y >= btn.pos.y) {
        if (pos.x <= btn.pos.x + btn.size.x && pos.y <= btn.pos.y + btn.size.y)
            return 1;
    }
    return 0;
}

void check_button_pressed(game_t *game, const button_t buttons[], int l)
{
    for (int i = 0; i < l; i++) {
        if (button_is_hover(game->window, buttons[i])) {
            over_button(game);
            buttons[i].fct(game);
            buttons[i].clear(game);
        }
    }
}

void over_button(game_t *game)
{
    sfMusic *music = game->sounds->over_button;
    sfMusic_play(music);
}

