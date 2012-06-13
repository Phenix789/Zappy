#include <iostream>
#include <cstdlib>
#include "interface/gui.hpp"
#include "interface/network.hpp"
#include "sfml.hpp"

//#ifdef DEBUG
#warning "!! MODE DEBUG !! -- NO NETWORK !"

/* ----------------- LOOP ------------------- */

int	gui::run(game::data &data, __attribute__((unused))INetwork &sock)
{
  Igui		*gui = NULL;

  data.allowConnection();
  data.map.setDim(14, 14);
  for (int i = 0; i < 50; i++)
  {
    data.map.setRess(rand() % 14, rand() % 14, game::FOOD, rand() % 14);
    data.map.setRess(rand() % 14, rand() % 14, game::DERAUMATRE, rand() % 14);
    data.map.setRess(rand() % 14, rand() % 14, game::LINEMATE, rand() % 14);
    data.map.setRess(rand() % 14, rand() % 14, game::PHIRAS, rand() % 14);
    data.map.setRess(rand() % 14, rand() % 14, game::THYSTAME, rand() % 14);
    data.map.setRess(rand() % 14, rand() % 14, game::SIBUR, rand() % 14);
    data.map.setRess(rand() % 14, rand() % 14, game::MENDIANE, rand() % 14);
    data.map.addPlayer(rand() % 14, rand() % 14, i, (game::orientation)(rand() % 4));
  }
  try
    {
      gui = gui_create(data);
      gui->init();
      gui->intro();
      while (gui->gameloop())
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
      if (gui)
	delete gui;
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
//#endif
