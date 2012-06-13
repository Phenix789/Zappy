#include "sfml.hpp"

inline void	sfml::process_keyboard(sf::Event &event)
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
      getPos().addY(-0.5);
      this->data.needRedraw(true);
      break;

    case sf::Key::Down:
      getPos().addY(0.5);
      this->data.needRedraw(true);
      break;

    case sf::Key::Left:
      getPos().addX(-0.5);
      this->data.needRedraw(true);
      break;

    case sf::Key::Right:
      getPos().addX(0.5);
      this->data.needRedraw(true);
      break;

    default:
      break;
    }
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
	  this->data.needRedraw(true);
	  return;

	case sf::Event::Closed:
	  this->close();
	  return;

	default:
	  return;
	}
    }
}
