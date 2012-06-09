#ifndef __IGUI_HPP_
#define __IGUI_HPP_

#include "game.hpp"

class Igui
{
public:
  virtual ~Igui() {};

  virtual bool  init() = 0;
  virtual void	intro() = 0;
  virtual void	process_event() = 0;
  virtual bool	is_running() const = 0;
  virtual void  draw_map() = 0;
  virtual void	end() = 0;
  virtual void  exit() = 0;
};

/*
** Gui NEED game::data &data
*/
extern "C" Igui	*create(game::data &data);

#endif /* __IGUI_HPP_ */
