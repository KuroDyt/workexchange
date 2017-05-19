#include <Timer32.h>


void (*Timer32::func)();

void Timer32::start(unsigned int group, unsigned int grtimer, (*func)(), (*flags)(), *exit) {
	unsigned char handle = 0;
	void null = 0;
	timer_start(group, grtimer);
	timer_isr_register(group , grtimer, func, null, flags, handle);
	if (handle != 0){
		timer_init(group, grtimer, exit);
	}
	
}
