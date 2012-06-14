
#include "client.h"
#include "kernel.h"

void client_consume_food(t_client *client, int error)
{
  (void) error;
  if (client->player && client->player->inv_food > 0)
    {
      client->player->inv_food--;
      kernel_register_wakeup(DELAY_FOOD, (kn_wakeup_cb) &client_consume_food, client);
    }
  else
    client_food_dead(client);
}

void client_food_dead(t_client *client)
{
  logger_message("[CLIENT] Client %i starved ... dead!", CLP_ID(client));
  player_free(client->player);
  client->player = NULL;
  client_send(client, "mort");
  client_unconnect(client);
}
