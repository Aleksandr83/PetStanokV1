// Copyright (c) 2022 Lukin Aleksandr
#ifndef __PINSWITCHERDIR_H__
#define __PINSWITCHERDIR_H__

#pragma once

namespace OS  {
namespace Drivers {
namespace StepperParts {
			
class PinSwitcherDIR
{
public:
	PinSwitcherDIR();
	
	void On();
	void Off();
	
}; //PinSwitcherDIR

}}}

#endif //__PINSWITCHERDIR_H__
