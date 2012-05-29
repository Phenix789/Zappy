/**
 *
 *
 *
 */

#ifndef __KERNEL_H__
#define	__KERNEL_H__

typedef struct s_kernel
{

} t_kernel;

typedef void (*kn_wakeup_cb)(void *);

typedef struct s_kernel_callback
{
	unsigned long turn;
	kn_wakeup_cb callback;
	void* param;
};

t_kernel * kernel_create();
t_kernel * kernel_init(t_kernel *kernel);
void kernel_destroy(t_kernel *);

bool register_wakeup(int nb_turn, kn_wakeup_cb callback, void *param);

#endif
