/*
 * oskernel.h
 *
 *  Created on: Jan 21, 2026
 *      Author: lavanyaimadabattina
 */
#pragma once

#ifndef OSKERNEL_H_
#define OSKERNEL_H_

#include <stdint.h>
#include "stm32wb55xx.h"

void osKernelInit(void);
void oskernelStackInit(int i);
uint8_t osKernelAddThreads(void(*task0)(void),void(*task1)(void),void(*task2)(void));
void osKernelLaunch(uint32_t quanta);

#endif /* OSKERNEL_H_ */
