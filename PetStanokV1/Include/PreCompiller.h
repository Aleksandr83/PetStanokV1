// Copyright (c) 2022 Lukin Aleksandr
#ifndef STDAFX_H_
#define STDAFX_H_

#pragma once

#include "Bits.h"
#include "Configuration.h"

#ifndef F_CPU
#define F_CPU 4000000
#endif	 

#include <avr/io.h>
#include <avr/sleep.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stddef.h>

typedef uint8_t GpioPinType;
typedef unsigned char uint8_t;

#endif /* STDAFX_H_ */