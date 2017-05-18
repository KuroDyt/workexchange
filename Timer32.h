#ifndef Timer32_h
#define Timer32_h
#include <driver/adc.h>

namespace Timer32 {
	extern unsigned long time_units;
	extern void (*func)();
	extern volatile unsigned long count;
	extern volatile char overflowing;
	extern volatile unsigned int tcnt2;

	void set(unsigned long ms, void (*func)());
	void set(unsigned long units, double resolution, void (*f)());
	void start();
	void stop();
	void _overflow();
}
#endif