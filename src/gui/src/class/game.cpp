#include <string>
#include <iostream>
#include "game.hpp"

namespace game
{
  player::player(int x, int y, int num) : number(num), pos_x(x), pos_y(y)
  { }

  player::~player()
  { }


  data::data() : connection(false)
  { }

  data::~data()
  { }

  bool	data::msg_to_send()
  {
    if (this->ask.size() > 0)
      return (true);
    return (false);
  }

  void	data::send_msg(const std::string &str)
  {
    this->ask.push_back(str);
  }

  tiles::tiles()
  {
    for (int i = 0; i < 7; i++)
      this->ressources[i] = 0;
  }

  map::map() : size_x(-1), size_y(-1)
  { }

  map::~map()
  { }

#warning "a refaire (plusieures même pierres par cases)"
  void  map::set_ress(unsigned int x, unsigned int y, ress type, unsigned int nb)
  {
  }

  void  map::add_player(unsigned int x, unsigned int y, int num_pl)
  {
    std::list<game::player>::iterator   it;

    it = this->_players.begin();
    while (it != this->_players.end())
      {
	if ((it)->number == num_pl)
	  {
	    std::cerr << "game::map::add_player : Player " << num_pl << " existe déja" << std::endl;
	    return ;
	  }
      }
    this->_players.push_back(player(x, y, num_pl));
  }

  void  map::rm_player(int num_pl)
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
    std::cerr << "game::map::rm_player : Player " << num_pl << " existe déja" << std::endl;
  }

  void  map::setDim(unsigned int x, unsigned int y)
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
};
