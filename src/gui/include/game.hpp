#ifndef __GAME_HPP_
#define __GAME_HPP_

class data_thread;
class thread_gui;

namespace game
{
  void          run_gui(data_thread &data);
  thread_gui    *launch_gui(data_thread &data);
};

#endif /* __GAME_HPP_ */
