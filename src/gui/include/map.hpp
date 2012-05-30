#ifndef __MAP_HPP_
#define __MAP_HPP_

#include <vector>
#include <list>
#include "player.hpp"

namespace game
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

  class map
  {
  public:
    map();
    ~map();

  public:
    void	add_ress(unsigned int x, unsigned int y, ress type);
    void	rm_ress(unsigned int x, unsigned int y, ress type);
    void	add_player(unsigned int x, unsigned int y, int num_pl);
    void	rm_player(int num_pl);
    void	setDim(unsigned int x, unsigned int y);
    const std::vector<int>		getTile() const;
    const std::list<game::player>	getPlayer() const;

  private:
    unsigned int                size_x;
    unsigned int                size_y;
    std::vector<int>		_case;
    std::list<game::player>	_players;
  };
}

#endif /* __MAP_HPP_ */
