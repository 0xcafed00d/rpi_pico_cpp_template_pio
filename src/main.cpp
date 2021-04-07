
#include <stdio.h>
#include "pico/binary_info.h"
#include "pico/stdlib.h"

int main() {
	bi_decl(bi_program_description("template raspberry pi pico c++ project"));

	stdio_init_all();

	const uint LED_PIN = PICO_DEFAULT_LED_PIN;

	gpio_init(LED_PIN);
	gpio_set_dir(LED_PIN, GPIO_OUT);

	uint32_t count = 1;

	while (true) {
		gpio_put(LED_PIN, count & 1);
		printf("%d\n", count);
		sleep_ms(100);
		count++;
	}
}
