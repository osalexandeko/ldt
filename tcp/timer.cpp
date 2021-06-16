#include "timer.hpp"
#include <stdio.h>
#include <time.h>
#include <signal.h>
timer_t gTimerid;

void start_timer(uint32_t msec)
{
	struct itimerspec value;
	value.it_value.tv_sec = 1;//waits for 5 seconds before sending timer signal
	value.it_value.tv_nsec = 0;
	value.it_interval.tv_sec = 5;//sends timer signal every 5 seconds
	value.it_interval.tv_nsec = 0;
	timer_create (CLOCK_REALTIME, NULL, &gTimerid);
	timer_settime (gTimerid, 0, &value, NULL);
}

void stop_timer(void)
{
	struct itimerspec value;
	value.it_value.tv_sec = 0;
	value.it_value.tv_nsec = 0;
	value.it_interval.tv_sec = 0;
	value.it_interval.tv_nsec = 0;
	timer_settime (gTimerid, 0, &value, NULL);
}



/**
*@param time_ms, time to the event.
*@param timer_callback, the event handler.
*@param timer_callback_params, the parameters oth the handler.
*/
void perform_event_by_timer( uint32_t time_ms, timer_cb_t timer_callback){
	printf("trying perform_event_by_timer \r\n");
	(void) signal(SIGALRM, timer_callback);
	start_timer(time_ms);
	
}


#ifdef UNIT_TEST_TIMER

void timer_callback(int sig) {
	printf(" Catched timer signal: %d … !!\n", sig);
}

int main(int ac, char **av)
{
	(void) signal(SIGALRM, timer_callback);
	start_timer();
	while(1);
}
#endif

