/*
** player_right.c for zappy in /home/lukior/Zappy/src/game
** 
** Made by damien vezant
** Login   <vezant_d@epitech.net>
** 
** Started on  Tue May 29 07:44:17 2012 damien vezant
** Last update Wed May 30 14:03:07 2012 damien vezant
*/

#include	"game.h"

void		player_right_cb(t_client *client, t_command *command)
{
  (void)command;
  if (client->player->orientation != WEST)
    ++client->player->orientation;
  else
    client->player->orientation = NORTH;
}
