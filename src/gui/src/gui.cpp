#include <unistd.h>
#include <cstdlib>
#include "game.hpp"
#include "network.hpp"
#include "IGui.hpp"

int	game::run_gui(data &data, Network &sock)
{
  Igui	*gui;

  gui = create(data);
  gui->init();
  while (gui->is_running())
    {
      gui->process_event();
      gui->draw_map();
      usleep(50000);
    }
  gui->exit();
  return (EXIT_SUCCESS);
}
