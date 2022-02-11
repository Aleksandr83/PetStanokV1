// Copyright (c) 2022 Lukin Aleksandr
#include "PinSwitcherDIR.h"
#include "PreCompiller.h"

namespace OS  {
namespace Drivers {
namespace StepperParts {


PinSwitcherDIR::PinSwitcherDIR()
{
	__SET_BIT(__STEPPER_DIR_REGISTER_DIR, __STEPPER_DIR);
	__RESET_BIT(__STEPPER_PORT_DIR, __STEPPER_DIR);
} 

void PinSwitcherDIR::On()
{
	__SET_BIT(__STEPPER_PORT_DIR, __STEPPER_DIR);
}

void PinSwitcherDIR::Off()
{
	__RESET_BIT(__STEPPER_PORT_DIR, __STEPPER_DIR);
}

}}}