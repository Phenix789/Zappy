#ifndef __IGUI_HPP_
#define __IGUI_HPP_

#include "map.hpp"

class Igui
{
public:
  virtual ~Igui() {};

  virtual bool  init() = 0;
  virtual bool	intro() = 0;
  virtual void  draw_map(const gui::map &map) = 0;
  virtual bool	end(const gui::map &map) = 0;
  virtual bool  exit() = 0;
};

extern "C" Igui	*create();

#endif /* __IGUI_HPP_ */
