// Copyright © 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com
#ifndef __STEPPERMODE_H__
#define __STEPPERMODE_H__

#pragma once

#include "PinSwitcherM0.h"
#include "PinSwitcherM1.h"
#include "PinSwitcherM2.h"

namespace OS  {
namespace Drivers {
namespace StepperParts {

class StepperMode
{
public:	
	enum TStepperMode
	{
		FullStep  = 0xC1,
		Step_1_2  = 0x8C,
		Step_1_4  = 0xE4,
		Step_1_8  = 0xF6,
		Step_1_16 = 0xB9
	};
	
private:
	PinSwitcherM0 _M0;
	PinSwitcherM1 _M1;
	PinSwitcherM2 _M2;
	
	TStepperMode  _Mode;	
	
public:
	TStepperMode Get();
	void Set(TStepperMode mode);	
	
private:
	void inline SetModeFullStep();
	void inline SetModeStep12();
	void inline SetModeStep14();
	void inline SetModeStep18();
	void inline SetModeStep116();

}; //StepperMode



}}}

#endif //__STEPPERMODE_H__
