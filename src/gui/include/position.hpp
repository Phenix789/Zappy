
/*
** Class pour la gui, afin de faciliter la gestion de la position de la gui
** (pour afficher des maps plus grandes que la fenêtre)
*/

namespace gui
{
  class position
  {
  public:
    position();
    ~position();

  private:
    double	pos[2];

  public:
    void	set(double x, double y);
    void	addX(double value);
    void	addY(double value);
    double	getX(void);
    double	getY(void);
    void	dump(void);
  };
};
