
#include <string.h>
#include "list.h"
#include "kernel.h"
#include "network.h"
#include "client.h"
#include "clock.h"
#include "game.h"

static t_list *g_callback = NULL;

typedef struct s_debug_callback
{
  char name[60];
  void *addr;
} t_debug_callback;

t_debug_callback *debug_callback_create(char *name, void *addr)
{
  t_debug_callback *callback;

  if (!(callback = malloc(sizeof(t_debug_callback))))
    return NULL;
  memset(callback, 0, sizeof(t_debug_callback));
  strcpy(callback->name, name);
  callback->addr = addr;
  return callback;
}

void debug_init()
{
  g_callback = list_create();
  list_add_end(g_callback, debug_callback_create("client_consume_food", &client_consume_food));
  list_add_end(g_callback, debug_callback_create("player_forward_start_cb", &player_forward_start_cb));
  list_add_end(g_callback, debug_callback_create("player_forward_end_cb", &player_forward_end_cb));
  list_add_end(g_callback, debug_callback_create("player_right_start_cb", &player_right_start_cb));
  list_add_end(g_callback, debug_callback_create("player_right_end_cb", &player_right_end_cb));
  list_add_end(g_callback, debug_callback_create("player_left_start_cb", &player_left_start_cb));
  list_add_end(g_callback, debug_callback_create("player_left_end_cb", &player_left_end_cb));
  list_add_end(g_callback, debug_callback_create("player_look_start_cb", &player_look_start_cb));
  list_add_end(g_callback, debug_callback_create("player_look_end_cb", &player_look_end_cb));
  list_add_end(g_callback, debug_callback_create("player_inventory_start_cb", &player_inventory_start_cb));
  list_add_end(g_callback, debug_callback_create("player_inventory_end_cb", &player_inventory_end_cb));
  list_add_end(g_callback, debug_callback_create("player_take_start_cb", &player_take_start_cb));
  list_add_end(g_callback, debug_callback_create("player_take_end_cb", &player_take_end_cb));
  list_add_end(g_callback, debug_callback_create("player_drop_start_cb", &player_drop_start_cb));
  list_add_end(g_callback, debug_callback_create("player_drop_end_cb", &player_drop_end_cb));
  list_add_end(g_callback, debug_callback_create("player_expulse_start_cb", &player_expulse_start_cb));
  list_add_end(g_callback, debug_callback_create("player_expulse_end_cb", &player_expulse_end_cb));
  //list_add_end(g_callback, debug_callback_create("player_broadcast_start_cb", &player_broadcast_start_cb));
  list_add_end(g_callback, debug_callback_create("player_incantation_start_cb", &player_incantation_start_cb));
  list_add_end(g_callback, debug_callback_create("player_incantation_end_cb", &player_incantation_end_cb));
  list_add_end(g_callback, debug_callback_create("player_fork_start_cb", &player_fork_start_cb));
  list_add_end(g_callback, debug_callback_create("player_fork_end_cb", &player_fork_end_cb));
  list_add_end(g_callback, debug_callback_create("player_connect_nbr_cb", &player_connect_nbr_cb));
  list_add_end(g_callback, debug_callback_create("player_death_cb", &player_death_cb));
}

int debug_fpredp(t_debug_callback *callback, void *search)
{
  return !(callback->addr == search);
}

char *debug_get_callback_name(void *search)
{
  t_debug_callback *callback;

  if (g_callback == NULL)
    debug_init();
  callback = list_get_to_param(g_callback, (fpredp) &debug_fpredp, search);
  if (callback)
    return callback->name;
  return NULL;
}
