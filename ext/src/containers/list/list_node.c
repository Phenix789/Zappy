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

#ifdef __LIST_POOL_NODE
static t_list *g_node_pool = NULL;
#endif

t_list_node *list_create_node(void *data)
{
  t_list_node *node;

#ifdef __LIST_POOL_NODE
  if (!g_node_pool)
    g_node_pool = list_create();
  if (g_node_pool->size > 0)
    {
      node = g_node_pool->head;
      g_node_pool->head = g_node_pool->head->next;
      g_node_pool->size--;
    }
  else if ((node = malloc(sizeof(t_list_node))) == 0)
#else
  if ((node = malloc(sizeof(t_list_node))) == 0)
#endif
    return NULL;
  node->data = data;
  node->prev = NULL;
  node->next = NULL;
  return node;
}

void list_pool_node(t_list_node *node)
{
#ifdef __LIST_POOL_NODE
  if (g_node_pool->size < LIST_POOL_SIZE)
    {
      if (g_node_pool->size > 0)
	g_node_pool->tail->next = node;
      else
	g_node_pool->head = node;
      node->prev = g_node_pool->tail;
      node->next = NULL;
      g_node_pool->tail = node;
      g_node_pool->size++;
    }
  else
#endif
    free(node);
}
