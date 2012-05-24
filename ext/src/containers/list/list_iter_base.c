/*
** list_iter_base.c for extlibc in /home/epitech/c/extlibc
**
** Made by claude ramseyer
** Login   <ramsey_c@epitech.net>
**
** Started on  Mon Feb 27 10:00:00 2011 claude ramseyer
** Last update Mon Feb 27 10:00:01 2011 claude ramseyer
*/

#include "list.h"

t_list_iterator *list_iterator_begin(t_list *list)
{
  t_list_iterator *iter;

  if ((iter = malloc(sizeof(t_list_iterator))) == 0)
    return NULL;
  iter->list = list;
  iter->node = list->head;
  iter->pos = 0;
  return iter;
}

t_list_iterator *list_iterator_end(t_list *list)
{
  t_list_iterator *iter;

  if ((iter = malloc(sizeof(t_list_iterator))) == 0)
    return NULL;
  iter->list = list;
  iter->node = list->tail;
  iter->pos = list->size - 1;
  return iter;
}

int list_iterator_next(t_list_iterator *iter)
{
  if (iter->node->next == NULL)
    return EXIT_FAILURE;
  else
    {
      iter->node = iter->node->next;
      iter->pos++;
      return EXIT_SUCCESS;
    }
}

int list_iterator_prev(t_list_iterator *iter)
{
  if (iter->node->prev == NULL)
    return EXIT_FAILURE;
  else
    {
      iter->node = iter->node->prev;
      iter->pos--;
      return EXIT_SUCCESS;
    }
}

void list_iterator_destroy(t_list_iterator *iter)
{
  free(iter);
}
