
#ifndef __GAME_INFO_H__
#define	__GAME_INFO_H__

#include <stdbool.h>
#include "list.h"

#define	REP_OK		"ok"
#define	REP_KO		"ko"
#define	REP_VOIR	"%s"
#define	REP_INVENTORY	"nourriture %d, linemate %d, deraumere %d, sibur %d, mendiane %d, phiras %d, thystame %d"
#define	REP_INCANTATION	"elevation en cours niveau actuel : %d"
#define	REP_CONNECT_NBR	"%d"
#define	REP_DEATH	"mort"

#define	TEAM_NAME_SIZE	32

#define	DELAY_STANDARD	7
#define	DELAY_INCANT	300
#define	DELAY_FORK	42
#define DELAY_FOOD	126

#define WORLD_MAX_SIZE 1000
#define TEAM_MAX_SLOT 50

typedef struct s_player t_player;
typedef struct s_team t_team;
typedef struct s_tile t_tile;

typedef enum {
	IT_FOOD,
	IT_LINEMATE,
	IT_DERAUMERE,
	IT_SIBUR,
	IT_MENDIANE,
	IT_PHIRAS,
	IT_THYSTAME
} t_item;

typedef enum {
	OR_NORTH = 0,
	OR_EAST = 1,
	OR_SOUTH = 2,
	OR_WEST = 3
} t_orientation;

typedef struct s_leveler {
	int nb_players;
	int linemate;
	int deraumere;
	int sibur;
	int mendiane;
	int phiras;
	int thystame;
} t_leveler;

typedef struct s_inventory {
	int food;
	int linemate;
	int deraumere;
	int sibur;
	int mendiane;
	int phiras;
	int thystame;
} t_inventory;

typedef struct s_pos {
	int x;
	int y;
} t_pos;
typedef t_pos t_dim;

typedef struct {
	t_tile *tiles;
	t_dim dimensions;
#define w_width dimensions.x
#define w_height dimensions.y
} t_world;

typedef struct s_game
{
	t_world world;
	t_list teams;
	t_list slots;
	int nb_slots;
} t_game;

struct s_player {
	int id;
	t_team *team;
	t_tile *tile;
#define ppos_x tile->coord.x
#define ppos_y tile->coord.y
	t_orientation orientation;
	t_inventory inventory;
#define inv_food inventory.food
#define inv_linemate inventory.linemate
#define inv_deraumere inventory.deraumere
#define inv_sibur inventory.sibur
#define inv_mendiane inventory.mendiane
#define inv_phiras inventory.phiras
#define inv_thystame inventory.thystame
	int level;
	int life;
};

struct s_team {
	char name[TEAM_NAME_SIZE + 1];
	t_list players;
	int available_slots;
	int free_slots;
};

struct s_tile {
	t_list players;
	t_pos coord;
#define pos_x coord.x
#define pos_y coord.y
	t_inventory ressources;
#define rc_food ressources.food
#define rc_linemate ressources.linemate
#define rc_deraumere ressources.deraumere
#define rc_sibur ressources.sibur
#define rc_mendiane ressources.mendiane
#define rc_phiras ressources.phiras
#define rc_thystame ressources.thystame
};

#endif
