#ifndef __GAME_MAP_HPP_
#define __GAME_MAP_HPP_

#include <vector>
#include <list>
#include "player.hpp"
#include "tiles.hpp"

namespace game
{

  class map
  {
  public:
    map();
    ~map();

  public:
    int                         size_x;
    int                         size_y;
    std::vector<tiles>          _tiles;
    std::list<game::player>     _players;

  public:
    void                                setRess(int x, int y, ress type, int nb);
    void                                addPlayer(int x, int y, int num_pl, orientation orient);
    void                                rmPlayer(int num_pl);
    void                                setDim(int x, int y);
    const tiles                         &getTile(int x, int y) const;
    const std::list<game::player>       getPlayer() const;

  private:
    void                                set_tile(tiles _tile, ress type, unsigned int nb);
    
  private:
    map(const map &other);
  };
};

#endif /* __GAME_MAP_HPP_ */
