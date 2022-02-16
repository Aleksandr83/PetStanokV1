// Copyright © 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com
#ifndef CONFIGURATION_H_
#define CONFIGURATION_H_

#pragma once

#define __DEVICE_ADDR	0x0A01

// PB4 - led			(16 pin)
// PB3 - heater			(15 pin)

// PB2 - stepper M0		(14 pin)
// PD6 - stepper M1		(11 pin)
// PB7 - stepper M2		(19 pin)

// PD2 - stepper Reset  (6 pin)
// PD3 - stepper SLP	(7 pin)
// PD5 - stepper Dir	(9 pin)
// PD4 - stepper Step	(8 pin)

#define __BUFFER_SIZE						20

#define __STEPPER_M0						2
#define __STEPPER_PORT_M0					PORTB
#define __STEPPER_DIR_REGISTER_M0			DDRB
#define __STEPPER_M1						6
#define __STEPPER_PORT_M1					PORTD
#define __STEPPER_DIR_REGISTER_M1			DDRD
#define __STEPPER_M2						7
#define __STEPPER_PORT_M2					PORTB
#define __STEPPER_DIR_REGISTER_M2			DDRB

#define __STEPPER_RST						2
#define __STEPPER_PORT_RST					PORTD
#define __STEPPER_DIR_REGISTER_RST			DDRD
#define __STEPPER_DELAY_RST					4
#define __STEPPER_SLP						3
#define __STEPPER_PORT_SLP					PORTD
#define __STEPPER_DIR_REGISTER_SLP			DDRD
#define __STEPPER_DIR						5
#define __STEPPER_PORT_DIR					PORTD
#define __STEPPER_DIR_REGISTER_DIR			DDRD
#define __STEPPER_STEP						4
#define __STEPPER_PORT_STEP					PORTD
#define __STEPPER_DIR_REGISTER_STP			DDRD
#define __STEPPER_DELAY_STEP				5

#define __LED								4
#define __LED_PORT							PORTB
#define __LED_DIR_REGISTER					DDRB
#define __ENABLE_LED_TOGLE_ON_START			1
#define __DELAY_LED_TOGGLE_ON_START			100
#define __DELAY_LED_TOGGLE					100
#define __COUNT_LED_TOGGLE					3

#define __HEATER							3
#define __HEATER_PORT						PORTB
#define __HEATER_DIR_REGISTER				DDRB

#define __IS_USE_UART_RX					1
#define __IS_USE_UART_TX					0

#define __CRC8_POLY							0x8C

#endif /* CONFIGURATION_H_ */