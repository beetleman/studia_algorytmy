#include <stdlib.h>
#include <time.h>

time_t _timer;
void start_timer(void){
    _timer = time(NULL);
}

time_t stop_timer(){
    return time(NULL) - _timer;
}
