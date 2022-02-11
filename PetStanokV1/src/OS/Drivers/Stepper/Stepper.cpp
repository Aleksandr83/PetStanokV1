// Copyright (c) 2022 Lukin Aleksandr
#include "Stepper.h"
#include "PreCompiller.h"

namespace OS {
namespace Drivers {


void Stepper::Init()
{
	Reset();
	Unsleep();	
	SetMode(StepperMode::TStepperMode::Step_1_16);
	SetDirection(StepperDirection::TStepperDirection::Normal);
}

void Stepper::Reset()
{
	_ResetPin.Off();
	_delay_ms(__STEPPER_DELAY_RST);
	_ResetPin.On();
}

void Stepper::Sleep()
{
	_SleepPin.Off();
}

void Stepper::Unsleep()
{
	_SleepPin.On();
}

void Stepper::SetMode(StepperMode::TStepperMode mode)
{
	_Mode.Set(mode);
}

void Stepper::SetDirection(StepperDirection::TStepperDirection direction)
{
	_Direction.Set(direction);
}

void Stepper::Step()
{
	_StepPin.On();
	_delay_ms(__STEPPER_DELAY_STEP);
	_StepPin.Off();
}

}}


