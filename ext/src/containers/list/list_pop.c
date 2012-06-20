/*
** list_pop.c for extlibc in /home/epitech/c/extlibc
**
** Made by claude ramseyer
** Login   <ramsey_c@epitech.net>
**
** Started on  Mon Feb 27 10:00:00 2011 claude ramseyer
** Last update Mon Feb 27 10:00:01 2011 claude ramseyer
*/

#include "list.h"

void list_pop(t_list *list, void *data)
{
  t_list_node *node;

  if (data)
    {
      node = list->head;
      while (node)
        {
          if (node->data == data)
            {
              _list_pop_node(list, node);
              return;
            }
          node = node->next;
        }
    }
}

void list_pop_begin(t_list *list)
{
  t_list_node *node;

  if (list->head)
    {
      node = list->head;
      list->head = node->next;
      list->size--;
      if (list->head)
	list->head->prev = NULL;
      else
        list->tail = NULL;
      list_pool_node(node);
    }
}

void list_pop_end(t_list *list)
{
  t_list_node *node;

  if (list->tail)
    {
      node = list->tail;
      list->tail = node->prev;
      list->size--;
      if (list->tail)
        list->tail->next = NULL;
      else
        list->head = NULL;
      list_pool_node(node);
    }
}

void list_pop_at(t_list *list, unsigned int index)
{
  t_list_node *node;

  if (index == 0)
    list_pop_begin(list);
  else if (index == (list->size - 1))
    list_pop_end(list);
  else if (index < list->size)
    {
      node = list->head;
      while (index-- > 0)
        node = node->next;
      _list_pop_node(list, node);
    }
}

void list_pop_to(t_list *list, fpred pred)
{
  t_list_node *current;

  current = list->head;
  while (current && (*pred)(current->data))
    current = current->next;
  if (current)
    _list_pop_node(list, current);
}

void list_pop_to_param(t_list *list, fpredp pred, void *param)
{
  t_list_node *current;

  current = list->head;
  while (current && (*pred)(current->data, param))
    current = current->next;
  if (current)
    _list_pop_node(list, current);
}
