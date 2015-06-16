#include <time.h>


#ifndef _TIMER_LIB_H_
#define _TIMER_LIB_H_

void start_timer(void);

time_t stop_timer(void);


clock_t stop_clock_timer(void);
void start_clock_timer(void);

#endif /* _TIMER_LIB_H_ */
