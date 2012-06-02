/*
** player_incantation_cb.c for zappy in /home/lukior/Zappy/src/server/game
**
** Made by damien vezant
** Login   <vezant_d@epitech.net>
**
** Started on  Wed May 30 17:55:25 2012 damien vezant
** Last update Wed May 30 22:04:39 2012 damien vezant
*/

#include		"game.h"

static t_player		*my_player;
static t_leveler	levelers[] = {{0, 0, 0, 0, 0, 0, 0},
				      {1, 1, 0, 0, 0, 0, 0},
				      {2, 1, 1, 1, 0, 0, 0},
				      {2, 2, 0, 1, 0, 2, 0},
				      {4, 1, 1, 2, 0, 1, 0},
				      {4, 1, 2, 1, 3, 0, 0},
				      {6, 1, 2, 3, 0, 1, 0},
				      {6, 2, 2, 2, 2, 2, 1}};


static int	_check_level(t_player *dude)
{
  return (dude->level == my_player->level);
}

static bool	_check_players(t_list *players, int nb_players)
{
  int		cnt;

  cnt = list_count(players, (fpred)_check_level);
  if (cnt >= nb_players)
    return (true);
  return (false);
}

static bool	_check_prerequisite(t_client *client, t_tile *tile)
{
  int		level;
  t_inventory	*ressources;

  ressources = &tile->ressources;
  level = client->player->level;
  if (ressources->linemate >= levelers[level].linemate &&
      ressources->deraumere >= levelers[level].deraumere &&
      ressources->sibur >= levelers[level].sibur &&
      ressources->mendiane >= levelers[level].mendiane &&
      ressources->phiras >= levelers[level].phiras &&
      ressources->thystame >= levelers[level].thystame &&
      level < 8 &&
      _check_players(&tile->players, levelers[level].nb_players))
    return (true);
  return (false);
}

void		player_incantation_end_cb(t_client *client, int error)
{
  if (error)
    client_send(client, REP_KO);
  else
    {
      client_send(client, REP_OK);
      client->player->level += 1;
    }
}

void		player_incantation_start_cb(t_client *client, char *command)
{
  t_tile	*tile;

  (void)command;
  tile = client->player->tile;
  if (_check_prerequisite(client, tile))
    {
      client_send(client, REP_INCANTATION,
		   client->player->level);
      kernel_register_wakeup(DELAY_INCANT, (kn_wakeup_cb) player_incantation_end_cb, client);
    }
}
