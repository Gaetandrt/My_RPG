/*
** EPITECH PROJECT, 2022
** delta
** File description:
** time
*/

#include "source.h"

void delta_time(game_t * game, sfTime time)
{
    time = sfClock_getElapsedTime(game->play->d_clock);
    sfClock_restart(game->play->d_clock);
    game->play->delta = time.microseconds / 1000000.0;
}
