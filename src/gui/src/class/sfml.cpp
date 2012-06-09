#include <iostream>
#include "sfml.hpp"

sfml::sfml(game::data &edata) : run(false), data(edata)
{ }

sfml::~sfml()
{
}

bool	sfml::init()
{
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

void	sfml::process_event()
{
  while (App.GetEvent(this->event))
    {
      if (this->event.Type == sf::Event::Closed)
	{
	  this->close();
	}
      else if ((this->event.Type == sf::Event::KeyPressed) &&
	       (this->event.Key.Code == sf::Key::Escape))
	this->run = false;
    }
}

void	sfml::intro()
{
  this->clear();
  std::cout << "Beginning graph loop" << std::endl;
  this->App.Display();
}

void	sfml::end()
{
  this->clear();
  this->App.Display();
  std::cout << "Ending graph loop" << std::endl;
}

void	sfml::draw_map()
{
  this->App.Display();
}

void	sfml::draw_background() { }
void	sfml::draw_gui() { }
void	sfml::draw_info() { }
void	sfml::draw_case() { }
void	sfml::draw_player() { }

void	sfml::close()
{
  if (this->App.IsOpened())
    this->App.Close();
  this->run = false;
}

void	sfml::clear()
{
  if (this->App.IsOpened())
    this->App.Clear();
}
