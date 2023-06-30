#include "batt_adc.h"
#include "reg.h"

#include "hardware/gpio.h"
#include "hardware/adc.h"
#include <pico/stdlib.h>

bool battadc_read_callback(struct repeating_timer *t)
{
	// const float conversion_factor = 3.3f / (1 << 12);
    uint16_t result = adc_read();
    // printf("Raw value: 0x%03x, voltage: %f V\n", result, result * conversion_factor);
    // sleep_ms(500);
    reg_set_value(REG_ID_BAT, result);	// What to set the defualt value to?

    return true;
}

void battadc_init(void)
{
	// Make sure GPIO is high-impedance, no pullups etc
    adc_gpio_init(26);
    // Select ADC input 0 (GPIO26)
    adc_select_input(0);

    // Create a repeating timer that calls repeating_timer_callback.
    // If the delay is > 0 then this is the delay between the previous callback ending and the next starting.
    // If the delay is negative (see below) then the next call to the callback will be exactly 500ms after the
    // start of the call to the last callback
    struct repeating_timer timer;

    // Negative delay so means we will call repeating_timer_callback, and call it again
    // 500ms later regardless of how long the callback took to execute
    // 
    // reg_get_value(REG_ID_FRQ)*100 since we are storing in increments of 100 ms in frq regester
    add_repeating_timer_ms(reg_get_value(REG_ID_BFQ)*(-100), battadc_read_callback, NULL, &timer);
}
