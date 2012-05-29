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

void		game_init()
{
  team_map = map_create();
  autoplay_team = map_create();
  map_init(team_map);
  map_init(autoplay_team);
}
