#include <stdlib.h>
#include <time.h>

time_t _timer;
void start_timer(void)
{
    _timer = time(NULL);
}

time_t stop_timer(void)
{
    return time(NULL) - _timer;
}


clock_t _clock_timer;
void start_clock_timer(void)
{
    _clock_timer = clock();
}

clock_t stop_clock_timer(void)
{
    return clock() - _clock_timer;
}
