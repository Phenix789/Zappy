#include <SFML/Window.hpp>
#include "sfml.hpp"

sfml::sfml(const game::map &omap) : run(false), map(omap)
{ }

sfml::~sfml()
{
}

bool	sfml::init()
{
  this->App.Create(sf::VideoMode(800, 600, 32), "Zappy - GUI");
  this->run = true;
  return (true);
}

void	sfml::exit()
{
  this->App.Close();
  this->run = false;
}

bool	sfml::is_running()
{
  return (this->run);
}

void	sfml::process_event()
{
  while (App.GetEvent(this->event))
    {
      if (this->event.Type == sf::Event::Closed)
        this->run = false;
      else if ((this->event.Type == sf::Event::KeyPressed) &&
	       (this->event.Key.Code == sf::Key::Escape))
	this->run = false;
    }
}

void	sfml::intro() {}
void	sfml::draw_map() {}
void	sfml::end() {}


void	sfml::draw_background() { }
void	sfml::draw_gui() { }
void	sfml::draw_info() { }
void	sfml::draw_case() { }
void	sfml::draw_player() { }

