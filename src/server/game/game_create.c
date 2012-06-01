/*
** game_init.c for zappy in /home/lukior/Zappy/src/game
**
** Made by damien vezant
** Login   <vezant_d@epitech.net>
**
** Started on  Tue May 29 07:21:02 2012 damien vezant
** Last update Fri Jun  1 02:27:29 2012 quentin duval
*/

#include	"game.h"

int		game_create(int x, int y, int nb_per_team)
{
  srand(getpid() * time(NULL));
  if ((g_game_world = calloc(1, sizeof(t_world))) == NULL)
    return (-1);
  g_game_world->dimensions.x = x;
  g_game_world->dimensions.y = y;
  if (!(g_game_world->world = calloc(x * y, sizeof(t_tile))))
    return (-1);
  g_game_world->connect_nbr = nb_per_team;
  return (0);
}
