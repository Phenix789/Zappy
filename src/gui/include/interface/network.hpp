#ifndef __NETWORK_HPP_
#define __NETWORK_HPP_

/*
** Interface INetwork pour simplifier le bordel
** Ne devrait pas être chargé dynamiquement (normalement)
*/

#include <string>
#include <list>

class INetwork
{
public:
  enum	type
    {
      READ,
      WRITE
    };

public:
  ~INetwork() {};

public:
  virtual bool	send(const std::string &msg) = 0;
  virtual bool	send(const std::list<std::string> &list) = 0;
  virtual bool	receive(std::string &buffer) = 0;

  virtual bool	connect() = 0;
  virtual bool	disconnect() = 0;

  virtual bool	setIp(const std::string&host) = 0;
  virtual bool	setPort(const std::string &port) = 0;

  virtual bool	isWaiting(type which) = 0;
  virtual bool	isBlocking(void) = 0;
  virtual bool	isValid(void) = 0;
  virtual bool	operator!() = 0;
};

extern "C" INetwork       *network_create();

#endif /* __NETWORK_HPP_ */
