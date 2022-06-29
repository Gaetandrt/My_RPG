/*
** EPITECH PROJECT, 2022
** enemies
** File description:
** rpg
*/

#include "source.h"

void process_enemy(game_t *game)
{
    enemy_t *tmp = game->play->enemies;
    while (tmp) {
        set_pos(game, tmp);
        launch_fight(game);
        sfRenderWindow_drawSprite(game->window, tmp->ent->sprite, NULL);
        move_enemy(tmp->ent, game->play->delta);
        tmp = tmp->next;
    }
}

void move_rect(entity_t *ent, int offset, int max_value)
{
    ent->rect.left += offset;
    if (ent->rect.left >= max_value)
        ent->rect.left = 0;
    sfSprite_setTextureRect(ent->sprite, ent->rect);
}

void move_enemy(entity_t *enemy, float timer)
{
    enemy->timer += timer * 10;
    if (enemy->timer >= 1) {
        move_rect(enemy, 145, 720);
        enemy->timer = 0;
    }
}

void enemy_pb(enemy_t **enemy, char *filename)
{
    enemy_t *nenemy = malloc(sizeof(enemy_t));
    enemy_t *tmp = (*enemy);
    int frandx = rand() % 600;
    int frandy = rand() % 600;
    int x = rand() % 500 + frandx;
    int y = rand() % 500 + frandy;
    sfVector2f pos = {x, y};
    sfVector2f scale = {0.8, 0.8};
    sfIntRect rect = {300, 0, 150, 150};

    nenemy->ent = init_entity(filename, pos, rect);
    nenemy->ent->pos = (sfVector2f) {x, y};
    sfSprite_setScale(nenemy->ent->sprite, scale);
    nenemy->next = NULL;
    if (!(*enemy)) {
        (*enemy) = nenemy;
        return;
    }
    while ((tmp)->next)
        (tmp) = (tmp)->next;
    (tmp)->next = nenemy;
}

enemy_t *init_enemies(game_t *game UNUSED, char *filename)
{
    enemy_t *enemies = NULL;
    enemy_pb(&enemies, filename);
    return enemies;
}
