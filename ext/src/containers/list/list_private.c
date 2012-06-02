/*
** list_private.c for extlibc in /home/epitech/c/extlibc
**
** Made by claude ramseyer
** Login   <ramsey_c@epitech.net>
**
** Started on  Mon Feb 27 10:00:00 2011 claude ramseyer
** Last update Mon Feb 27 10:00:01 2011 claude ramseyer
*/

#include "list.h"

void _list_add_node(t_list *list, t_list_node *current, void *data)
{
  t_list_node *node;

  if (!current)
    list_add_begin(list, data);
  if (current->next == NULL)
    list_add_end(list, data);
  else
    {
      node = list_create_node(data);
      node->prev = current;
      node->next = current->next;
      node->next->prev = node;
      current->next = node;
      list->size++;
    }
}

void _list_pop_node(t_list *list, t_list_node *node)
{
  if (list->head == node)
    list_pop_begin(list);
  else if (list->tail == node)
    list_pop_end(list);
  else
    {
      node->next->prev = node->prev;
      node->prev->next = node->next;
      list->size--;
      list_pool_node(node);
    }
}

