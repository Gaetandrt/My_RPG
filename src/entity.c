/*
** EPITECH PROJECT, 2022
** entity
** File description:
** rpg
*/

#include "source.h"

void destroy_entity(entity_t *entity)
{
    sfSprite_destroy(entity->sprite);
    sfTexture_destroy(entity->texture);
    free(entity);
}

int entity_is_hover(sfRenderWindow *window, sfIntRect rect, sfVector2f pos)
{
    sfVector2i p = sfMouse_getPositionRenderWindow(window);
    float width = rect.width;

    if (p.x >= pos.x && p.y >= pos.y) {
        if (p.x <= pos.x + rect.height && p.y <= pos.y + width)
            return 1;
    }
    return 0;
}

entity_t *init_entity(char *file, sfVector2f pos, sfIntRect rect)
{
    entity_t *entity = malloc(sizeof(entity_t));

    entity->texture = sfTexture_createFromFile(file, NULL);
    entity->sprite = sfSprite_create();
    entity->pos = pos;
    entity->rect = rect;
    sfSprite_setTexture(entity->sprite, entity->texture, sfTrue);
    sfSprite_setPosition(entity->sprite, pos);
    sfSprite_setTextureRect(entity->sprite, rect);
    return entity;
}
