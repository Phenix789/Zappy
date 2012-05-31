/*
** game_init.c for zappy in /home/lukior/Zappy/src/game
**
** Made by damien vezant
** Login   <vezant_d@epitech.net>
**
** Started on  Tue May 29 07:21:02 2012 damien vezant
** Last update Tue May 29 07:22:05 2012 damien vezant
*/

#include	"game.h"

static void	_generate_tile(t_tile *tile)
{
  unsigned int	res;

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
    return (0);
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
  return (1);
}
