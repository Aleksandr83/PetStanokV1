// Copyright © 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com
#ifndef __STEPPER_H__
#define __STEPPER_H__

#pragma once

#include "StepperMode.h"
#include "PinSwitcherSLP.h"
#include "PinSwitcherRST.h"
#include "StepperDirection.h"
#include "PinSwitcherSTP.h"

namespace OS {
namespace Drivers {

using OS::Drivers::StepperParts::StepperMode;
using OS::Drivers::StepperParts::StepperDirection;

using OS::Drivers::StepperParts::PinSwitcherSLP;
using OS::Drivers::StepperParts::PinSwitcherRST;
using OS::Drivers::StepperParts::PinSwitcherSTP;

class Stepper 
{
private:
	StepperMode			_Mode;
	StepperDirection	_Direction;
	
	PinSwitcherSLP		_SleepPin;
	PinSwitcherRST		_ResetPin;
	PinSwitcherSTP		_StepPin;
	
public:
	void Init();
	void Reset();
	void Sleep();
	void Unsleep();
	void SetMode(StepperMode::TStepperMode mode);
	void SetDirection(StepperDirection::TStepperDirection direction);
	
	void Step();
};


}}

#endif //__STEPPER_H__
