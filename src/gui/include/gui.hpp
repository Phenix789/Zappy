#ifndef __GUI_HPP_
#define __GUI_HPP_

#include <list>
#include "map.hpp"

namespace gui
{
  class t_map
  {
  public:
    map(unsigned int x, unsigned int y);
    ~map();

  public:
    void	draw_map();
    void	set_case_state(size_t x, size_t y, ress type);

  private:
    void	draw_background();
    void	draw_gui();
    void	draw_info();
    void	draw_case();
    void	draw_player();

  private:
    unsigned int		size_x;
    unsigned int		size_y;
    std::list<t_case>		_case;
    std::list<t_players>	_players;

  private:
    map();
  };
};


#endif /* __GUI_HPP_ */
