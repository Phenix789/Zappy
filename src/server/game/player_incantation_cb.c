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

extern t_world		game_world;

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

static bool	_check_players(t_list *players, int level, t_player *player, int nb_players)
{
  int		cnt;
  int		idx;

  idx = 0;
  cnt = list_count(players, _check_level);
  if (cnt >= nb_players)
    return (true);
  return (false);
}

static bool	_check_prerequisite(t_client *client, t_tile *tile)
{
  int		level;
  t_inventory	*ressources;

  ressources = tile->ressources;
  level = client->player.level;
  if (ressources->linemate >= levelers[level].linemate &&
      ressources->deraumere >= levelers[level].deraumere &&
      ressources->sibur >= levelers[level].sibur &&
      ressources->mendiane >= levelers[level].mendiane &&
      ressources->phiras >= levelers[level].phiras &&
      ressources->thystame >= levelers[level].thystame &&
      level < 8 &&
      _check_players(&tile->players, level, client->player, levelers[level].nb_players))
    return (true);
  return (false);
}

void		player_incantation_end_cb(t_client *client, int error)
{
  if (error)
    session_send(client, REP_KO);
  else
    {
      session_send(client, REP_OK);
      client->player.level += 1;
    }
}

void		player_incantation_start_cb(t_client *client, t_command *command)
{
  t_tile	*tile;

  tile = game_world.world[client->player.position.x * client->player.position.y];
  if (_check_prerequisite(client, tile))
    {
      session_send(client, REP_INCANTATION,
		   client->player.level);
      register_wakeup(DELAY_INCANT, player_incantation_end_cb, client);
    }
}
