/*
** list_add.c for extlibc in /home/epitech/c/extlibc
**
** Made by claude ramseyer
** Login   <ramsey_c@epitech.net>
**
** Started on  Mon Feb 27 10:00:00 2011 claude ramseyer
** Last update Mon Feb 27 10:00:01 2011 claude ramseyer
*/

#include "list.h"

void list_add_begin(t_list *list, void *data)
{
  t_list_node *node;

  node = list_create_node(data);
  node->next = list->head;
  if (list->head)
    list->head->prev = node;
  list->head = node;
  if (list->size == 0)
    list->tail = node;
  list->size++;
}

void list_add_end(t_list *list, void *data)
{
  t_list_node *node;

  node = list_create_node(data);
  node->prev = list->tail;
  if (list->tail)
    list->tail->next = node;
  list->tail = node;
  if (list->size == 0)
    list->head = node;
  list->size++;
}

void list_add_at(t_list *list, unsigned int index, void *data)
{
  t_list_node *current;

  if (list->size == 0 || index == 0)
    list_add_begin(list, data);
  else if (list->size >= index)
    list_add_end(list, data);
  else
    {
      current = list->head;
      while (--index > 0)
        current = current->next;
      _list_add_node(list, current, data);
    }
}

void list_add_to(t_list *list, fcmp cmp, void *data)
{
  t_list_node *current;

  current = list->head;
  if (!current)
    list_add_begin(list, data);
  else
    {
      while ((*cmp)(data, current->data) <= 0)
        {
          current = current->next;
          if (!current)
            {
              list_add_end(list, data);
              return;
            }
        }
      if (current->prev)
        _list_add_node(list, current->prev, data);
      else
	list_add_begin(list, data);
    }
}
