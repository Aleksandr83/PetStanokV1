// Copyright (c) 2022 Lukin Aleksandr
#include "Led.h"
#include "PreCompiller.h"


Led::Led()	
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

//Led::~Led()
//{
//}
