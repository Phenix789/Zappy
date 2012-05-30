#ifndef __MAP_HPP_
#define __MAP_HPP_

#include <list>
#include "player.hpp"

namespace map
{
  enum	ress
    {
      LINEMATE = 1,
      DERAUMATRE = 2,
      SIBUR = 4,
      MENDIANE = 8,
      PHIRAS = 16,
      THYSTAME = 32,
      FOOD = 64
    };

  typedef struct	s_case
  {
    ress		obj;
  }			t_case;

  class map
  {
  public:
    map(unsigned int x, unsigned int y);
    ~map();

  public:
    void        draw_map();
    void        set_case_state(size_t x, size_t y, ress type);

  private:
    void        draw_background();
    void        draw_gui();
    void        draw_info();
    void        draw_case();
    void        draw_player();

  private:
    unsigned int                size_x;
    unsigned int                size_y;
    std::list<t_case>           _case;
    std::list<player>		  _players;

  private:
    map();
  };
}

#endif /* __MAP_HPP_ */
