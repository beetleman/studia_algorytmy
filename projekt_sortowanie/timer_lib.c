#include <stdlib.h>
#include <time.h>

clock_t _timer;
void start_timer(void)
{
    _timer = clock();
}

float stop_timer(void)
{
    return (float)(clock() - _timer) / (CLOCKS_PER_SEC);
}
