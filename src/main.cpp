
#include <stdio.h>
#include "hardware/pio.h"
#include "pico/binary_info.h"
#include "pico/stdlib.h"

#include "template.pio.h"

int main() {
	bi_decl(bi_program_description("template raspberry pi pico c++ project with pio"));

	stdio_init_all();

	const uint LED_PIN = PICO_DEFAULT_LED_PIN;

	gpio_init(LED_PIN);
	gpio_set_dir(LED_PIN, GPIO_OUT);

	// use pio0
	PIO pio = pio0;

	// load program
	uint offset = pio_add_program(pio, &template_program);

	// get a state machine
	uint sm = pio_claim_unused_sm(pio, true);

	// init program
	template_program_init(pio, sm, offset, PICO_DEFAULT_LED_PIN);

	while (true) {
		// put 1 onto input fifo
		pio_sm_put_blocking(pio, sm, 1);
		sleep_ms(500);
		// put 0 onto input fifo
		pio_sm_put_blocking(pio, sm, 0);
		sleep_ms(500);
	}
}