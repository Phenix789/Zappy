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

/*
** start of globals
*/

t_map		*team_map;
t_map		*autoplay_team;

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
  int		current_delay;
}		t_player;

t_player	*player_new();
void		player_delete(t_player *retiree);

void		player_forward(t_player *player);
void		player_right(t_player *player);
void		player_left(t_player *player);
/*char		*player_look(t_player *player);*/
char		*player_inventory(t_player *player);
void		player_take(t_item item, t_player *player);
int		player_drop(t_item item, t_player *player);
/*void		player_expulse(t_player *player);*/
/*void		player_broadcast(char *message, t_player *player);*/
void		player_incantation(t_player *player);
void		player_fork(t_player *player);
void		player_death(t_player *player);

/*
** end of player module
*/

/*
** start of team module
*/

typedef struct
{
  char		*name;
  t_map		*player_map;
  int		nb_players;
}		t_team;

t_team		*team_new(char *name);
t_team		*team_get(char *name);
void		team_delete(char *name);

/*
** end of team module
*/

void		game_turn();
void		game_init();

void		game_player_add(char *team, t_player *player);
void		game_player_remove(char *team, t_player *player);

void		game_autoplay_add_player(t_player *player);
t_player	*game_autoplay_get_player(t_player *player);

/*void		protocol_cb_*(t_client *client, t_command *command);*/

#endif
