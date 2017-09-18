#include <Timer32.h>

unsigned long Timer32::time_units;
void (*Timer32::func)();
volatile unsigned long Timer32::count;
volatile char Timer32::overflowing;
volatile unsigned int Timer32::tcnt2;

void Timer32::set(unsigned long ms, void (*f)()) {
	Timer32::set(ms, 0.001, f);
}

void Timer32::set(unsigned long units, double resolution, void (*f)()){
	float prescaler = 0.0;
	if (units == 0)
		time_units = 1;
	else
		time_units = units;

	func = f;
}