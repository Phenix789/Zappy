/*
** map.c for extlibc in /home/epitech/c/extlibc
**
** Made by claude ramseyer
** Login   <ramsey_c@epitech.net>
**
** Started on  Mon Feb 27 10:00:00 2011 claude ramseyer
** Last update Mon Feb 27 10:00:01 2011 claude ramseyer
*/

#include "map.h"

t_map_pair *map_create_pair(void *key, void *value)
{
  t_map_pair *pair;

  if ((pair = malloc(sizeof(t_map_pair))) == NULL)
    return NULL;
  pair->key = key;
  pair->value = value;
  return pair;
}

t_map *map_create(fcmp cmp)
{
  t_map *map;

  if ((map = malloc(sizeof(t_map))) == NULL)
    return NULL;
  return map_init(map, cmp);
}

t_map *map_init(t_map *map, fcmp cmp)
{
  list_init(&map->list);
  map->cmp = cmp;
  return map;
}
