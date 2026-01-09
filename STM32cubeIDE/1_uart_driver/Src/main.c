#include <stdio.h>
#include "led.h"
#include "uart.h"

static void led_toggle(void){
	led_on();
	for(int i = 0; i <90000; i++){}
	led_off();
	for(int i = 0; i <90000; i++){}
}

static void app(void){
	led_toggle(); //Blue Led toggle/blink
	printf("Hello from STM32WB55\n\r");
}

int main()
{
	led_init();
	uart_tx_init();

	while(1)
	{
		app();
	}
	return 0;
}
