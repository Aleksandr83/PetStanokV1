// Copyright © 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com
#include "Led.h"
#include "PreCompiller.h"

Led::Led()	
{		
} 

void Led::Init()
{
	__SET_BIT(__LED_DIR_REGISTER, __LED);
	__RESET_BIT(__LED_PORT, __LED);
}

void Led::On()
{
	__SET_BIT(__LED_PORT, __LED);
}

void Led::Off()
{
	__RESET_BIT(__LED_PORT, __LED);
}


void Led::Toggle()
{		
	On();
	_delay_ms(__DELAY_LED_TOGGLE);
	Off();
	_delay_ms(__DELAY_LED_TOGGLE);
}