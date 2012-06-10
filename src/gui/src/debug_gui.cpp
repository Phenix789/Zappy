#ifdef DEBUG

#include <iostream>
#include <cstdlib>
#include "interface/gui.hpp"
#include "interface/network.hpp"

#warning "!! MODE DEBUG !! -- NO NETWORK !"

/* ----------------- LOOP ------------------- */

int	gui::run(game::data &data, __attribute__((unused))INetwork &sock)
{
  data.connection = true;

  try
    {
      Igui        *gui;

      gui = gui_create(data);
      gui->init();
      gui->intro();
      while (gui->is_running() && data.connection)
	{
	  gui->process_event();
	  gui->draw_map();
	}
      gui->end();
      gui->exit();
      delete gui;
    }
  catch (const gui::except &ex)
    {
      std::cout << "Fermeture de l'interface graphique - " << ex.what() << std::endl;
    }
  return (EXIT_SUCCESS);
}

/* ------------------------------------------- */

int     gui::main(const std::string __attribute__((unused))host,
		  const std::string __attribute__((unused))port)
{
  game::data    data;
  INetwork	*sock = network_create();
  int		res;

  res = gui::run(data, *sock);
  delete sock;
  return (res);
}
#endif
