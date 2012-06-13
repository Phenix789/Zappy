#include "sfml.hpp"

sfml::sfml(game::data &edata) : run(false), data(edata)
{
    double	maxX = edata.map.size_x - (WIDTH / 64);
    double	maxY = edata.map.size_y - (HEIGHT / 64);
  
    this->pos.set(-1, -1, (maxX < -1 ? -1 : maxX + 1), (maxY < -1 ? -1 : maxY + 1));
}

sfml::~sfml()
{
}

void	sfml::exit()
{
  this->App.Close();
  this->run = false;
}

bool	sfml::gameloop() const
{
  return (this->run & this->App.IsOpened() & !(this->data));
}

void	sfml::close()
{
  if (this->App.IsOpened())
    this->App.Close();
  this->run = false;
  throw gui::except("Fermeture par l'utilisateur");
}

gui::position	&sfml::getPos()
{
  return (this->pos);
}

const sf::Image		&sfml::getImg(imtype image)
{
  return (this->img[image]);
}