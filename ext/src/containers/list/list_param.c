/*
** list_param.c for extlibc in /home/epitech/c/extlibc
**
** Made by claude ramseyer
** Login   <ramsey_c@epitech.net>
**
** Started on  Mon Feb 27 10:00:00 2011 claude ramseyer
** Last update Mon Feb 27 10:00:01 2011 claude ramseyer
*/

#include "list.h"

int list_count_param(t_list *list, fpredp pred, void *param)
{
  t_list_node *node;
  int count;

  node = list->head;
  count = 0;
  while (node)
    {
      if ((*pred)(node->data, param))
        count++;
      node = node->next;
    }
  return count ;
}

void list_foreach_param(t_list *list, feachp each, void *param)
{
  t_list_node *node;

  node = list->head;
  while (node)
    {
      (*each)(node->data, param);
      node = node->next;
    }
}

void list_transform_param(t_list *list, ftransp trans, void *param)
{
  t_list_node *node;

  node = list->head;
  while (node)
    {
      node->data = (*trans)(node->data, param);
      node = node->next;
    }
}

t_list *list_filter_param(t_list *list, fpredp pred, void *param)
{
  t_list *filter;
  t_list_node *node;

  filter = list_create();
  node = list->head;
  while (node)
    {
      if ((*pred)(node->data, param))
        list_add_end(filter, node->data);
      node = node->next;
    }
  return filter;
}
