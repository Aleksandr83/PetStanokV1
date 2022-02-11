// Copyright (c) 2022 Lukin Aleksandr
#ifndef __CHEATER_H__
#define __CHEATER_H__

#pragma once

#include "Led.h"

class Heater 
{
private:
	Led  _Led;

public:
	Heater();
	//~Heater();
	
	void On();
	void Off();
	
}; //CHeater

#endif //__CHEATER_H__
