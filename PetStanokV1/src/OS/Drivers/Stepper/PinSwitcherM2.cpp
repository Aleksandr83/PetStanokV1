// Copyright © 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com
#include "PinSwitcherM2.h"
#include "PreCompiller.h"

namespace OS  {
namespace Drivers {
namespace StepperParts {
	
PinSwitcherM2::PinSwitcherM2()
{
	__SET_BIT(__STEPPER_DIR_REGISTER_M2, __STEPPER_M2);
	__RESET_BIT(__STEPPER_PORT_M2, __STEPPER_M2);
} 

void PinSwitcherM2::On()
{
	__SET_BIT(__STEPPER_PORT_M2, __STEPPER_M2);
}

void PinSwitcherM2::Off()
{
	__RESET_BIT(__STEPPER_PORT_M2, __STEPPER_M2);
}


}}}