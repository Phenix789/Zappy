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

#define BUFFER_SIZE 1024

struct s_buffer
{
  int read;
  int pos;
  int index;
  int count;
  char buffer[BUFFER_SIZE];
  char command[BUFFER_SIZE + 1];
};

static bool session_read(t_client *client, struct s_buffer * bf)
{
  if (bf->read < BUFFER_SIZE)
    return false;
  bf->read = socket_read(client->socket, bf->buffer, BUFFER_SIZE);
  logger_verbose("[SESSION] Read %i data", bf->read);
  if (bf->read == 0 && bf->count == 0)
    {
      session_close(client);
      return false;
    }
  bf->count++;
  bf->pos = 0;
  return true;
}

void session_treat_data(t_socket *socket, t_client *client)
{
  struct s_buffer bf;

  (void) socket;
  bf.read = bf.pos = BUFFER_SIZE;
  bf.index = bf.count = 0;
  while (bf.index < BUFFER_SIZE)
    {
      if (bf.read <= bf.pos)
	{
	  if (!session_read(client, &bf))
	    return;
	}
      if (bf.buffer[bf.pos] == '\n')
	{
	  if (bf.index == 0)
	    return;
	  bf.command[bf.index] = '\0';
	  session_execute(client, bf.command);
	  bf.index = 0;
	}
      else
	bf.command[bf.index++] = bf.buffer[bf.pos++];
    }
}

void session_execute(t_client *client, char *cmd)
{
  t_command *command;
  t_instruction_in *exec;

  logger_debug("[SESSION] Try execute : %s", cmd);
  exec = session_retrieve_command(cmd);
  if (exec)
    {
      command = parser_parse(cmd, exec->mask);
      (*exec->cb)(client, command);
      parser_command_destroy(command);
    }
  else
    logger_warning("[SESSION] Unknow command : %s", cmd);
}

void session_close(t_client *client)
{
  //@todo close la socket correctement et eviter le segfault
  logger_message("[SESSION] Close connection to client");
  network_del_socket(client->socket);
  socket_close(client->socket);
  client_destroy(client);
}
