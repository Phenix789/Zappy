/**
 *
 *
 *
 */

#ifndef __TOOLS_H__
#define	__TOOLS_H__

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define IMPAIR(a) ((a) & 1)
#define PAIR(a) (!(IMPAIR(a)))
#define ABS(a) ((a) > 0 ? (a) : -(a))

typedef struct s_coord {
	int x;
	int y;
} t_coord;
typedef t_coord t_size;
typedef t_coord t_vector;

#endif
