
#include <string.h>
#include "client.h"

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

static bool client_read(t_client *client, struct s_buffer *bf)
{
  if (bf->read >= BUFFER_SIZE)
    {
      bf->read = socket_read(client->socket, bf->buffer, BUFFER_SIZE);
      logger_verbose("[CLIENT] Client %i read %i data on socket", CLP_ID(client), bf->read);
      if (bf->read != 0 && bf->count != 0)
	{
	  bf->count++;
	  bf->pos = 0;
	  return true;
	}
      client_unconnect(client);
    }
  return false;
}

void client_receive(t_socket *socket, t_client *client)
{
  struct s_buffer bf;

  (void) socket;
  memset(&bf, 0, sizeof(struct s_buffer));
  bf.read = bf.pos = BUFFER_SIZE;
  while (bf.index <= BUFFER_SIZE)
    {
      if (bf.read <= bf.pos)
	if (!client_read(client, &bf))
	  return;
      if (bf.buffer[bf.pos] == '\n')
	{
	  if (bf.index == 0)
	    return;
	  bf.command[bf.index] = '\0';
	  client_action_save(client, bf.command);
	  bf.index = 0;
	}
      else
	bf.command[bf.index++] = bf.buffer[bf.pos++];
    }
}
