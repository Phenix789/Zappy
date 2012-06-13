#include <iostream>
#include "game.hpp"

namespace game
{
  map::map() : size_x(-1), size_y(-1)
  { }

  map::~map()
  { }

  void  map::setRess(int x, int y, ress type, int nb)
  {
    unsigned int	pos;

    pos = x * this->size_x * y;
    if (pos > this->_tiles.size())
      {
	std::cerr << "game::map::setRess : Taille invalide (" << pos << ") - " ;
	std::cerr << x << "/" << y << std::endl;
      }
    else
      this->_tiles.at(pos).set(type, nb);
  }

  void  map::addPlayer(int x, int y, int num_pl, orientation orient)
  {
    std::list<game::player>::iterator   it;

    it = this->_players.begin();
    while (it != this->_players.end())
      {
	if ((it)->number == num_pl)
	  {
	    std::cerr << "game::map::addPlayer : Player " << num_pl << " existe déja" << std::endl;
	    return ;
	  }
      }
    this->_players.push_back(player(x, y, num_pl, orient));
  }

  void  map::rmPlayer(int num_pl)
  {
    std::list<game::player>::iterator   it;

    it = this->_players.begin();
    while (it != this->_players.end())
      {
	if ((it)->number == num_pl)
	  {
	    this->_players.erase(it);
	    return ;
	  }
      }
    std::cerr << "game::map::rmPlayer : Player " << num_pl << " existe déja" << std::endl;
  }

  void  map::setDim(int x, int y)
  {
    this->size_x = x;
    this->size_y = y;
    this->_tiles.resize(x * y);
  }
  const std::vector<tiles>        map::getTile() const
  {
    return (this->_tiles);
  }

  const std::list<game::player> map::getPlayer() const
  {
    return (this->_players);
  }
}
