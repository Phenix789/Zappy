/**
 *
 *
 *
 */

#ifndef		__GAME_H__
# define	__GAME_H__

# include	<stdlib.h>
# include	<stdio.h>
# include	<string.h>
# include	"map.h"

# define	TEAM_NAME_SIZE	512

/*
** start of globals
*/

t_map		*team_map;
t_map		*autoplay_team;
t_ground	*ground;

/*
** end of globals
*/

typedef enum
  {
    LINEMATE,
    DERAUMERE,
    SIBUR,
    MENDIANE,
    PHIRAS,
    THYSTAME,
    FOOD
  }		t_item;

/*
** start of player module
*/

typedef enum
  {
    NORTH,
    EAST,
    SOUTH,
    WEST
  }	t_orientation;

typedef struct
{
  int	food;
  int	linemate;
  int	deraumere;
  int	sibur;
  int	mendiane;
  int	phiras;
  int	thystame;
}	t_inventory;

typedef struct
{
  int	x;
  int	y;
}	t_pos;

typedef struct
{
  char		*team;
  t_orientation	orientation;
  t_pos		position;
  t_inventory	inventory;
  unsigned int	id;
  int		level;
  int		life;
  int		current_delay;
}		t_player;

t_player	*player_new();
void		player_delete(t_player *retiree);

void		player_forward_cb(t_client *args, t_command *command);
void		player_right_cb(t_client *args, t_command *command);
void		player_left_cb(t_client *args, t_command *command);
void		player_look_cb(t_client *args, t_command *command);
void		player_inventory_cb(t_client *args, t_command *command);
void		player_take_cb(t_client *args, t_command *command);
void		player_drop_cb(t_client *args, t_command *command);
void		player_expulse_cb(t_client *args, t_command *command);
void		player_broadcast_cb(t_client *args, t_command *command);
void		player_incantation_cb(t_client *args, t_command *command);
void		player_fork_cb(t_client *args, t_command *command);
void		player_death_cb(t_client *args, t_command *command);

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

typedef struct
{
  t_list	players;
  t_pos		coord;
  t_inventory	ressources;
}		t_tile;

typedef struct
{
  t_tile	*tiles;
  t_pos		dimensions;
}		t_ground;

void		ground_init(int x, int y);

/*
** end of ground module
*/

void		game_turn();
void		game_init();

void		game_player_add(char *team, t_player *player);
void		game_player_remove(char *team, t_player *player);

void		game_autoplay_add_player(t_player *player);
t_player	*game_autoplay_get_player(t_player *player);

/*void		protocol_cb_*(t_client *client, t_command *command);*/

#endif
