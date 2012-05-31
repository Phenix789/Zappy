#include "gui.hpp"

thread_gui	*game::launch_gui(data_thread &data)
{
  thread_gui	*ptr = new thread_gui(data);
  boost::thread	thrd(*ptr);

  return (ptr);
}

void	game::run_gui(data_thread &data)
{
  std::cout << "In another thread !" << std::endl;
}
