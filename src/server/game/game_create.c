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

int		game_create(int x, int y, int connect_nbr)
{
  int		bufflen;
  int		idx;

  srand(getpid() * time(NULL));
  bufflen = x * y;
  if ((game_world = calloc(1, sizeof(t_world))) == NULL)
    return (-1);
  game_world->dimensions.x = x;
  game_world->dimensions.y = y;
  game_world->connect_nbr = connect_nbr;
  return (0);
}