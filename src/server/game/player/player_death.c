/*
** player_death.c for zappy in /home/lukior/Zappy/src/game
** 
** Made by damien vezant
** Login   <vezant_d@epitech.net>
** 
** Started on  Tue May 29 08:22:26 2012 damien vezant
** Last update Tue May 29 08:26:49 2012 damien vezant
*/

#include	"game.h"

void		player_death_cb(t_client *client, t_command *command)
{
  (void)command;
  logger_verbose("[GAME] player %ud is dead", client->player->id);
  session_send(client, REP_DEATH);
}
