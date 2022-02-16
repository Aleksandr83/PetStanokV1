// Copyright © 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com
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
