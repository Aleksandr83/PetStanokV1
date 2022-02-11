// Copyright (c) 2022 Lukin Aleksandr
#include "PinSwitcherM1.h"
#include "PreCompiller.h"

namespace OS  {
namespace Drivers {
namespace StepperParts {
	
PinSwitcherM1::PinSwitcherM1()
{
	__SET_BIT(__STEPPER_DIR_REGISTER_M1, __STEPPER_M1);
	__RESET_BIT(__STEPPER_PORT_M1, __STEPPER_M1);
} 

void PinSwitcherM1::On()
{
	__SET_BIT(__STEPPER_PORT_M1, __STEPPER_M1);
}

void PinSwitcherM1::Off()
{
	__RESET_BIT(__STEPPER_PORT_M1, __STEPPER_M1);
}


}}}