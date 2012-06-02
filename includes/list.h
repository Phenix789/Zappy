/*
** list.h for extlibc in /home/epitech/c/extlibc
**
** Made by claude ramseyer
** Login   <ramsey_c@epitech.net>
**
** Started on  Mon Feb 27 10:00:00 2011 claude ramseyer
** Last update Mon Feb 27 10:00:01 2011 claude ramseyer
*/

#ifndef __LIST_H__
#define __LIST_H__

#include <stdlib.h>

#define LIST_POOL_SIZE 1024

typedef struct s_list_node {
	void *data;
	struct s_list_node *prev;
	struct s_list_node *next;
} t_list_node;

typedef struct s_list {
	unsigned int size;
	t_list_node *head;
	t_list_node *tail;
} t_list;

typedef struct s_list_iterator {
	t_list *list;
	t_list_node *node;
	unsigned int pos;
} t_list_iterator;

typedef int (*fcmp)(void *, void *);
typedef int (*fpred)(void *);
typedef void (*feach)(void *);
typedef void* (*ftrans)(void *);

typedef int (*fcmpp)(void *, void *, void *);
typedef int (*fpredp)(void *, void *);
typedef void (*feachp)(void *, void *);
typedef void* (*ftransp)(void *, void *);

void _list_add_node(t_list *list, t_list_node *current, void *data);
void _list_pop_node(t_list *list, t_list_node *node);

t_list_node *list_create_node(void *data);
void list_pool_node(t_list_node *node);

t_list *list_create();
t_list *list_init(t_list *list);

void list_add_begin(t_list *list, void *data);
void list_add_end(t_list *list, void *data);
void list_add_at(t_list *list, unsigned int index, void *data);
void list_add_to(t_list *list, fcmp cmp, void *data);
void list_add_to_param(t_list *list, fcmpp cmp, void *data, void *param);

void *list_get_begin(t_list *list);
void *list_get_end(t_list *list);
void *list_get_at(t_list *list, unsigned int index);
void *list_get_to(t_list *list, fpred pred);
void *list_get_to_param(t_list *list, fpredp pred, void *param);

void list_pop(t_list *list, void *data);
void list_pop_begin(t_list *list);
void list_pop_end(t_list *list);
void list_pop_at(t_list *list, unsigned int index);
void list_pop_to(t_list *list, fpred pred);
void list_pop_to_param(t_list *list, fpredp pred, void *param);

int list_size(t_list *list);
int list_empty(t_list *list);
void list_clear(t_list *list);
void list_free(t_list *list);

int list_count(t_list *list, fpred pred);
void list_foreach(t_list *list, feach each);
void list_transform(t_list *list, ftrans trans);
t_list *list_filter(t_list *list, fpred pred);

int list_count_param(t_list *list, fpredp pred, void *param);
void list_foreach_param(t_list *list, feachp each, void *param);
void list_transform_param(t_list *list, ftransp trans, void *param);
t_list *list_filter_param(t_list *list, fpredp pred, void *param);

t_list_iterator *list_iterator_begin(t_list *list);
t_list_iterator *list_iterator_end(t_list *list);
int list_iterator_next(t_list_iterator *iter);
int list_iterator_prev(t_list_iterator *iter);
void list_iterator_add(t_list_iterator *iter, void *data);
void *list_iterator_get(t_list_iterator *iter);
void list_iterator_pop(t_list_iterator *iter);
void list_iterator_destroy(t_list_iterator *iter);

#endif
