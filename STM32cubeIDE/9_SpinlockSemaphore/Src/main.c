
#include <stdio.h>
#include "led.h"
#include "uart.h"
#include "oskernel.h"

#define QUNATA		10

void motor_start(void);
void motor_stop(void);
void valve_open(void);
void valve_close(void);

int32_t semaphore1,semaphore2;

typedef uint32_t TaskProfiler;
TaskProfiler Task0_Profiler, Task1_Profiler, Task2_Profiler,pTask1_Profiler,pTask2_Profiler;

void task3(void)
{
		pTask1_Profiler++;

}
void task0(void)
{
	while(1)
	{
		osSemaphoreWait(&semaphore1);
		Task0_Profiler++;
		motor_start();
		osSemaphoreGive(&semaphore2);
	}
}

void task1(void)
{
	while(1)
	{
		osSemaphoreWait(&semaphore2);
		Task1_Profiler++;
		valve_open();
		osSemaphoreGive(&semaphore1);

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
	/* UART Debugger Init */
	uart_tx_init();

	/*Initializing TIM2 */
	Timer2_1Hz_Interrupt_Init();

	/*initialize the Semaphores*/
	osSemaphoreInit(&semaphore1, 1);
	osSemaphoreInit(&semaphore2, 0);


	/*Initializing kernel*/
	osKernelInit();

	/*Add threads*/
	osKernelAddThreads(&task0, &task1, &task2);

	/*Set RoundRobbin time quanta*/
	osKernelLaunch(QUNATA);


}

void TIM2_IRQHandler(void)
{
	/*Clear UIE(Update Interrupt)flag*/
	TIM2->SR &= ~TIM2_UIF;

	/*Do-Something*/
	pTask2_Profiler++;
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


