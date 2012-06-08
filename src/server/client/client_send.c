
#include <stdarg.h>
#include "client.h"

static char buffer[1024 + 1];

int client_send(t_client *client, char *mask, ...)
{
  va_list vl;
  int size;

  va_start(vl, mask);
  size = vsnprintf(buffer, 1024, mask, vl);
  logger_verbose("[CLIENT] Client %i send %i bytes '%s'", CLP_ID(client), size, buffer);
  buffer[size++] = '\n';
  buffer[size] = '\0';
  size = socket_write(client->socket, buffer, size);
  va_end(vl);
  return size;
}
