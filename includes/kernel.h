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

#define KN_SV_SESSION 0x01
#define KN_SV_CLIENT 0x2
#define KN_SV_GAME 0x4
#define KN_SV_CLOCK 0x8
#define KN_SV_INIT (KN_SV_SESSION | KN_SV_CLIENT | KN_SV_GAME | KN_SV_CLOCK)

#define KN_ERROR_OK 0

#define KN_DEFAULT_PORT 3945

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

void		kernel_init();
void		kernel_destroy();

bool kernel_session_init(t_socket *listener, int port);
bool kernel_client_init();
bool kernel_game_init(int x, int y, int nb_per_team);
bool kernel_clock_init(int frequence);
bool kernel_is_init(int service);

bool kernel_add_team(char *team);

void kernel_run();
void kernel_stop();

bool kernel_register_wakeup(unsigned int time, kn_wakeup_cb callback, void *param);
int kernel_wakeup_insert(t_kernel_callback *first, t_kernel_callback *second);
int kernel_wakeup();

#endif
