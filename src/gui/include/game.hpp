#ifndef __GAME_HPP_
#define __GAME_HPP_

#include <list>
#include <vector>
#include <string>

namespace game
{
  /* -- Player -- */
  enum	orientation
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
    orientation		orient;
    int                 number;
    double              pos_x;
    double              pos_y;

  public:
    void	set(double x, double y, orientation ori);

  private:
    player();
  };


  /* -- Map -- */
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
    void	set(ress type, int nb);
    int		get(ress type) const;
    
    int ressources[7];
  };

  class map
  {
  public:
    map();
    ~map();

  public:
    void        setRess(int x, int y, ress type, int nb);
    void        addPlayer(int x, int y, int num_pl, orientation orient);
    void        rmPlayer(int num_pl);
    void        setDim(int x, int y);
    const tiles 	&getTile(int x, int y) const;
    const std::list<game::player>       getPlayer() const;

  private:
    void	set_tile(tiles _tile, ress type, unsigned int nb);

  public:
    //  private:
    int		                size_x;
    int			        size_y;
    std::vector<tiles>          _tiles;
    std::list<game::player>     _players;

  private:
    map(const map &other);
  };

  /* -- data -- */
  class data
  {
  public:
    data();
    ~data();

  public:
    game::map                   map;
    std::list<std::string>      waitList;

  private:
    bool                        connection;
    bool			upped;
    
  public:
    void	closeConnection();
    void	allowConnection();
    void	putInWaitList(const std::string &str);
    bool	msgInWaitList();
    bool	operator!();
    bool	needRedraw();
    void	needRedraw(bool need);

  private:
    data(const data &other);
  };
};

class INetwork;
namespace network
{
  void	iteration(game::data &data, INetwork &sock);
};

#endif /* __GAME_HPP_ */
