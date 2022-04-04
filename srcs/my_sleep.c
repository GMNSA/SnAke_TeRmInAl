#include "my_sleep.h"
#include <time.h>

void sleep_us(unsigned long microseconds)
{
	struct timespec ts;
	ts.tv_sec = microseconds / 1000000ul;
	ts.tv_nsec = (microseconds % 1000000ul) * 1000;
#ifdef MY_USLEEP_
	nanosleep(&ts, NULL);
#endif
}
