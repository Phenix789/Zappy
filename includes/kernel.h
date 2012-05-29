/**
 *
 *
 *
 */

#ifndef __KERNEL_H__
#define	__KERNEL_H__

#include "list.h"

#define KN_SV_NETWORK 0x01
#define KN_SV_SESSION 0x2
#define KN_SV_GAME 0x4
#define KN_SV_INIT (KN_SV_NETWORK | KN_SV_SESSION | KN_SV_GAME)

typedef struct s_kernel
{
	int init;
	t_list callbacks;
	t_socket listener;
} t_kernel;

typedef void (*kn_wakeup_cb)(void *);

typedef struct s_kernel_callback
{
	unsigned long turn;
	kn_wakeup_cb callback;
	void* param;
} t_kernel_callback;

t_kernel_callback *_kernel_create_callback(int turn, kn_wakeup_cb callback, void *param);

t_kernel * kernel_create();
t_kernel * kernel_init(t_kernel *kernel);
void kernel_destroy(t_kernel *);

int kernel_network_init(int port);
int kernel_session_init();
int kernel_game_init(int x, int y, int time, int nb_per_team);
int kernel_add_team(char *team);
int kernel_is_init();

int kernel_run();

bool register_wakeup(int nb_turn, kn_wakeup_cb callback, void *param);

#endif
