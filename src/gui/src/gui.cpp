#include <boost/thread.hpp>
#include "gui.hpp"

void	game::run_gui(data_thread &data)
{
  Igui	*gui;

  gui = create(data.map);
  gui->init();
  while (gui->is_running())
    {
      data.lock();
      gui->process_event();
      gui->draw_map();
      data.unlock();
      boost::this_thread::sleep(boost::posix_time::milliseconds(50));
    }
  gui->exit();
}
