// Copyright © 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com
#ifndef __PINSWITCHERM2_H__
#define __PINSWITCHERM2_H__

#pragma once

namespace OS  {
namespace Drivers {
namespace StepperParts {
	
class PinSwitcherM2
{
public:
	PinSwitcherM2();
	
	void On();
	void Off();
	
}; //PinSwitcherM2

}}}

#endif //__PINSWITCHERM2_H__
