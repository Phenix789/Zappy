#include <iostream>
#include "sfml.hpp"

void    sfml::draw_map()
{
  if (this->data.needRedraw())
    {
      if (this->App.IsOpened())
	{
	  this->App.Clear();
	  this->draw_background();
	  this->draw_case();
	  this->draw_player();
	  this->draw_gui();
	  this->App.Display();
	  this->data.needRedraw(false);
	}
      else
	throw gui::except("Affichage sur la map lorsque la fenêtre est fermée");
    }
  else
    sf::Sleep(0.010);
}

void    sfml::draw_background()
{

}

void    sfml::draw_gui() { }
void    sfml::draw_case()
{
  static sf::Sprite	grass(this->getImg(GRASS));
  int	posx = this->pos.getX();
  int	posy = this->pos.getY();

    for (int y = (posy > 0 ? posy : 0); y < 1 + posy + (HEIGHT / 64) && y < this->data.map.size_y; y++)
      for (int x = (posx > 0 ? posx : 0); x < 1 + posx + (WIDTH / 64) && x < this->data.map.size_x; x++)
	{
	  grass.SetPosition((x - pos.getX()) * 64 , (y - pos.getY()) * 64);
	  App.Draw(grass);
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
