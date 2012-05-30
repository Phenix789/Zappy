/*
** ground_init.c for zappy in /home/lukior/Zappy/src/server/game
** 
** Made by damien vezant
** Login   <vezant_d@epitech.net>
** 
** Started on  Tue May 29 21:40:29 2012 damien vezant
** Last update Wed May 30 01:11:29 2012 damien vezant
*/

#include	"game.h"

extern t_ground	*ground;

int		ground_init(int x, int y)
{
  int		buff_len;
  int		i;

  buff_len = x * y;
  i = 0;
  if ((ground = calloc(1, buff_len * sizeof(t_tile))) == NULL)
    return(-1);
  while ( i < buff_len)
    {
      
      ++i;
    }
}
