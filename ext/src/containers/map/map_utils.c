/*
** map_utils.c for extlibc in /home/epitech/c/extlibc
**
** Made by claude ramseyer
** Login   <ramsey_c@epitech.net>
**
** Started on  Mon Feb 27 10:00:00 2011 claude ramseyer
** Last update Mon Feb 27 10:00:01 2011 claude ramseyer
*/

#include "map.h"

int map_size(t_map *map)
{
  return list_size(&map->list);
}

int map_empty(t_map *map)
{
  return list_empty(&map->list);
}

void map_clear(t_map *map)
{
  list_foreach(&map->list, &free);
  list_clear(&map->list);
}
