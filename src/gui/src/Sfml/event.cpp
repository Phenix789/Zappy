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
          std::cout << "KeyPressed : " << event.MouseButton.X << "/" << event.MouseButton.Y << std::endl;
          break;
          
	default:
	  break;
	}
    }
}
