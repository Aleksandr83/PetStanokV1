// Copyright (c) 2022 Lukin Aleksandr
#include "PinSwitcherRST.h"
#include "PreCompiller.h"

namespace OS  {
namespace Drivers {
namespace StepperParts {


PinSwitcherRST::PinSwitcherRST()
{
	__SET_BIT(__STEPPER_DIR_REGISTER_RST, __STEPPER_RST);
	__RESET_BIT(__STEPPER_PORT_RST, __STEPPER_RST);
} 

void PinSwitcherRST::On()
{
	__SET_BIT(__STEPPER_PORT_RST, __STEPPER_RST);
}

void PinSwitcherRST::Off()
{
	__RESET_BIT(__STEPPER_PORT_RST, __STEPPER_RST);
}

}}}