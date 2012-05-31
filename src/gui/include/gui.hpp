#ifndef __GUI_HPP_
#define __GUI_HPP_

#include <boost/thread.hpp>
#include "data_thread.hpp"
#include "Igui.hpp"
#include "game.hpp"

struct thread_gui
{
  thread_gui(data_thread &data) : _data(data) { }
  void	operator()()
  {
    game::run_gui(this->_data);
  }
public:
  data_thread	&_data;

private:
  thread_gui();
};

extern "C" Igui *create(const game::map &map);

#endif /* __GUI_HPP_ */
