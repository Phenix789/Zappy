/**
 *
 *
 *
 */

#ifndef __CLIENT_H__
#define	__CLIENT_H__

#include <stdbool.h>

typedef struct s_socket t_socket;
typedef struct s_player t_player;

#include "list.h"

typedef struct s_client_manager
{
	t_list clients;
} t_client_manager;

typedef struct s_client
{
	t_socket *socket;
	t_player *player;
	t_list actions;
} t_client;

/*client manager*/
void client_manager_init();
void client_manager_destroy();
int client_manager_count();
void _client_manager_add(t_client *client);
void _client_manager_remove(t_client *client);

t_client *client_manager_retrieve_from_socket(t_socket *socket);
t_client *client_manager_retrieve_from_player(t_player *player);

/*client*/
t_client *client_create(t_socket *socket);
t_client *client_init(t_client *client, t_socket *socket);
void client_destroy(t_client *client);

t_socket *client_get_socket(t_client *client);
t_player *client_get_player(t_client *client);
bool client_set_player(t_client *client, t_player *player);

#endif
