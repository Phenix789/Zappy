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
  this->LoadAllSprite();
  this->App.Create(sf::VideoMode(WIDTH + GUI_WIDTH, HEIGHT, 32), "Zappy - GUI", sf::Style::Close);
  this->App.SetFramerateLimit(60);
  this->run = true;
  return (true);
}