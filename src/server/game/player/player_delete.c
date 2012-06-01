/*
** player_delete.c for zappy in /home/lukior/Zappy/src/player
** 
** Made by damien vezant
** Login   <vezant_d@epitech.net>
** 
** Started on  Tue May 29 03:41:30 2012 damien vezant
** Last update Tue May 29 03:42:25 2012 damien vezant
*/

#include	"game.h"

void		player_delete(t_player *retiree)
{
  free(retiree);
  logger_debug("[GAME] player %ud has been deleted", retiree->id);
}
