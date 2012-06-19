#include <cmath>
#include "sfml.hpp"

void	sfml::process_keyboard(sf::Event &event)
{
  switch (event.Key.Code)
    {
    case sf::Key::Escape:
      this->close();
      return;

    case sf::Key::F1:
      {
	sf::Image Screen = App.Capture();
	Screen.SaveToFile("screenshot.jpg");
	break;
      }

    case sf::Key::Up:
      PosAddY(-0.5);
      break;

    case sf::Key::Down:
      PosAddY(0.5);
      break;

    case sf::Key::Left:
      PosAddX(-0.5);
      break;

    case sf::Key::Right:
      PosAddX(0.5);
      break;

    default:
      break;
    }
}

void    sfml::process_mouse(sf::Event &event)
{
  float   xclick = event.MouseButton.X / 64.0 + this->data.pos.getX();
  float   yclick = event.MouseButton.Y / 64.0 + this->data.pos.getY();

  if (xclick < 0 || yclick < 0);
  else if (xclick >= this->data.map.size_x || yclick >= this->data.map.size_y);
  else if (event.MouseButton.X >= sfml::WIDTH);
  else
    {
      gui_focus.first = trunc(xclick);
      gui_focus.second = trunc(yclick);
      return;
    }
  gui_focus.first = -1;
  gui_focus.second = -1;
}

void    sfml::process_event()
{
  static sf::Event		event;

  while (App.GetEvent(event))
    {
      switch (event.Type)
	{
	case sf::Event::KeyPressed:
	  this->process_keyboard(event);
	  break;

	case sf::Event::Resized:
          break;

	case sf::Event::Closed:
	  this->close();
          break;

        case sf::Event::MouseButtonPressed:
          this->process_mouse(event);
          break;
          
	default:
	  break;
	}
    }
}
