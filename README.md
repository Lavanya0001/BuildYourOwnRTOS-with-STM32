# BuildYourOwnRTOS

This repository contains an STM32 embedded project developed on the **NUCLEO-WB55** board using **STM32CubeIDE (C language)**.

The long-term goal of this project is to **design and build a simple RTOS from scratch**, focusing on understanding core OS concepts rather than using an existing RTOS like FreeRTOS.

---

## Current Status

✔ Bare-metal STM32CubeIDE project  
✔ LED driver implemented  
✔ UART driver implemented  

These drivers will be used as building blocks for task scheduling, timing, and inter-task communication.

---

## Development Environment

- **Board**: NUCLEO-WB55  
- **MCU**: STM32WB55  
- **IDE**: STM32CubeIDE  
- **Language**: C  
- **Programming Interface**: ST-LINK  

---

## Project Goal

The objective of this project is to gradually implement:
- Cooperative/preemptive task scheduling
- Context switching
- Software timers
- Basic inter-task communication
- Minimal RTOS kernel concepts

This is a **learning-oriented RTOS implementation**, built step by step on real hardware.

---

## Notes

- Build artifacts (`.elf`, `.bin`, `Debug/`, `Release/`) are not tracked.
- Only source code and configuration files are committed.

---

## Author

Lavanya Imadabattina  
Embedded Engineer | STM32 | Bare-Metal | RTOS
