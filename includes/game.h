/**
 *
 *
 *
 */

#ifndef		__GAME_H__
# define	__GAME_H__

# include	<stdbool.h>
# include	<stdlib.h>
# include	<stdio.h>
# include	<string.h>
# include	"map.h"
# include	"session.h"
# include	"kernel.h"

# define	REP_OK		"ok"
# define	REP_KO		"ko"
# define	REP_VOIR	"%s"
# define	REP_INVENTORY	"linemate %d, deraumere %d, sibur %d, mendiane %d, phiras %d, thystame %d, nourriture %d"
# define	REP_INCANTATION	"elevation en cours niveau actuel : %d"
# define	REP_CONNECT_NBR	"%d"
# define	REP_DEATH	"-"

# define	TEAM_NAME_SIZE	32

# define	DELAY_STANDARD	7
# define	DELAY_INCANT	300
# define	DELAY_FORK	42

typedef enum
  {
    IT_LINEMATE,
    IT_DERAUMERE,
    IT_SIBUR,
    IT_MENDIANE,
    IT_PHIRAS,
    IT_THYSTAME,
    IT_FOOD
  }		t_item;

/*
** start of player module
*/

typedef struct
{
  int		nb_players;
  int		linemate;
  int		deraumere;
  int		sibur;
  int		mendiane;
  int		phiras;
  int		thystame;
}		t_leveler;

typedef enum
  {
    OR_NORTH,
    OR_EAST,
    OR_SOUTH,
    OR_WEST
  }		t_orientation;

typedef struct
{
  int		linemate;
  int		deraumere;
  int		sibur;
  int		mendiane;
  int		phiras;
  int		thystame;
  int		food;
}		t_inventory;

typedef struct
{
  int		x;
  int		y;
}		t_pos;

typedef struct
{
  char		team[TEAM_NAME_SIZE + 1];
  t_orientation	orientation;
  t_pos		position;
  t_inventory	inventory;
  unsigned int	id;
  int		level;
  int		life;
}		t_player;

t_player	*player_new();
void		player_delete(t_player *retiree);

/* done */
void		player_forward_start_cb(t_client *client, t_command *command);
void		player_forward_end_cb(t_client *client, bool error);

/* done */
void		player_right_start_cb(t_client *client, t_command *command);
void		player_right_end_cb(t_client *client, bool error);

/* done */
void		player_left_start_cb(t_client *client, t_command *command);
void		player_left_end_cb(t_client *client, bool error);

/* TODO !!! */
void		player_look_start_cb(t_client *client, t_command *command);
void		player_look_end_cb(t_client *client, bool error);

/* done */
void		player_inventory_start_cb(t_client *client, t_command *command);
void		player_inventory_end_cb(t_client *client, bool error);

/* done */
void		player_take_start_cb(t_client *client, t_command *command);
void		player_take_end_cb(t_client *client, bool error);

/* done */
void		player_drop_start_cb(t_client *client, t_command *command);
void		player_drop_end_cb(t_client *client, bool error);

/* done */
void		player_expulse_start_cb(t_client *client, t_command *command);
void		player_expulse_end_cb(t_client *client, bool error);

/* TODO !!! */
void		player_broadcast_start_cb(t_client *client, t_command *command);
void		player_broadcast_end_cb(t_client *client, bool error);

/* done */
void		player_incantation_start_cb(t_client *client, t_command *command);
void		player_incantation_end_cb(t_client *client, bool error);

void		player_fork_start_cb(t_client *client, t_command *command);
void		player_fork_end_cb(t_client *client, bool error);

void		player_connect_nbr(t_client *client, bool error);

void		player_death_cb(t_client *client, t_command *command);

/*
** end of player module
*/

/*
** start of team module
*/

typedef struct
{
  char		name[TEAM_NAME_SIZE + 1];
  t_map		player_map;
  int		nb_players;
}		t_team;

t_team		*team_new(char *name);
t_team		*team_get(char *name);
void		team_delete(char *name);

/*
** end of team module
*/

/*
** start of ground module
*/

typedef t_pos t_dim;

typedef struct
{
  t_list	players;
  t_pos		coord;
  t_inventory	ressources;
}		t_tile;

typedef struct
{
  t_tile	*world;
  t_dim		dimensions;
}		t_world;

void		world_init(int x, int y);

/*
** end of ground module
*/

/*
** start of globals
*/

t_leveler	levelers[] = {{0, 0, 0, 0, 0, 0, 0},
			      {1, 1, 0, 0, 0, 0, 0},
			      {2, 1, 1, 1, 0, 0, 0},
			      {2, 2, 0, 1, 0, 2, 0},
			      {4, 1, 1, 2, 0, 1, 0},
			      {4, 1, 2, 1, 3, 0, 0},
			      {6, 1, 2, 3, 0, 1, 0},
			      {6, 2, 2, 2, 2, 2, 1}};
t_map		*team_map;
t_map		*autoplay_team;
t_world		game_world;

/*
** end of globals
*/

void		game_turn();
void		game_init();

void		game_player_add(char *team, t_player *player);
void		game_player_remove(char *team, t_player *player);

void		game_autoplay_add_player(t_player *player);
t_player	*game_autoplay_get_player(t_player *player);

/*void		protocol_cb_*(t_client *client, t_command *command);*/

#endif
