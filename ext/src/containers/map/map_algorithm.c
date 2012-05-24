/*
** map_algorithm.c for extlibc in /home/epitech/c/extlibc
**
** Made by claude ramseyer
** Login   <ramsey_c@epitech.net>
**
** Started on  Mon Feb 27 10:00:00 2011 claude ramseyer
** Last update Mon Feb 27 10:00:01 2011 claude ramseyer
*/

#include "map.h"

void map_foreach(t_map *map, fmeach each)
{
  t_list_node *node;

  node = map->l_head;
  while (node)
    {
      (*each)(M_KEY(node), M_VALUE(node));
      node = node->next;
    }
}

void map_transform(t_map *map, fmtrans trans)
{
  t_list_node *node;

  node = map->l_head;
  while (node)
    {
      M_VALUE(node) = (*trans)(M_KEY(node), M_VALUE(node));
      node = node->next;
    }
}

void map_ktransform(t_map *map, fmtrans trans)
{
  t_list_node *node;

  node = map->l_head;
  while (node)
    {
      M_KEY(node) = (*trans)(M_KEY(node), M_VALUE(node));
      node = node->next;
    }
}
