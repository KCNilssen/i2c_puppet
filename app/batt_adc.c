#include "batt_adc.h"
#include "reg.h"

#include <pico/stdlib.h>
#include "hardware/gpio.h"
#include "hardware/adc.h"

void battadc_read(void)
{
	// const float conversion_factor = 3.3f / (1 << 12);
    uint16_t result = adc_read();
    // printf("Raw value: 0x%03x, voltage: %f V\n", result, result * conversion_factor);
    // sleep_ms(500);

    reg_set_value(REG_ID_BAT, result);	// What to set the defualt value to?
}

void battadc_init(void)
{
	// Make sure GPIO is high-impedance, no pullups etc
    adc_gpio_init(26);
    // Select ADC input 0 (GPIO26)
    adc_select_input(0);
}
