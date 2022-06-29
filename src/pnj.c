/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-gaetan.darrort
** File description:
** pnj
*/

#include "source.h"

void set_pos_pnj(game_t *game, pnj_t *pnj)
{
    int mapx = game->play->map->pos.x;
    int mapy = game->play->map->pos.y;
    int enx = pnj->ent->pos.x;
    int eny = pnj->ent->pos.y;
    sfVector2f pos = {0 + mapx + enx, 0 + mapy + eny};
    sfSprite_setPosition(pnj->ent->sprite, pos);
}

void dialog_pnj(game_t *game)
{
    sfRenderWindow_drawSprite(game->window,
    game->play->pnj->dial->sprite, NULL);
}

void process_pnj(game_t *game)
{
    pnj_t *tmp = game->play->pnj;
    while (tmp) {
        set_pos_pnj(game, tmp);
        sfRenderWindow_drawSprite(game->window, tmp->ent->sprite, NULL);
        sfRenderWindow_drawSprite(game->window,
        game->play->pnj->dial->sprite, NULL);
        tmp = tmp->next;
    }
}

void pnj_pb(pnj_t **pnj, game_t *game UNUSED , char *filename)
{
    pnj_t *npnj = malloc(sizeof(pnj_t));
    sfVector2f pos = {800, -75};
    sfIntRect rect =  {0, -145, 43, 194};
    sfVector2f dpos = {-1000, -1000};
    sfIntRect drect =  {0, 0, 320, 80};
    npnj->ent = init_entity(filename, pos, rect);
    npnj->dial = init_entity("assets/dialogpnj.png", dpos, drect);
    sfSprite_setScale(npnj->ent->sprite, (sfVector2f) {1.5, 1.5});
    sfSprite_setScale(npnj->dial->sprite, (sfVector2f) {2, 2});
    npnj->next = NULL;
    if (!(*pnj)) {
        (*pnj) = npnj;
        return;
    }
}

pnj_t *init_pnj(game_t *game, char *filename)
{
    pnj_t *pnjb = NULL;

    pnj_pb(&pnjb, game, filename);
    return pnjb;
}
