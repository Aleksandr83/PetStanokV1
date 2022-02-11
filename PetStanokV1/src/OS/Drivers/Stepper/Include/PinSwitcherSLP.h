// Copyright (c) 2022 Lukin Aleksandr
#ifndef __PINSWITCHERSLP_H__
#define __PINSWITCHERSLP_H__

#pragma once

namespace OS  {
namespace Drivers {
namespace StepperParts {

class PinSwitcherSLP
{
public:
	PinSwitcherSLP();

	void On();
	void Off();

}; //PinSwitcherSLP

}}}

#endif //__PINSWITCHERSLP_H__
