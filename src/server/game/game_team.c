/*
** game_player_remove.c for zappy in /home/lukior/Zappy/src/player
**
** Made by damien vezant
** Login   <vezant_d@epitech.net>
**
** Started on  Tue May 29 04:35:28 2012 damien vezant
** Last update Tue May 29 07:12:47 2012 damien vezant
*/

#include <string.h>
#include "game.h"

extern t_game *g_game;

static int _game_team_name_cmp(t_team *team, char *name)
{
  return strcmp(team->name, name);
}

void game_create_team(char *name)
{
  team_create(name, g_game->nb_slots);
}

void game_add_team(t_team *team)
{
  list_add_end(&g_game->teams, team);
}

t_team *game_get_team(char *name)
{
  return list_get_to_param(&g_game->teams, (fpredp) &_game_team_name_cmp, name);
}

t_list *game_get_teams()
{
  return &g_game->teams;
}
