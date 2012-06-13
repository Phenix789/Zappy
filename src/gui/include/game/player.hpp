#ifndef __GAME_PLAYER_HPP_
#define __GAME_PLAYER_HPP_

namespace game
{
  enum  orientation
    {
      NORD,
      EST,
      SUD,
      OUEST
    };

  class player
  {
  public:
    player(int x, int y, int number, orientation ori);
    ~player();

  public:
    orientation         orient;
    int                 number;
    int                 pos_x;
    int                 pos_y;

  public:
    void        set(int x, int y, orientation ori);
    bool        isHere(int x, int y) const;

  private:
    player();
  };
};

#endif /* __GAME_PLAYER_HPP_ */
