#include <iostream>
#include "sfml.hpp"

sfml::sfml(game::data &edata) : run(false), data(edata)
{
}

sfml::~sfml()
{
}

bool	sfml::init()
{
  this->LoadImage();
  this->App.Create(sf::VideoMode(800, 800, 32), "Zappy - GUI");
  this->App.SetFramerateLimit(60);
  this->run = true;
  return (true);
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
  return (this->img[image]);
}