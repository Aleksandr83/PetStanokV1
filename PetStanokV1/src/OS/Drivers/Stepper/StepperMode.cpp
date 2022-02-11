// Copyright (c) 2022 Lukin Aleksandr
#include "StepperMode.h"

namespace OS  {
namespace Drivers {
namespace StepperParts {
	
	
StepperMode::TStepperMode StepperMode::Get()
{
	return _Mode;
}

void StepperMode::Set(TStepperMode mode)
{
	if (mode == TStepperMode::FullStep)
	{
		SetModeFullStep();
		return;
	}
	if (mode == TStepperMode::Step_1_2)
	{
		SetModeStep12();
		return;
	}
	if (mode == TStepperMode::Step_1_4)
	{
		SetModeStep14();
		return;
	}
	if (mode == TStepperMode::Step_1_8)
	{
		SetModeStep18();
		return;
	}
	if (mode == TStepperMode::Step_1_16)
	{
		SetModeStep116();
		return;
	}
}

void StepperMode::SetModeFullStep()
{
	_M0.Off();
	_M1.Off();
	_M2.Off();
	_Mode = TStepperMode::FullStep;
}

void StepperMode::SetModeStep12()
{
	_M0.On();
	_M1.Off();
	_M2.Off();
	_Mode = TStepperMode::Step_1_2;
}

void StepperMode::SetModeStep14()
{
	_M0.Off();
	_M1.On();
	_M2.Off();
	_Mode = TStepperMode::Step_1_4;
}

void StepperMode::SetModeStep18()
{
	_M0.On();
	_M1.On();
	_M2.Off();
	_Mode = TStepperMode::Step_1_8;
}

void StepperMode::SetModeStep116()
{
	_M0.On();
	_M1.On();
	_M2.On();
	_Mode = TStepperMode::Step_1_16;
}


}}}