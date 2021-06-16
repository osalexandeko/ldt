#ifndef TIMER_HPP
#define TIMER_HPP
#include <stdint.h>

typedef  void (*timer_cb_t )(int) ;

void perform_event_by_timer( uint32_t time_ms, timer_cb_t timer_callback);
void stop_timer(void);

#endif 