#ifdef DEBUG

#include <iostream>
#include <cstdlib>
#include "interface/gui.hpp"
#include "interface/network.hpp"

#warning "!! MODE DEBUG !! -- NO NETWORK !"

/* ----------------- LOOP ------------------- */

int	gui::run(game::data &data, __attribute__((unused))INetwork &sock)
{
  Igui		*gui = NULL;

  data.allowConnection();
  data.map.setDim(10, 10);
  try
    {
      gui = gui_create(data);
      gui->init();
      gui->intro();
      while (gui->is_running() && !data)
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

  catch (const network::except &ex)
    {
      if (gui)
	delete gui;
      std::cout << "Perte de la connexion - " << ex.what() << std::endl;
      return (EXIT_FAILURE);
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
