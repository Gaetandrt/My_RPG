/*
** EPITECH PROJECT, 2022
** hover
** File description:
** entity
*/

#include "source.h"

void hover_entity(game_t *game, entity_t *entity, void (*fct)(game_t *))
{
    if (entity) {
        if (entity_is_hover(game->window, entity->rect, entity->pos))
            fct(game);
    }
}
