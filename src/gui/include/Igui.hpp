#ifndef __IGUI_HPP_
#define __IGUI_HPP_

#include "map.hpp"

class Igui
{
public:
  virtual ~Igui() {};

  virtual bool  init() = 0;
  virtual void	intro() = 0;
  virtual void	process_event() = 0;
  virtual bool	is_running() = 0;
  virtual void  draw_map() = 0;
  virtual void	end() = 0;
  virtual void  exit() = 0;
};

#endif /* __IGUI_HPP_ */
