/*
** player_new.c for zappy in /home/lukior/Zappy/src/player
** 
** Made by damien vezant
** Login   <vezant_d@epitech.net>
** 
** Started on  Tue May 29 03:16:17 2012 damien vezant
** Last update Tue May 29 07:13:17 2012 damien vezant
*/

#include		"game.h"

t_player		*player_new()
{
  static unsigned int	last_id = 0;
  t_player		*newcomer;

  if ((newcomer = calloc(1, sizeof(t_player))) == NULL)
    return (NULL);
  newcomer->inventory.food = 10;
  newcomer->id = last_id++;
  return (newcomer);
}
