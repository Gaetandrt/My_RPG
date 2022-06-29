/*
** EPITECH PROJECT, 2022
** stats
** File description:
** rpg
*/

#include "source.h"

menu_t *init_menu(game_t *game)
{
    menu_t *menu = malloc(sizeof(menu_t));
    sfVector2f bg_pos = {0, 0};
    sfIntRect bg_rect = {0, 0, 1920, 1080};

    menu->bg = init_entity("assets/bgm.png", bg_pos, bg_rect);
    menu->title = init_text(sfYellow, 150, (sfVector2f){450, 230});
    sfText_setString(menu->title, "titan quest");
    menu->music = sfMusic_createFromFile("assets/main_theme.ogg");
    if (game->ismusic == sfTrue)
        sfMusic_play(menu->music);
    return menu;
}

pause_t *init_pause(game_t *game UNUSED)
{
    pause_t *pause = malloc(sizeof(pause_t));
    sfVector2f bg_pos = {0, 0};
    sfIntRect bg_rect = {0, 0, 1920, 1080};

    pause->bg = init_entity("assets/bgm.png", bg_pos, bg_rect);
    pause->pause = init_text(sfYellow, 150, (sfVector2f){715, 230});
    sfText_setString(pause->pause, "Pause");
    return pause;
}

play_t *init_play(game_t *game)
{
    sfVector2f bg_pos = {0, 0};
    sfIntRect bg_rect = {0, 0, 720, 720};
    sfVector2f scale = {2.8, 2.8};
    play_t *play = malloc(sizeof(play_t));

    play->col = my_str_to_word_array("assets/map_chall.txt", '\n');
    play->map = init_entity("assets/map_bg.png", bg_pos, bg_rect);
    play->map_col = init_entity("assets/map_fg.png", bg_pos, bg_rect);
    sfSprite_setScale(play->map->sprite, scale);
    sfSprite_setScale(play->map_col->sprite, scale);
    play->enemies = init_enemies(game, "assets/enemy.png");
    play->player = init_player(game, "assets/pkmnsprtsh.png");
    play->pnj = init_pnj(game, "assets/pnj.png");
    play->xp = init_xp(game, "assets/xpbar.png");
    play->inventory = init_inventory(game, "assets/sq_inv.png");
    play->d_clock = sfClock_create();
    play->music = sfMusic_createFromFile("assets/play_music.ogg");
    if (game->ismusic == sfTrue)
        sfMusic_play(play->music);
    return play;
}

sounds_t *init_sounds(game_t *game UNUSED)
{
    sounds_t *sounds = malloc(sizeof(sounds_t));

    sounds->over_button = sfMusic_createFromFile("assets/hover_button.ogg");
    sounds->levelup = sfMusic_createFromFile("assets/levelup.ogg");
    return sounds;
}

sfText *init_text(sfColor color, int size, sfVector2f pos)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("assets/myfont.ttf");

    sfText_setPosition(text, pos);
    sfText_setFont(text, font);
    sfText_setColor(text, color);
    sfText_setCharacterSize(text, size);
    return text;
}
