#include <iostream>
#include "sfml.hpp"

bool	sfml::init()
{
  if (this->data.map.size_x < 1  || this->data.map.size_y < 1)
    {
      std::cerr << "Taille : " << this->data.map.size_x << "/" << this->data.map.size_y << std::endl;
      throw gui::except("La map est trop petite");
    }
  this->LoadImage();
  this->App.Create(sf::VideoMode(WIDTH, HEIGHT, 32), "Zappy - GUI");
  this->App.SetFramerateLimit(LIMFPS);
  this->App.UseVerticalSync(true);
  this->run = true;
  return (true);
}