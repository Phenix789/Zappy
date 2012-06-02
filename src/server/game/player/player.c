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

t_player		*player_create(t_team *team, int x, int y)
{
  static int	id = 0;
  t_player		*player;

  if (team->available_slots <= 0)
    return NULL;
  if ((player = calloc(1, sizeof(t_player))) == NULL)
    return (NULL);
  logger_verbose("[GAME] New player %i from team %s", id, team->name);
  player->id = id++;
  player->inventory.food = 10;
  team_add_player(team, player);
  world_add_player(player, x, y);
  return (player);
}

void player_free(t_player *player)
{
  logger_message("[GAME] Player %i is dead", player->id);
  team_remove_player(player->team, player);
  world_remove_player(player);
  free(player);
}
