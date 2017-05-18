#include <Timer32.h>


void (*Timer32::func)();

void Timer32::set(unsigned int group, unsigned int grtimer, (*func)(), (*flags)(), handle) {
	timer_isr_register(group , grtimer, func, null, flags, handle);
}
