// Copyright (c) 2022 Lukin Aleksandr
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
		FullStep,
		Step_1_2,
		Step_1_4,
		Step_1_8,
		Step_1_16
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
	void SetModeFullStep();
	void SetModeStep12();
	void SetModeStep14();
	void SetModeStep18();
	void SetModeStep116();

}; //StepperMode



}}}

#endif //__STEPPERMODE_H__
