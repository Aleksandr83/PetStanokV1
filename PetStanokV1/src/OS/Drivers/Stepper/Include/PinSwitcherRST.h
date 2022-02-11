// Copyright (c) 2022 Lukin Aleksandr
#ifndef __PINSWITCHERRST_H__
#define __PINSWITCHERRST_H__

#pragma once

namespace OS  {
namespace Drivers {
namespace StepperParts {
			
class PinSwitcherRST
{
public:
	PinSwitcherRST();
	
	void On();
	void Off();

}; //PinSwitcherRST

}}}

#endif //__PINSWITCHERRST_H__
