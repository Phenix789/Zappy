/*
** list_iter_modif.c for extlibc in /home/epitech/c/extlibc
**
** Made by claude ramseyer
** Login   <ramsey_c@epitech.net>
**
** Started on  Mon Feb 27 10:00:00 2011 claude ramseyer
** Last update Mon Feb 27 10:00:01 2011 claude ramseyer
*/

#include "list.h"

void list_iterator_add(t_list_iterator *iter, void *data)
{
  _list_add_node(iter->list, iter->node, data);
}

void *list_iterator_get(t_list_iterator *iter)
{
  return iter->node->data;
}

void list_iterator_pop(t_list_iterator *iter)
{
  t_list_node *node;

  node = iter->node;
  list_iterator_next(iter);
  _list_pop_node(iter->list, node);
  iter->pos--;
}
