/*
** EPITECH PROJECT, 2022
** main
** File description:
** rpg
*/

#include "source.h"

int main(int ac, char **av)
{
    game_t *game = NULL;

    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        my_putstr("This a Role Playing Game\n\n");
        my_putstr("USAGE:\n    ./my_rpg\n\nUSER INTERACTIONS:");
        my_putstr("\n    [ESCAPE] = Pause the game\n");
        return 0;
    } else
        game = init_game();
    init_scene(game);
    clear_game(game);
    return 0;
}
