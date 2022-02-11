// Copyright (c) 2022 Lukin Aleksandr
#include "PinSwitcherSTP.h"
#include "PreCompiller.h"

namespace OS  {
namespace Drivers {
namespace StepperParts {


PinSwitcherSTP::PinSwitcherSTP()
{
	__SET_BIT(__STEPPER_DIR_REGISTER_STP, __STEPPER_STEP);
	__RESET_BIT(__STEPPER_PORT_STEP, __STEPPER_STEP);
} 

void PinSwitcherSTP::On()
{
	__SET_BIT(__STEPPER_PORT_STEP, __STEPPER_STEP);
}

void PinSwitcherSTP::Off()
{
	__RESET_BIT(__STEPPER_PORT_STEP, __STEPPER_STEP);
}

}}}