/*
** EPITECH PROJECT, 2022
** game
** File description:
** game
*/

#ifndef GAME_H
    #define GAME_H

    #include "source.h"

typedef struct game game_t;
typedef struct enemy_s enemy_t;
typedef struct player_s player_t;
typedef struct xpbar_s xpbar_t;
typedef struct inventory_s inventory_t;
typedef struct fight_s fight_t;
typedef struct pnj_s pnj_t;


typedef struct entity {
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
    sfVector2f pos;
    float timer;
} entity_t;

struct inventory_s {
    entity_t *ent;
    inventory_t *next;
};

typedef struct button {
    char *title;
    sfVector2f pos;
    sfVector2f size;
    void (*fct)(game_t *);
    void (*clear)(game_t *);
} button_t;

typedef struct pause {
    entity_t *bg;
    sfText *pause;
} pause_t;

struct enemy_s {
    entity_t *ent;
    int life;
    int speed;
    enemy_t *next;
};

struct player_s {
    entity_t *ent;
    sfVector2f view;
    player_t *next;
};

struct pnj_s {
    entity_t *ent;
    entity_t *dial;
    pnj_t *next;
};

struct xpbar_s {
    entity_t *ent;
    int level;
    sfText *text;
    sfMusic *music;
    xpbar_t *next;
};

typedef struct play {
    sfMusic *music;
    float delta;
    entity_t *map;
    entity_t *map_col;
    char **col;
    sfClock *d_clock;
    inventory_t *inventory;
    xpbar_t *xp;
    enemy_t *enemies;
    pnj_t *pnj;
    player_t *player;
} play_t;

typedef struct menu {
    entity_t *bg;
    sfText *title;
    sfMusic *music;
    void (*fct)(game_t *);
} menu_t;

struct fight_s {
    entity_t *bg;
    entity_t *p1;
    entity_t *enem;
    sfBool initfight;
    entity_t *dbox;
    entity_t *beam;
    entity_t *attack;
    sfMusic *music;
};

typedef struct sounds_s {
    sfMusic *over_button;
    sfMusic *spend_gold;
    sfMusic *levelup;
} sounds_t;

typedef struct opt_s {
    entity_t *bg;
    entity_t *music;
    entity_t *btn;
    entity_t *nomusic;
} opt_t;

struct game {
    sfRenderWindow *window;
    sfEvent event;
    sfBool ismenu;
    menu_t *menu;
    fight_t *fight;
    play_t *play;
    sfBool ismusic;
    sfBool isfight;
    pause_t *pause;
    sfBool ispause;
    sfBool isplay;
    sfBool isopt;
    opt_t *opt;
    sounds_t *sounds;
};

#endif /* !game */
