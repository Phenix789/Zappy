/*
** ground_init.c for zappy in /home/lukior/Zappy/src/server/game
** 
** Made by damien vezant
** Login   <vezant_d@epitech.net>
** 
** Started on  Tue May 29 21:40:29 2012 damien vezant
** Last update Wed May 30 20:00:15 2012 damien vezant
*/

#include	"game.h"

extern t_world	game_world;

static void	generate_ressources(t_tile *tile)
{
  if ((rand() % 100) < 40)
    tile->ressources.food += 1;
  if ((rand() % 100) < 30)
    tile->ressources.linemate += 1;
  if ((rand() % 100) < 25)
    tile->ressources.deraumere += 1;
  if ((rand() % 100) < 20)
    tile->ressources.sibur += 1;
  if ((rand() % 100) < 15)
    tile->ressources.mendiane += 1;
  if ((rand() % 100) < 10)
    tile->ressources.phiras += 1;
  if ((rand() % 100) < 8)
    tile->ressources.phiras += 1;
  if ((rand() % 100) < 5)
    tile->ressources.thystame += 1;
}

int		world_init(int x, int y)
{
  int		buff_len;
  int		i;

  buff_len = x * y;
  i = 0;
  if ((game_world.world = calloc(1, buff_len * sizeof(t_tile))) == NULL)
    return(-1);
  game_world.dimensions.x = 0;
  game_world.diemnsions.y = 0;
  while ( i < buff_len)
    {
      game_world.world[i].coord.x = game_world.dimensions.x++;
      game_world.world[i].coord.y = game_world.dimensions.y;
      if (pos_x == x)
	{
	  pos_x = 0;
	  pos_y++;
	}
      generate_ressources(&ground[i]);
      ++i;
    }
  return (0);
}
