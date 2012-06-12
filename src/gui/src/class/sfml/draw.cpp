#include <iostream>
#include "sfml.hpp"

void    sfml::draw_map()
{
  if (this->App.IsOpened())
  {
    this->App.Clear();
    this->draw_background();
    this->draw_case();
    this->draw_player();
    this->draw_gui();
    this->App.Display();
  }
  else
    throw gui::except("Affichage sur la map lorsque la fenêtre est fermée");
  std::cout << 1.f / App.GetFrameTime() << std::endl;
}

void    sfml::draw_background()
{
  
}

void    sfml::draw_gui() { }
void    sfml::draw_case()
{ 
  sf::Sprite	grass(this->getImg(GRASS));
  
  for (int y = 0; y < this->data.map.size_x; y++)
    for (int x = 0; x < this->data.map.size_y; x++)
      {
	if ((x >= (this->pos.getX() - 1)) && (x <= (1 + this->pos.getX() + (WIDTH / 64))))
	  if ((y >= (this->pos.getY() - 1)) && (y <= (1 + this->pos.getY() + (HEIGHT / 64))))
	    {
	      grass.SetPosition((x - pos.getX()) * 64 , (y - pos.getY()) * 64);
	      App.Draw(grass);
	    }
      }
}

void    sfml::draw_player()
{ 
  
  
}


void    sfml::clear()
{
  if (this->App.IsOpened())
    this->App.Clear();
}
