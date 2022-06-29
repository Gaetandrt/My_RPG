/*
** EPITECH PROJECT, 2022
** code_inventory
** File description:
** main
*/


#include "source.h"

void process_inv(game_t *game)
{
    inventory_t *tmp = game->play->inventory;
    sfRenderWindow_drawSprite(game->window, tmp->ent->sprite, NULL);
}

void inventory_pb(inventory_t **inventory, game_t *game UNUSED , char *filename)
{
    inventory_t *ninventory = malloc(sizeof(inventory_t));
    sfVector2f pos = {100, 200};
    sfIntRect rect =  {0, 0, 45, 70};
    ninventory->ent = init_entity(filename, pos, rect);
    sfSprite_setScale(ninventory->ent->sprite, (sfVector2f) {3, 3});
    ninventory->next = NULL;
    if (!(*inventory)) {
        (*inventory) = ninventory;
        return;
    }
}

inventory_t *init_inventory(game_t *game, char *filename)
{
    inventory_t *inventoryb = NULL;

    inventory_pb(&inventoryb, game, filename);
    return inventoryb;
}
