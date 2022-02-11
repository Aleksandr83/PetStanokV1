// Copyright (c) 2022 Lukin Aleksandr
#include "Interrupts.h"
#include <avr/interrupt.h>

namespace OS {
namespace System {

void Interrupts::EnableAll()
{
	sei();
}

void Interrupts::DisableAll()
{
	cli();
}

void Interrupts::EnableTimer0()
{
	TIMSK  |=  (1 << TOIE0);
}

void Interrupts::DisableTimer0()
{	
	TIMSK  &= ~(1 << TOIE0);	
}

}}
