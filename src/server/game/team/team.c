/*
** team_new.c for zappy in /home/lukior/Zappy/src/game/player
**
** Made by damien vezant
** Login   <vezant_d@epitech.net>
**
** Started on  Tue May 29 06:35:21 2012 damien vezant
** Last update Tue May 29 06:59:53 2012 damien vezant
*/

#include <string.h>
#include	"game.h"

t_team		*team_create(char *name, int slots)
{
  t_team	*team;

  if (slots < 0 || slots > TEAM_MAX_SLOT)
    return NULL;
  if ((team = calloc(1, sizeof(t_team))) == NULL)
    return (NULL);
  logger_verbose("[GAME] Team '%s' create", name);
  strncpy(team->name, name, TEAM_NAME_SIZE);
  team->available_slots = slots;
  team->free_slots = slots;
  game_add_team(team);
  return (team);
}

void team_free(t_team *team)
{
  t_player *player;

  while ((player = list_get_begin(&team->players)))
    player_free(player);
  free(team);
}

bool team_add_player(t_team *team, t_player *player)
{
  if (team->available_slots <= 0)
    return false;
  player->team = team;
  team->available_slots--;
  list_add_end(&team->players, player);
  return true;
}

void team_remove_player(t_team *team, t_player *player)
{
  list_pop(&team->players, player);
}
