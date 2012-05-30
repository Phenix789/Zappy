#ifndef __PLAYER_HPP_
#define __PLAYER_HPP_

#include <list>

enum	state
  {
    DEAD,
    ALIVE,
  };

class player
{
public:
  player();
  ~player();

private:
  int			number;
  int			pos_x;
  int			pos_y;
  // TODO LATER
  //  int			level;
  //  std::list<ress>	inventory;
};

#endif /* __PLAYER_HPP_ */
