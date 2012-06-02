/*
** list_get.c for extlibc in /home/epitech/c/extlibc
**
** Made by claude ramseyer
** Login   <ramsey_c@epitech.net>
**
** Started on  Mon Feb 27 10:00:00 2011 claude ramseyer
** Last update Mon Feb 27 10:00:01 2011 claude ramseyer
*/

#include "list.h"

void *list_get_begin(t_list *list)
{
  if (list->head)
    return list->head->data;
  return NULL;
}

void *list_get_end(t_list *list)
{
  if (list->tail)
    return list->tail->data;
  return NULL;
}

void *list_get_at(t_list *list, unsigned int index)
{
  t_list_node *current;

  if (list->size <= index)
    return NULL;
  current = list->head;
  while (index-- > 0)
    current = current->next;
  return current->data;
}

void *list_get_to(t_list *list, fpred pred)
{
  t_list_node *current;

  current = list->head;
  while (current && (*pred)(current->data))
    current = current->next;
  if (current)
    return current->data;
  return NULL;
}

void *list_get_to_param(t_list *list, fpredp pred, void *param)
{
  t_list_node *current;

  current = list->head;
  while (current && (*pred)(current->data, param))
    current = current->next;
  if (current)
    return current->data;
  return NULL;
}
