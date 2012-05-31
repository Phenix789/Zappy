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

  res = rand() % 100;
  if (res < 40)
    tile->ressources.food += 1;
  else if (res < 65)
    tile->ressources.linemate += 1;
  else if (res < 75)
    tile->ressources.deraumere += 1;
  else if (res < 85)
    tile->ressources.sibur += 1;
  else if (res < 90)
    tile->ressources.mendiane += 1;
  else if (res < 95)
    tile->ressources.phiras += 1;
  else
    tile->ressources.thystame += 1;
}

void		game_init()
{
  int		x;
  int		y;
  int		idx;
  int		idy;

  x = game_world->dimensions.x;
  y = game_world->dimensions.y;
  idx = 0;
  idy = 0;
  while (idy < y)
  {
    while (idx < x)
    {
      _generate_tile(&game_world->world[x * y]);
      ++x;
    }
    x = 0;
    ++y;
  }
}
