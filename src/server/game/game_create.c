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

int		game_create(int x, int y, int nb_per_team)
{
  srand(getpid() * time(NULL));
  if ((g_game_world = calloc(1, sizeof(t_world))) == NULL)
    return (-1);
  g_game_world->dimensions.x = x;
  g_game_world->dimensions.y = y;
  g_game_world->connect_nbr = nb_per_team;
  return (0);
}