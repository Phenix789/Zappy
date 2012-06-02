/*
** list_algorithm.c for extlibc in /home/epitech/c/extlibc
**
** Made by claude ramseyer
** Login   <ramsey_c@epitech.net>
**
** Started on  Mon Feb 27 10:00:00 2011 claude ramseyer
** Last update Mon Feb 27 10:00:01 2011 claude ramseyer
*/

#include "list.h"

int list_count(t_list *list, fpred pred)
{
  t_list_node *node;
  int count;

  node = list->head;
  count = 0;
  while (node)
    {
      if ((*pred)(node->data))
        count++;
      node = node->next;
    }
  return count ;
}

void list_foreach(t_list *list, feach each)
{
  t_list_node *node;

  node = list->head;
  while (node)
    {
      (*each)(node->data);
      node = node->next;
    }
}

void list_transform(t_list *list, ftrans trans)
{
  t_list_node *node;

  node = list->head;
  while (node)
    {
      node->data = (*trans)(node->data);
      node = node->next;
    }
}

t_list *list_filter(t_list *list, fpred pred)
{
  t_list *filter;
  t_list_node *node;

  filter = list_create();
  node = list->head;
  while (node)
    {
      if ((*pred)(node->data))
        list_add_end(filter, node->data);
      node = node->next;
    }
  return filter;
}

void **list_flatten(t_list *list)
{
  void **flatten;
  t_list_node *node;
  int i;

  if (!(flatten = malloc((list->size + 1) * sizeof(void *))))
    return NULL;
  node = list->head;
  i = 0;
  while (node)
    {
      flatten[i++] = node->data;
      node = node->next;
    }
  flatten[i] = NULL;
  return flatten;
}
