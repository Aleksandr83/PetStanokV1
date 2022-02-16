// Copyright © 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com
#include "PinSwitcherSLP.h"
#include "PreCompiller.h"

namespace OS  {
namespace Drivers {
namespace StepperParts {


PinSwitcherSLP::PinSwitcherSLP()
{
	__SET_BIT(__STEPPER_DIR_REGISTER_SLP, __STEPPER_SLP);
	__RESET_BIT(__STEPPER_PORT_SLP, __STEPPER_SLP);
} 

void PinSwitcherSLP::On()
{
	__SET_BIT(__STEPPER_PORT_SLP, __STEPPER_SLP);
}

void PinSwitcherSLP::Off()
{
	__RESET_BIT(__STEPPER_PORT_SLP, __STEPPER_SLP);
}

}}}