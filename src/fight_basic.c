/*
** EPITECH PROJECT, 2022
** basic
** File description:
** fight
*/

#include "source.h"

void change_dialog(game_t *game, char *filename)
{
    pnj_t *pnj = game->play->pnj;
    pnj->dial = init_entity(filename, (sfVector2f) {-1000, -1000},
    (sfIntRect) {0, 0, 320, 80});
    sfSprite_setScale(pnj->dial->sprite, (sfVector2f) {2, 2});
}

void clear_fight(game_t *game)
{
    sfMusic_pause(game->fight->music);
    change_dialog(game, "assets/dial2.png");
    game->fight->initfight = sfFalse;
    sfMusic_destroy(game->fight->music);
    destroy_entity(game->fight->bg);
    game->isfight = sfFalse;
    game->play->xp->ent->rect.width += 195;
    resume_game(game);
    sfMusic_play(game->play->music);
    free(game->fight);
}

void set_fight(game_t *game)
{
    sfMusic_pause(game->play->music);
    game->fight = init_fight(game);
    if (game->ismusic == sfTrue)
        sfMusic_play(game->fight->music);
    game->ismenu = sfFalse;
    game->isfight = sfTrue;
    game->ispause = sfFalse;
    game->isplay = sfFalse;
    game->isopt = sfFalse;
}

void fight_anim(entity_t *enemy, float timer)
{
    enemy->timer += timer * 10;
    if (enemy->timer >= 2) {
        if (enemy->pos.y < 700)
            enemy->pos.y += 20;
        else
            enemy->pos.y -= 20;
        enemy->timer = 0;
    }

}

void beam_attack(entity_t *enemy, float timer)
{
    enemy->timer += timer * 10;
    if (enemy->timer >= 0.001) {
        if (enemy->pos.x > 200)
            enemy->pos.x -= 70;
        enemy->timer = 0;
    }
}
