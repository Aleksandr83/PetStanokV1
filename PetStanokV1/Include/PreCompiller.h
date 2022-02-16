// Copyright © 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com
#ifndef STDAFX_H_
#define STDAFX_H_

#pragma once

#include "Bits.h"
#include "Configuration.h"

#ifndef F_CPU
//#define F_CPU 4000000
#define F_CPU 16000000
#endif	 

#include <stdio.h>
#include <stdarg.h>
#include <avr/io.h>
#include <avr/sleep.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/wdt.h>
#include <stddef.h>
#include <string.h>

typedef uint8_t GpioPinType;
typedef unsigned char uint8_t;

#endif /* STDAFX_H_ */