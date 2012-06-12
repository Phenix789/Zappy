#include "sfml.hpp"

sfml::sfml(game::data &edata) : run(false), data(edata)
{
}

sfml::~sfml()
{
}

void	sfml::exit()
{
  this->App.Close();
  this->run = false;
}

bool	sfml::is_running() const
{
  return (this->run && this->App.IsOpened());
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
  if (image < INTRO || image > BACKGROUND)
    throw gui::except("getImg : Bad number");
  return (this->img[image]);
}