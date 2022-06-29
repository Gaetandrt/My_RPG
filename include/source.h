/*
** EPITECH PROJECT, 2022
** spurce
** File description:
** SRC_H
*/

#ifndef SRC_H
    #define SRC_H

    #define UNUSED __attribute__((unused))

    #include <stdio.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <string.h>
    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include <SFML/Audio.h>
    #include <stdbool.h>
    #include <sys/stat.h>
    #include "game.h"

void my_putstr(char *str);
int my_strlen(char const *str);
void delta_time(game_t * game, sfTime time);

menu_t *init_menu(game_t *game UNUSED);
pause_t *init_pause(game_t *game UNUSED);
play_t *init_play(game_t *game);
game_t *init_game(void);
sounds_t *init_sounds(game_t *game UNUSED);
sfText *init_text(sfColor color, int size, sfVector2f pos);
opt_t *init_opt(game_t *game UNUSED);
void inventory_init(game_t *game);

void init_scene(game_t *game);
void clear_game(game_t *game);

void hover_entity(game_t *game, entity_t *entity, void (*fct)(game_t *));
void event_menu(game_t *game);
void event_play(game_t *game);
void event_pause(game_t *game);
void event_opt(game_t *game);
int process_events(game_t *game);

void set_play(game_t *game);
void set_pause(game_t *game);
void set_menu(game_t *game);
void hover_entity(game_t *game, entity_t *entity, void (*fct)(game_t *));
void resume_game(game_t *game);
void quit_game(game_t *game);
void clear_menu(game_t *game);
void clear_pause(game_t *game);
void clear_play(game_t *game);
void set_opt(game_t *game);
void return_menu(game_t *game);
void clear_opt(opt_t *opt);

void process_opt(game_t *game);
void process_menu(game_t *game);
void process_pause(game_t *game);
void process_play(game_t *game);
void delta_time(game_t * game, sfTime time);

void process_enemy(game_t *game);
void move_enemy(entity_t *enemy, float timer);
void move_rect(entity_t *ent, int offset, int max_value);
enemy_t *init_enemies(game_t *game UNUSED, char *filename);
void enemy_pb(enemy_t **enemy, char *filename);
void set_pos(game_t *game, enemy_t *enemy);

int button_is_hover(sfRenderWindow *window, button_t btn);
void check_button_pressed(game_t *game, const button_t buttons[], int l);
void over_button(game_t *game);

void destroy_entity(entity_t *entity);
entity_t *init_entity(char *file, sfVector2f pos, sfIntRect rect);
int entity_is_hover(sfRenderWindow *window, sfIntRect rect, sfVector2f pos);

player_t *init_player(game_t *game UNUSED, char *filename);
void player_pb(player_t **player, game_t *game, char *filename);
void process_player(game_t *game);
void move_player(entity_t *player, float timer);
game_t *move_pers(game_t *game);
void stop_map(game_t *game);
int pnj_colision(game_t *game);

xpbar_t *init_xp(game_t *game, char *filename);
void xp_pb(xpbar_t **xp, game_t *game UNUSED , char *filename);
void process_xp(game_t *game);
void morexp(game_t *game);
char *my_itoa(int nb);
void level_up(game_t *game);

inventory_t *init_inventory(game_t *game, char *filename);
void inventory_pb(inventory_t **inv, game_t *game UNUSED , char *filename);
void process_inventory(game_t *game);
void display_inv(game_t *game);
void process_inv(game_t *game);

char **my_str_to_word_array(char *str, char delim);
char *readfile(char *filepath);
void printab(char **tab);
void my_putchar(char c);
void detect_collisions(game_t *game);
void pause_allmusic(game_t *game);
void set_pos(game_t *game, enemy_t *enemy);
void launch_fight(game_t *game);

fight_t *init_fight(game_t *game);
void clear_fight(game_t *game);
void set_fight(game_t *game);
void process_fight(game_t *game);
void fight_anim(entity_t *enemy, float timer);

void event_fight(game_t *game);
void beam_attack(entity_t *enemy, float timer);

void process_pnj(game_t *game);
void move_pnj(entity_t *pnj, float timer);
void pnj_pb(pnj_t **pnj, game_t *game UNUSED , char *filename);
pnj_t *init_pnj(game_t *game, char *filename);
int pnj_colision(game_t *game);
void dialog_pnj(game_t *game);

    #define POS_PLAY (sfVector2f){800, 500}
    #define POS_QUIT (sfVector2f){800, 700}
    #define POS_HOME (sfVector2f){800, 800}
    #define POS_opt (sfVector2f) {800, 600}

    #define PQP (sfVector2f){800, 500}
    #define PHP (sfVector2f){500, 500}
    #define PRP (sfVector2f){1100, 500}

static const button_t menu_buttons[] = {
    {"Play", POS_PLAY, (sfVector2f){100, 60}, set_play, clear_menu},
    {"Quit", POS_QUIT, (sfVector2f){95, 55}, quit_game, clear_menu},
    {"Options", POS_opt, (sfVector2f) {95, 55}, set_opt, clear_menu},
};

static const button_t pause_buttons[] = {
    {"Resume", PRP, (sfVector2f){180, 60}, resume_game, clear_pause},
    {"Home", PHP, (sfVector2f){100, 60}, set_menu, clear_pause},
    {"Quit", PQP, (sfVector2f){240, 60}, quit_game, clear_pause},
};

    #define NB_M_BUTTONS (sizeof(menu_buttons) / sizeof(button_t))
    #define NB_P_BUTTONS (sizeof(pause_buttons) / sizeof(button_t))

#endif /* !SRC_H */
