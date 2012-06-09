#include <boost/thread.hpp>
#include <iostream>
#include <cstdlib>
#include "interface/gui.hpp"
#include "game.hpp"
#include "network.hpp"
#include "parser.hpp"

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

  {
    Igui        *gui;

    gui = create(data);
    gui->init();
    gui->intro();
    while (gui->is_running() && data.connection)
      {
        gui->process_event();
        gui->draw_map();
	boost::this_thread::sleep(boost::posix_time::milliseconds(50));
      }
    gui->end();
    gui->exit();
    delete gui;
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
