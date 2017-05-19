#ifndef Timer32_h
#define Timer32_h
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/xtensa.api"
#include "freertos/queue.h"
#include "esp_attr.h"
#include "esp_err.h"
#include "esp_wifi.h"
#include "esp_system.h"
#include "esp_event.h"
#include "esp_event_loop.h"
#include "nvs_flash.h"
#include "driver/gpio.h"
#include "driver/adc.h"
#include "driver/ledc.h"



namespace Timer32 {
	extern void (*func)();

	void start(timer_group_t, timer_idx_t, void (*func)(), void *arg, int flags, *timer_isr_handle_t);

#endif