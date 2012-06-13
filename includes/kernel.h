/*
** kernel.h for zappy in /home/duval_q//Documents/projects/zappy-2015-2014s-duval_q/includes
**
** Made by quentin duval
** Login   <duval_q@epitech.net>
**
** Started on  Tue Jun 12 16:19:57 2012 quentin duval
** Last update Tue Jun 12 16:34:25 2012 quentin duval
*/

#ifndef __KERNEL_H__
#define	__KERNEL_H__

#include <unistd.h>
#include <stdbool.h>
#include <sys/time.h>
#include "list.h"
#include "clock.h"
#include "network.h"
#include "client.h"

#define KN_SV_CLIENT 0x1
#define KN_SV_GAME 0x2
#define KN_SV_CLOCK 0x4
#define KN_SV_INIT (KN_SV_CLIENT | KN_SV_GAME | KN_SV_CLOCK)

#define KN_ERROR_OK 0

#define KN_DEFAULT_PORT 3945

typedef struct s_kernel
{
	bool run;
	int init;
	t_list callbacks;
} t_kernel;

typedef void (*kn_wakeup_cb)(void *, int);

typedef struct s_kernel_callback
{
	struct timeval begin;
	unsigned int time;
	kn_wakeup_cb callback;
	void* param;
} t_kernel_callback;

#define IS_FLAG(str) ((str)[0] == '-')

t_kernel_callback *_kernel_create_callback(int turn, kn_wakeup_cb callback, void *param);

void		kernel_init(void);
bool		kernel_init_with_argv(int argc, char **argv);
void		kernel_destroy(void);

bool kernel_session_init(t_socket *listener, int port);
bool kernel_client_init(int port);
bool kernel_game_init(int x, int y, int nb_per_team);
bool kernel_clock_init(int frequence);
bool kernel_is_init(int service);

bool kernel_add_team(char *team);

void kernel_run(void);
void kernel_stop(void);

bool kernel_register_wakeup(unsigned int time,
			    kn_wakeup_cb callback,
			    void *param);
void kernel_unregister_wakeup(void *param);
int kernel_wakeup_insert(t_kernel_callback *first, t_kernel_callback *second);
int kernel_wakeup(void);

int kernel_retrieve_flag_index(int argc, char **argv, char *flag);
char *kernel_getopt(int argc, char **argv, char *flag, char *defaut);
int kernel_getopt_int(int argc, char **argv, char *flag, int defaut);

void kernel_signal(void);
void kernel_signal_handle(int sig);

#endif
