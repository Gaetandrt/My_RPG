/*
** EPITECH PROJECT, 2022
** xpbar
** File description:
** myrpg
*/

#include "source.h"

void process_xp(game_t *game)
{
    xpbar_t *tmp = game->play->xp;
    sfRenderWindow_drawSprite(game->window, tmp->ent->sprite, NULL);
    morexp(game);
}

void level_up(game_t *game)
{
    sfMusic *music = game->sounds->levelup;
    sfMusic_play(music);
}

void morexp(game_t *game)
{
    xpbar_t *xp = game->play->xp;
    sfSprite_setPosition(xp->ent->sprite, (sfVector2f) {700, 850});
    if (xp->ent->rect.width >= 719) {
        level_up(game);
        xp->ent->rect.width = 40;
        xp->level += 1;
    }
    sfSprite_setTextureRect(game->play->xp->ent->sprite,
    game->play->xp->ent->rect);
}

void xp_pb(xpbar_t **xp, game_t *game UNUSED , char *filename)
{
    xpbar_t *nxp = malloc(sizeof(xpbar_t));
    sfVector2f pos = {1000, 1400};
    sfIntRect rect =  {0, 0, 47, 150};
    nxp->level = 0;
    nxp->ent = init_entity(filename, pos, rect);
    sfSprite_setScale(nxp->ent->sprite, (sfVector2f) {0.5, 0.5});
    nxp->next = NULL;
    if (!(*xp)) {
        (*xp) = nxp;
        return;
    }
}

xpbar_t *init_xp(game_t *game, char *filename)
{
    xpbar_t *xpb = NULL;

    xp_pb(&xpb, game, filename);
    return xpb;
}
