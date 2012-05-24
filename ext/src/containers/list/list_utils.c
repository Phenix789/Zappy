/*
** list_utils.c for extlibc in /home/epitech/c/extlibc
**
** Made by claude ramseyer
** Login   <ramsey_c@epitech.net>
**
** Started on  Mon Feb 27 10:00:00 2011 claude ramseyer
** Last update Mon Feb 27 10:00:01 2011 claude ramseyer
*/

#include "list.h"

int list_size(t_list *list)
{
  return list->size;
}

int list_empty(t_list *list)
{
  return !list->size;
}

void list_clear(t_list *list)
{
  while (list->size)
    list_pop_end(list);
}
