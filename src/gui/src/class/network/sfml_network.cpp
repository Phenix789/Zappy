#include "network/sfml_network.hpp"
#include "utils.hpp"

sfNetwork::sfNetwork() : addr("localhost"), port(4242)
{
}

sfNetwork::~sfNetwork()
{
  if (sock.IsValid())
    sock.Close();
}

void  sfNetwork::send(const std::string &msg)
{
  sf::Packet	packet;

  packet.Append(msg.c_str(), msg.size());
  this->sendPacket(packet);
}

void  sfNetwork::send(const std::list<std::string> &list)
{
  sf::Packet	packet;
  std::list<std::string>::const_iterator	cit;

  cit = list.begin();
  while (cit != list.end())
    {
      packet.Append(cit->c_str(), cit->size());
      cit++;
    }
  this->sendPacket(packet);
}

void  sfNetwork::receive(std::string &buffer)
{
  sf::Packet	packet;

  buffer.clear();
  sock.Receive(packet);
  packet >> buffer;
}

bool  sfNetwork::connect()
{
  return (sock.Connect(port, addr));
}

bool  sfNetwork::connect(const std::string &host, const std::string &_port)
{
  return (sock.Connect(utils::atos(_port), sf::IPAddress(host)));
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
  this->addr.IsValid();
}
void  sfNetwork::setPort(const std::string &_port)
{
  this->port = utils::atos(_port);
}

bool  sfNetwork::isReady(type __attribute__((unused))which)
{
  return (false);
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

bool	sfNetwork::sendPacket(sf::Packet &packet)
{
  return (sock.Send(packet));
}
