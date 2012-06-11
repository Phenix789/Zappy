/*
** network.h for zappy in /home/duval_q//Documents/projects/zappy/includes
**
** Made by quentin duval
** Login   <duval_q@epitech.net>
**
** Started on  Tue May 29 04:02:57 2012 quentin duval
** Last update Mon Jun  4 09:02:02 2012 quentin duval
*/

#ifndef		NETWORK_H_
#define		NETWORK_H_

typedef struct s_socket t_socket;

# ifdef		_WIN32
typedef int	socklen_t;
# elif defined (linux)

#  include	<unistd.h>
#  include	<sys/types.h>
#  include	<sys/socket.h>
#  include	<netinet/in.h>
#  include	<arpa/inet.h>
#  include	<stdbool.h>
#  include	<sys/time.h>
typedef int			SOCKET;
typedef struct sockaddr_in	SOCKADDR_IN;
typedef struct sockaddr		SOCKADDR;
static const int INVALID_SOCKET = -1;
static const int SOCKET_ERROR	= -1;
#  define closesocket(s)		close(s);
# endif	/*	_WIN32	*/

# include	"list.h"

# define MAX_CO	255

typedef void    (*t_nt_read_cb)(t_socket *, void *);
typedef void    (*t_nt_create_cb)(t_socket *);

struct s_socket
{
  SOCKET        fd;
  SOCKADDR_IN   addr;
  socklen_t     length;
  t_nt_read_cb  read;
  void          *param;
};

typedef struct		s_listener
{
  t_socket		*socket;
  t_nt_create_cb	create;
} t_listener;

typedef struct s_network
{
  t_list	*listened;
  t_list	*read;
  t_list	*destroy;
  int		nfds;
  int		usec_timeout;
} t_network;

bool		network_create();
bool		network_init();
bool		network_destroy();

t_network	*get_network();

bool		network_add_socket(t_socket *socket,
				   t_nt_read_cb callback,
				   void *param);
bool		network_del_socket(t_socket *socket);
int		network_listen(struct timeval *timeout);
bool		network_listen_to(t_socket *socket,
				  int port,
				  t_nt_create_cb new_entry);

void		network_set_sock_error_cb();

t_socket	*socket_create();
t_socket	*socket_init(t_socket *socket);
void		free_socket(t_socket *socket);
void		socket_close(t_socket *socket);

bool		socket_connect(t_socket *socket, char *ip, int port);

int		socket_read(t_socket *soket, void *buffer, int size);
int		socket_write(t_socket *socket, void *buffer, int size);

void            network_close_socket_async(t_socket *socket);

void		socket_set_pleindetrucs();

#endif	/*	NETWORK_H_	*/
