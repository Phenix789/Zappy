#include "network/sfml_network.hpp"

sfNetwork::sfNetwork() : addr("localhost"), port(4242)
{
  sock.SetBlocking(true);
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
  char          receive_buffer[512];
  std::size_t   howmany = 512;
  
  buffer.clear();
  while (isReady(0.010))
    {
      std::memset(receive_buffer, '\0', 512);
      if (sock.Receive(receive_buffer, 256, howmany) != sf::Socket::Done)
        throw network::except("sfNetwork::receive");
      buffer += receive_buffer;
    }
}

bool  sfNetwork::connect()
{
  sf::Socket::Status  res;
  
  std::cout << "Tentative de connection ... " << std::flush;
  res = sock.Connect(port, addr);
  if (res == sf::Socket::Done)
    {
      std::cout << "Réussie" << std::endl;
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

bool  sfNetwork::isReady(float timeout)
{
  if (selector.Wait(timeout) > 0)
    return (true);
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