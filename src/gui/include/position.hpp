#ifndef __GUI_HPP_
#define __GUI_HPP_
/*
** Class pour la gui, afin de faciliter la gestion de la position de la gui
** (pour afficher des maps plus grandes que la fenêtre)
*/

namespace game
{
  class data;
};

namespace gui
{
  class position
  {
  public:
    position();
    ~position();

  private:
    float	pos[2];
    float	limit[2];

  public:
    void         setLimit(int x, int y);
    void         setLimit(game::data &data);
    void	 setX(float value);
    void	 setY(float value);
    float	 getX(void) const;
    float	 getY(void) const;
    float        getLimitX(void) const;
    float        getLimitY(void) const;
    void	 dump(void);
  };
};

#endif /* __GUI_HPP_ */
