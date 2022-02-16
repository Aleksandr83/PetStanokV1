// Copyright © 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com
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
