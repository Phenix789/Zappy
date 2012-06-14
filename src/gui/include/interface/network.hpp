#ifndef __INTERFACE_NETWORK_HPP_
#define __INTERFACE_NETWORK_HPP_

/*
** Interface INetwork pour simplifier le bordel
** Balance des exceptions quand la connexion est perdue (catchée)
** Ne devrait pas être chargé dynamiquement (normalement)
*/

#include <exception>
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
  virtual void	send(const std::string &msg) = 0;
  virtual void	send(const std::list<std::string> &list) = 0;
  virtual void	receive(std::string &buffer) = 0;

  virtual bool	connect() = 0;
  virtual bool	disconnect() = 0;

  virtual void	setIp(const std::string&host) = 0;
  virtual void	setPort(const std::string &port) = 0;

  virtual bool	isReady(type which) = 0;
  virtual bool	isBlocking(void) = 0;
  virtual bool	isValid(void) = 0;
  virtual bool	operator!() = 0;
};

namespace network
{
  class except : public std::exception
  {
  public:
    except(const std::string &str) throw();
    ~except() throw();
    const char *what() const throw();

  private:
    const std::string msg;

  private:
    except();
  };
}
extern "C" INetwork       *network_create();

#endif /* __INTERFACE_NETWORK_HPP_ */
