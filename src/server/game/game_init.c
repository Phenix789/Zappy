/*
** game_init.c for zappy in /home/lukior/Zappy/src/game
**
** Made by damien vezant
** Login   <vezant_d@epitech.net>
**
** Started on  Tue May 29 07:21:02 2012 damien vezant
** Last update Fri Jun  1 02:24:48 2012 quentin duval
*/

#include	"game.h"

static int	_register_functions()
{
  if (session_register_in("avance", "%s", player_forward_start_cb) < 0 ||
      session_register_in("droite", "%s", player_right_start_cb) < 0 ||
      session_register_in("gauche", "%s", player_left_start_cb) < 0 ||
      session_register_in("voir", "%s", player_look_start_cb) < 0 ||
      session_register_in("inventaire", "%s", player_inventory_start_cb) < 0 ||
      session_register_in("prend", "%s %s", player_take_start_cb) < 0 ||
      session_register_in("pose", "%s %s", player_drop_start_cb) < 0 ||
      session_register_in("expulse", "%s", player_expulse_start_cb) < 0 ||
      session_register_in("broadcast", "%s %s", player_broadcast_start_cb) < 0 ||
      session_register_in("incantation", "%s", player_incantation_start_cb) < 0 ||
      session_register_in("fork", "%s", player_fork_start_cb) < 0 ||
      session_register_in("connect_nbr", "%s", player_connect_nbr) < 0 ||
      session_register_in("-", "%s", player_death_cb) < 0)
    return (-1);
  return (0);
}

static void	_generate_tile(t_tile *tile)
{
  tile->ressources.food += rand() % 4;
  tile->ressources.linemate += rand() % 1;
  if ((rand() % 100) < 25)
    tile->ressources.deraumere += 1;
  else if ((rand() % 100) < 20)
    tile->ressources.sibur += 1;
  else if ((rand() % 100) < 15)
    tile->ressources.mendiane += 1;
  else if ((rand() % 100) < 10)
    tile->ressources.phiras += 1;
  else if ((rand() % 100) < 5)
    tile->ressources.thystame += 1;
}

int		game_init(int x, int y, int nb_per_team)
{
  int		idx;
  int		idy;

  if (game_create(x, y, nb_per_team) == -1)
    return (-1);
  idx = 0;
  idy = 0;
  while (idy < y)
  {
    while (idx < x)
    {
      _generate_tile(&g_game_world->world[x * y]);
      ++idx;
    }
    x = 0;
    ++idy;
  }
  if (_register_functions())
    return (-1);
  return (0);
}
