// Copyright (c) 2022 Lukin Aleksandr
#ifndef __PINSWITCHERM0_H__
#define __PINSWITCHERM0_H__

#pragma once

namespace OS  {
namespace Drivers {
namespace StepperParts {
	
class PinSwitcherM0
{
public:
	PinSwitcherM0();	

	void On();
	void Off();
	
}; //PinSwitcherM0

}}}

#endif //__PINSWITCHERM0_H__
