/*
** map_operation.c for extlibc in /home/epitech/c/extlibc
**
** Made by claude ramseyer
** Login   <ramsey_c@epitech.net>
**
** Started on  Mon Feb 27 10:00:00 2011 claude ramseyer
** Last update Mon Feb 27 10:00:01 2011 claude ramseyer
*/

#include "map.h"

int map_has(t_map *map, void *key)
{
  t_list_node *node;

  node = map->l_head;
  while (node)
    {
      if ((*map->cmp)(M_KEY(node), key))
        return 1;
      node = node->next;
    }
  return 0;
}

void map_add(t_map *map, void *key, void *value)
{
  if (!map_has(map, key))
    list_add_end(&map->list, map_create_pair(key, value));
  else
    map_set(map, key, value);
}

void map_set(t_map *map, void *key, void *value)
{
  t_list_node *node;

  node = map->l_head;
  while (node)
    {
      if ((*map->cmp)(M_KEY(node), key))
        {
          M_VALUE(node) = value;
          return ;
        }
      node = node->next;
    }
}

void *map_get(t_map *map, void *key)
{
  t_list_node *node;

  node = map->l_head;
  while (node)
    {
      if ((*map->cmp)(M_KEY(node), key))
	return M_VALUE(node);
      node = node->next;
    }
  return NULL;
}

void map_pop(t_map *map, void *key)
{
  t_list_node *node;

  node = map->l_head;
  while (node)
    {
      if ((*map->cmp)(M_KEY(node), key))
        {
          _list_pop_node(&map->list, node);
          return ;
        }
      node = node->next;
    }
}
