// Copyright © 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com
#include "PinSwitcherM0.h"
#include "PreCompiller.h"

namespace OS  {
namespace Drivers {
namespace StepperParts {
	
PinSwitcherM0::PinSwitcherM0()
{
	__SET_BIT(__STEPPER_DIR_REGISTER_M0, __STEPPER_M0);
	__RESET_BIT(__STEPPER_PORT_M0, __STEPPER_M0);
} 

void PinSwitcherM0::On()
{
	__SET_BIT(__STEPPER_PORT_M0, __STEPPER_M0);
}

void PinSwitcherM0::Off()
{
	__RESET_BIT(__STEPPER_PORT_M0, __STEPPER_M0);
}


}}}