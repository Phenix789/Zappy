/*
** list.c for extlibc in /home/epitech/c/extlibc
**
** Made by claude ramseyer
** Login   <ramsey_c@epitech.net>
**
** Started on  Mon Feb 27 10:00:00 2011 claude ramseyer
** Last update Mon Feb 27 10:00:01 2011 claude ramseyer
*/

#include "list.h"

t_list *list_create()
{
  t_list *list;

  if ((list = malloc(sizeof(t_list))) == 0)
    return NULL;
  return list_init(list);
}

t_list *list_init(t_list *list)
{
  list->size = 0;
  list->head = NULL;
  list->tail = NULL;
  return list;
}
