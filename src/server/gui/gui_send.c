
#include "gui.h"

extern t_gui_manager *g_gui_manager;

int gui_send(t_gui *gui, char *msg)
{
  return client_send(gui, msg);
}

void gui_send_all(char *msg)
{
  list_foreach_param(&g_gui_manager->guis, (feachp) &gui_send, msg);
}
