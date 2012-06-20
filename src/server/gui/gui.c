
#include "gui.h"

t_gui_manager * g_gui_manager = NULL;

bool gui_init()
{
  if (!(g_gui_manager = malloc(sizeof(t_gui_manager))))
    return false;
  list_init(&g_gui_manager->guis);
  return true;
}

void gui_connect(t_gui *gui)
{
  logger_verbose("[GUI] New Client GUI connected");
  gui->exec = &gui_execute;
  list_add_end(&g_gui_manager->guis, gui);
/*
  gui_command_msz(gui, NULL);
  gui_command_sgt(gui, NULL);
  gui_command_mct(gui, NULL);
  gui_command_tna(gui, NULL);
  gui_command_pnw(gui, NULL);
  gui_command_enw(gui, NULL);
*/
}

void gui_execute(t_gui *gui, char *command)
{
  (void) gui;
  (void) command;
  logger_verbose("[GUI] Recieve command '%s' for gui", command);
}

void gui_destroy()
{
  list_clear(&g_gui_manager->guis);
  free(g_gui_manager);
  g_gui_manager = NULL;
}
