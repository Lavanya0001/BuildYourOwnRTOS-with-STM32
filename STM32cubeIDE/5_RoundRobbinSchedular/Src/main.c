
#include <stdio.h>
#include "led.h"
#include "uart.h"
#include "oskernel.h"

#define QUNATA		1000

void motor_start(void);
void motor_stop(void);
void valve_open(void);
void valve_close(void);

typedef uint32_t TaskProfiler;
TaskProfiler Task0_Profiler, Task1_Profiler, Task2_Profiler;

void task0(void)
{
	while(1)
	{
		Task0_Profiler++;
	}
}

void task1(void)
{
	while(1)
	{
		Task1_Profiler++;
	}
}

void task2(void)
{
	while(1)
	{
		Task2_Profiler++;
	}
}
int main()
{
	/*Initializing kernel*/
	osKernelInit();

	/*Add threads*/
	osKernelAddThreads(&task0, &task1, &task2);

	/*Set RoundRobbin time quanta*/
	osKernelLaunch(QUNATA);


}

void motor_start(void)
{
	printf("Motor is starting...\n\r");
}


void motor_stop(void)
{
	printf("Motor is stopping...\n\r");
}


void valve_open(void)
{
	printf("Valve is Opening...\n\r");
}


void valve_close(void)
{
	printf("Valve is Closing...\n\r");
}

