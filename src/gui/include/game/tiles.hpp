#ifndef __GAME_TILES_HPP_
#define __GAME_TILES_HPP_

namespace game
{
    enum  ress
    {
      FOOD,
      LINEMATE,
      DERAUMATRE,
      SIBUR,
      MENDIANE,
      PHIRAS,
      THYSTAME
    };

  struct tiles
  {
  public:
    tiles();
    void        set(ress type, int nb);
    int         get(ress type) const;

    int ressources[7];
  };
};

#endif /* __GAME_TILES_HPP_ */
