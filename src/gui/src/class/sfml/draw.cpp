#include "sfml.hpp"

void    sfml::draw_map()
{
  if (this->App.IsOpened())
  {
    this->draw_background();
    this->draw_gui();
    this->draw_info();
    this->draw_case();
    this->draw_player();
    this->App.Display();
  }
  else
    throw gui::except("Affichage sur la map lorsque la fenêtre est fermée");
}

void    sfml::draw_background()
{
  
}

void    sfml::draw_gui() { }
void    sfml::draw_info() { }
void    sfml::draw_case() { }
void    sfml::draw_player() { }
void    sfml::clear()
{
  if (this->App.IsOpened())
    this->App.Clear();
}
