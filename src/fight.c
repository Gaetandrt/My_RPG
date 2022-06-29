/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-gaetan.darrort
** File description:
** fight
*/

#include "source.h"

void launch_fight(game_t *game)
{
    player_t *player = game->play->player;
    enemy_t *enemy = game->play->enemies;
    int len = 0;
    int x = enemy->ent->pos.x - player->ent->pos.x;
    int y = enemy->ent->pos.y - player->ent->pos.y;
    if (x < 103)
        len++;
    if (x > -77)
        len++;
    if (y < 126)
        len++;
    if (y > -44)
        len++;
    if (len == 4 && game->fight->initfight == sfTrue) {
        set_fight(game);
    }
}

void set_scale_fight(fight_t *fight)
{
    sfVector2f scale = {2.5, 2.5};
    sfVector2f scalebox = {3.5, 3.5};

    sfSprite_setScale(fight->enem->sprite, scale);
    sfSprite_setScale(fight->p1->sprite, scale);
    sfSprite_setScale(fight->dbox->sprite, scalebox);
}

fight_t *init_fight(game_t *game UNUSED)
{
    fight_t *fight = malloc(sizeof(fight_t));
    sfVector2f bg_pos = {0, 0};
    sfIntRect bg_rect = {0, 0, 1920, 1080};
    sfVector2f pos = {400, 100};

    fight->initfight = sfTrue;
    fight->bg = init_entity("assets/fight_bg.png", (bg_pos), bg_rect);
    fight->enem = init_entity("assets/ef.png", (sfVector2f) {200, 600},
    (sfIntRect) {0, 0, 200, 200});
    fight->p1 = init_entity("assets/pf.png", (sfVector2f) {1400, 830},
    (sfIntRect) {0, 0, 200, 200});
    fight->dbox = init_entity("assets/dbox.png", pos,
    (sfIntRect) {0, 0, 320, 80});
    fight->music = sfMusic_createFromFile("assets/fight_theme.ogg");
    fight->attack = init_entity("assets/beam_attack.png", (sfVector2f)
    {1100, 650}, (sfIntRect) {0, 0, 500, 500});
    fight->beam = init_entity("assets/beam_attack.png", (sfVector2f) {300, 0},
    (sfIntRect) {0, 0, 500, 500});
    set_scale_fight(fight);
    return fight;
}

void process_fight(game_t *game)
{
    fight_t *fight = game->fight;
    fight_anim(fight->enem, game->play->delta);
    sfSprite_setPosition(fight->enem->sprite, fight->enem->pos);
    sfRenderWindow_drawSprite(game->window, fight->bg->sprite, NULL);
    sfRenderWindow_drawSprite(game->window, fight->enem->sprite, NULL);
    sfRenderWindow_drawSprite(game->window, fight->p1->sprite, NULL);
    sfRenderWindow_drawSprite(game->window, fight->dbox->sprite, NULL);
    sfRenderWindow_drawSprite(game->window, fight->beam->sprite, NULL);
    sfRenderWindow_drawSprite(game->window, fight->attack->sprite, NULL);
    sfSprite_setPosition(fight->attack->sprite, fight->attack->pos);
    sfRenderWindow_drawSprite(game->window, game->fight->attack->sprite, NULL);
    if (fight->attack->pos.x < 220) {
        clear_fight(game);
        resume_game(game);
    }
}
