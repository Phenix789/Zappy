#include "network/sfml_network.hpp"

sfNetwork::sfNetwork() : addr("localhost"), port(4242)
{
  selector.Add(this->sock);
}

sfNetwork::~sfNetwork()
{
  if (sock.IsValid())
    sock.Close();
}

void  sfNetwork::send(const std::string &msg)
{
  if (sock.Send(msg.c_str(), msg.size()) != sf::Socket::Done)
   throw network::except("sfNetwork::send");
}

void  sfNetwork::send(const std::list<std::string> &list)
{
  std::list<std::string>::const_iterator	cit;

  cit = list.begin();
  while (cit != list.end())
    {
      if (sock.Send(cit->c_str(), cit->size()) != sf::Socket::Done)
        throw network::except("sfNetwork::send(list)");
      cit++;
    }
}

void  sfNetwork::receive(std::string &buffer)
{
  char          tmp[513];
  std::size_t   value = 512;
  
  buffer.clear();
  while (value == 512)
    {
      std::memset(tmp, '\0', 513);
      if (sock.Receive(tmp, 512, value) != sf::Socket::Done)
        throw network::except("sfNetwork::receive");
      buffer += tmp;
    }  
}

bool  sfNetwork::connect()
{
  sf::Socket::Status  res;
  
  std::cout << "Tentative de connection ... " << std::flush;
  res = sock.Connect(port, addr);
  if (res == sf::Socket::Done)
    {
      std::cout << "Réussite!" << std::endl;
      return (true);
    }
  else
    {
      std::cout << "Echec." << std::endl;
      return (false);
    }
}

bool  sfNetwork::disconnect()
{
  if (sock.IsValid())
    return (sock.Close());
  return (true);
}

void  sfNetwork::setIp(const std::string &host)
{
  this->addr = host;
  if(this->addr.IsValid() == false)
    std::cerr << "L'adresse '" << host << "' est invalide" << std::endl;
}

void  sfNetwork::setPort(const std::string &_port)
{
  this->port = static_cast<unsigned short>(atoi(_port.c_str()));
}

bool  sfNetwork::isReady(type __attribute__((unused))which)
{
  return (true);
}
bool  sfNetwork::isBlocking(void)
{
  return (false);
}
bool  sfNetwork::isValid(void)
{
  return (sock.IsValid());
}

bool  sfNetwork::operator!()
{
  return (sock.IsValid());
}

void    sfNetwork::setBlocking(bool value) 
{
  sock.SetBlocking(value);
}
