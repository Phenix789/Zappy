/*
** map.h for extlibc in /home/epitech/c/extlibc
**
** Made by claude ramseyer
** Login   <ramsey_c@epitech.net>
**
** Started on  Mon Feb 27 10:00:00 2011 claude ramseyer
** Last update Mon Feb 27 10:00:01 2011 claude ramseyer
*/

#ifndef __MAP_H__
#define __MAP_H__

#include "list.h"

typedef struct s_map
{
  t_list list;
#define l_size list.size;
#define l_head list.head;
#define l_tail list.tail;
  fcmp cmp;
} t_map;

typedef struct s_map_pair
{
  void *key;
  void *value;
} t_map_pair;

typedef struct s_map_iterator
{
  t_list_iterator iterator;
} t_map_iterator;

typedef void (*fmeach)(void *, void *);
typedef void *(*fmtrans)(void *, void *);

#define M_KEY(node) (((t_map_pair *) (node->data))->key)
#define M_VALUE(node) (((t_map_pair *) (node->data))->value)

t_map_pair *map_create_pair(void *key, void *value);
t_map *map_create(fcmp cmp);
t_map *map_init(t_map *map, fcmp cmp);

int map_has(t_map *map, void *key);
void map_add(t_map *map, void *key, void *value);
void map_set(t_map *map, void *key, void *value);
void *map_get(t_map *map, void *key);
void map_pop(t_map *map, void *key);

int map_size(t_map *map);
int map_empty(t_map *map);
void map_clear(t_map *map);

void map_foreach(t_map *map, fmeach each);
void map_transform(t_map *map, fmtrans trans);
void map_ktransform(t_map *map, fmtrans trans);

#endif
