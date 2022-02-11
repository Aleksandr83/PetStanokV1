// Copyright (c) 2022 Lukin Aleksandr
#ifndef __STEPPERDIRECTION_H__
#define __STEPPERDIRECTION_H__

#pragma once

#include "PinSwitcherDIR.h"

namespace OS  {
namespace Drivers {
namespace StepperParts {
			
class StepperDirection
{
public:
	enum TStepperDirection
	{
		Normal,
		Reverse
	};

private:
	PinSwitcherDIR	  _Dir;
		
	TStepperDirection _Direction;
	
public:
	TStepperDirection Get();
	void Set(TStepperDirection direction);
	
private:
	void SetNormal();
	void SetReverse();
	

}; //StepperDirection

}}}

#endif //__STEPPERDIRECTION_H__
