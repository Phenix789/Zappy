
#include "test.h"

void test_list_dump(int *value)
{
  logger_verbose("Value : %i", *value);
}

int test_list_add_to_fcmp(int *a, int *b)
{
  return *b - *a;
}

int test_list_size(t_list *list)
{
  t_list_node *node;
  int size;

  node = list->head;
  size = 0;
  while (node)
    {
      size++;
      node = node->next;
    }
  return size;
}

void test_list_add_begin(int count)
{
  t_list *list;
  int *value;

  logger_verbose("Create list and add %i elements to begin", count);
  list = list_create();
  while (count > 0)
    {
      value = malloc(sizeof(int));
      *value = count;
      list_add_begin(list, value);
      count--;
    }
  logger_verbose("Dump list %i :", list_size(list));
  list_foreach(list, (feach) &test_list_dump);
  list_free(list);
  free(list);
}

void test_list_add_end(int count)
{
  t_list *list;
  int *value;

  logger_verbose("Create list and add %i elements to end", count);
  list = list_create();
  while (count > 0)
    {
      value = malloc(sizeof(int));
      *value = count;
      list_add_end(list, value);
      count--;
    }
  logger_verbose("Dump list %i :", list_size(list));
  list_foreach(list, (feach) &test_list_dump);
  list_free(list);
  free(list);
}

void test_list_add_to(int count)
{
  t_list *list;
  int *value;

  logger_verbose("Create list and add %i element by insertion", count);
  list = list_create();
  srand(count);
  while (count > 0)
    {
      value = malloc(sizeof(int));
      *value = rand();
      list_add_to(list, (fcmp) &test_list_add_to_fcmp, value);
      count--;
    }
  logger_verbose("Dump list %i :", list_size(list));
  list_foreach(list, (feach) &test_list_dump);
  list_free(list);
  free(list);
}

void test_list_random_add_pop(int count)
{
  t_list *list;
  int *value;

  logger_verbose("Create list and performs %i operations", count);
  list = list_create();
  srand(count);
  while (count > 0)
    {
      logger_verbose("Loop %i", count);
      if (rand() % 2)
	{
	  value = malloc(sizeof(int));
	  *value = rand();
	  logger_verbose("Add sorted element %i", *value);
	  list_add_to(list, (fcmp) &test_list_add_to_fcmp, value);
	}
      else
	{
	  value = list_get_begin(list);
	  if (value)
	    logger_verbose("Remove first element %i", *value);
	  else
	    logger_verbose("Any element to remove");
	  list_pop_begin(list);
	  free(value);
	}
      count--;
      logger_verbose("Dump list %i (%p:%p):", list_size(list), list->head, list->tail);
      list_foreach(list, (feach) &test_list_dump);
      logger_verbose("Check size");
      if (list_size(list) != test_list_size(list))
	{
	  logger_verbose("Error size!! %i != %i", list_size(list), test_list_size(list));
	  count = 0;
	}
    }
  logger_verbose("Dump list %i (%p:%p):", list_size(list), list->head, list->tail);
  list_foreach(list, (feach) &test_list_dump);
  list_free(list);
  free(list);
}
