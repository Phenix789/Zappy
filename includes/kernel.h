/**
 *
 *
 *
 */

#ifndef __KERNEL_H__
#define	__KERNEL_H__

#include <unistd.h>
#include <stdbool.h>
#include <sys/time.h>
#include "list.h"
#include "clock.h"
#include "session.h"
#include "network.h"
#include "client.h"

#define KN_SV_NETWORK 0x01
#define KN_SV_SESSION 0x2
#define KN_SV_GAME 0x4
#define KN_SV_INIT (KN_SV_NETWORK | KN_SV_SESSION | KN_SV_GAME)

#define KN_ERROR_OK 0

typedef struct s_kernel
{
	bool run;
	int init;
	t_list callbacks;
	t_socket listener;
} t_kernel;

typedef void (*kn_wakeup_cb)(t_client *, int);

typedef struct s_kernel_callback
{
	struct timeval begin;
	unsigned int time;
	kn_wakeup_cb callback;
	void* param;
} t_kernel_callback;

t_kernel_callback *_kernel_create_callback(int turn, kn_wakeup_cb callback, void *param);

t_kernel * kernel_create();
t_kernel * kernel_init(t_kernel *kernel);
void kernel_destroy(t_kernel *);

bool kernel_network_init(int port);
bool kernel_session_init();
bool kernel_game_init(int x, int y, int time, int nb_per_team);
bool kernel_add_team(char *team);
bool kernel_is_init();

void kernel_run();
void kernel_stop();

bool kernel_register_wakeup(unsigned int time, kn_wakeup_cb callback, void *param);
int kernel_wakeup_insert(t_kernel_callback *first, t_kernel_callback *second);
int kernel_wakeup();

#endif
