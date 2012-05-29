/**
 *
 *
 *
 */

#ifndef __CLIENT_H__
#define	__CLIENT_H__

typedef struct s_client
{

} t_client;

t_client *client_create();
t_client *client_init(t_client *client);
void client_destroy();

t_socket * client_get_socket(t_client *client);
int client_count();


#endif
