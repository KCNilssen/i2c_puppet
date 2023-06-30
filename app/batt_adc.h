#pragma once

#include <stdint.h>

// struct batt_adc_callback
// {
// 	void (*func)(uint16_t adc_value);
// 	struct batt_adc_callback *next;
// };

// Create a repeating timer that calls repeating_timer_callback.
// struct repeating_timer timer;

// void batt_adc_add_read_callback(struct batt_adc_callback *callback);
// void battadc_read_callback(struct repeating_timer *t);
void battadc_init(void);
