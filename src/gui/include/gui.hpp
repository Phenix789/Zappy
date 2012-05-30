#ifndef __GUI_HPP_
#define __GUI_HPP_

#include <boost/thread.hpp>
#include "data_thread.hpp"

struct thread_gui;

namespace game
{
  void		run_gui(data_thread &data);
  thread_gui	*launch_gui(data_thread &data);
};

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



#endif /* __GUI_HPP_ */
