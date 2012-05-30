#ifndef __PLAYER_HPP_
#define __PLAYER_HPP_

#include <list>

namespace game
{
  enum	state
    {
      DEAD,
      ALIVE,
    };

  class player
  {
  public:
    player(int x, int y, int number);
    ~player();

  public:
    int			number;
    int			pos_x;
    int			pos_y;
    // TODO LATER
    //  int			level;
    //  std::list<ress>	inventory;

  private:
    player();
  };
}

#endif /* __PLAYER_HPP_ */
