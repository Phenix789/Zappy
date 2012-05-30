/*
** player_left.c for zappy in /home/lukior/Zappy/src/game
** 
** Made by damien vezant
** Login   <vezant_d@epitech.net>
** 
** Started on  Tue May 29 07:46:48 2012 damien vezant
** Last update Wed May 30 14:11:38 2012 damien vezant
*/

#include	"game.h"

void		player_left_cb(t_client *client, t_command *command)
{
  (void)command;
  if (player->orientation != NORTH)
    --player->orientation;
  else
    player->orientation = WEST;
}
