// Copyright (c) 2022 Lukin Aleksandr
#ifndef __ANALOG_COMPARATOR_H__
#define __ANALOG_COMPARATOR_H__

#pragma once

#include "PreCompiller.h"

class AnalogComparator
{
public:
	void Enable();
	void Disable();	
	
	bool GetValue();	
}; 

#endif // __ANALOG_COMPARATOR_H__
