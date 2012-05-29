/**
 *
 *
 *
 */

#ifndef __CLOCK_H__
#define	__CLOCK_H__

void clock_create();
void clock_set_speed(int speed);

int clock_turn_to_play();
void clock_turn_played();
void clock_wait();
unsigned long clock_turn();

#endif
