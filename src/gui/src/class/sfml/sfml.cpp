#include <iostream>
#include "sfml.hpp"

sfml::sfml(game::data &edata) : run(false), data(edata)
{ }

sfml::~sfml()
{
}

bool	sfml::init()
{
  this->load_img();
  this->App.Create(sf::VideoMode(800, 800, 32), "Zappy - GUI");
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

void	sfml::intro()
{
  sf::Image	Image;

  this->clear();
  this->App.Display();
  std::cout << "Beginning graph loop" << std::endl;
}

void	sfml::end()
{
  this->clear();
  this->App.Display();
  std::cout << "Ending graph loop" << std::endl;
}

void	sfml::close()
{
  if (this->App.IsOpened())
    this->App.Close();
  this->run = false;
}
