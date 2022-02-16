// Copyright © 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com
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
		Normal	= 0xA0,
		Reverse = 0xB0
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
