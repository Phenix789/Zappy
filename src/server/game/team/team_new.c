/*
** team_new.c for zappy in /home/lukior/Zappy/src/game/player
**
** Made by damien vezant
** Login   <vezant_d@epitech.net>
**
** Started on  Tue May 29 06:35:21 2012 damien vezant
** Last update Tue May 29 06:59:53 2012 damien vezant
*/

#include	"game.h"

t_team		*team_new(char *name)
{
  t_team	*new_team;

  if ((new_team = calloc(1, sizeof(t_team))) == NULL)
    return (NULL);
  strcpy(new_team->name, name);
  map_add(&g_team_map, new_team->name, new_team);
  return (new_team);
}
