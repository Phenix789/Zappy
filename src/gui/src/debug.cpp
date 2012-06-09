#include <boost/thread.hpp>
#include <iostream>
#include <cstdlib>
#include "interface/gui.hpp"
#include "game.hpp"
#include "network.hpp"
#include "parser.hpp"
#include "utils.hpp"

#ifdef DEBUG
#warning "!! MODE DEBUG !! -- NO NETWORK !"

namespace game
{ // should have been declared inside ‘game’ otherwise ...
  int	debug_gui(data &data);
};

/* ----------------- LOOP ------------------- */

int	game::debug_gui(data &data)
{
  data.connection = true;

  try
    {
      Igui        *gui;

      gui = gui::create(data);
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
  catch (const gui::ex_exit &ex)
    {
      std::cout << "Fermeture de l'interface graphique - " << ex.what() << std::endl;
    }
  return (EXIT_SUCCESS);
}

/* ------------------------------------------- */

int     main_gui(const std::string __attribute__((unused))host,
		 const std::string __attribute__((unused))port)
{
  game::data    data;
  return (game::debug_gui(data));
}
#endif
