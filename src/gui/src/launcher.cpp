#include "gui.hpp"

thread_gui      *game::launch_gui(data_thread &data)
{
  thread_gui    *ptr = new thread_gui(data);
  boost::thread thrd(*ptr);

  return (ptr);
}