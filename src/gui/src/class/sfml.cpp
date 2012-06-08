#include <iostream>
#include "sfml.hpp"

sfml::sfml(game::data &edata) : run(false), data(edata)
{ }

sfml::~sfml()
{
}

bool	sfml::init()
{
  this->App.Create(sf::VideoMode(800, 800), "Zappy - GUI");
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

void	sfml::intro()
{ std::cout << "Beginning graph loop" << std::endl; }
void	sfml::end()
{ std::cout << "Ending graph loop" << std::endl; }

void	sfml::draw_map() {}
void	sfml::draw_background() { }
void	sfml::draw_gui() { }
void	sfml::draw_info() { }
void	sfml::draw_case() { }
void	sfml::draw_player() { }

