/*
** session_treat_data.c for zappy in /home/kersuz_v//Zappy/src/session
**
** Made by vincent kersuzan
** Login   <kersuz_v@epitech.net>
**
** Started on  Tue May 29 04:06:36 2012 vincent kersuzan
** Last update Tue May 29 05:44:27 2012 vincent kersuzan
*/

#include	"session.h"
#include "logger.h"

void	session_treat_data(t_socket *socket, t_client *client)
{
  logger_error("[SESSION] Treat data not implemented");
  char buffer[1024 + 1];

  memset(buffer, 0, 1024 + 1);
  socket_read(socket, buffer, 1024);
  logger_verbose("Message receive : %s", buffer);
  /*
    appelle le parser pour verifier que c est possible ou non
    recupere une liste d instruction
    execute la callback en memoire avec les arguments parsé
  */
  (void)socket;
  (void)client;
}
