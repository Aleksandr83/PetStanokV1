// Copyright (c) 2022 Lukin Aleksandr
#ifndef __PINSWITCHERSTP_H__
#define __PINSWITCHERSTP_H__

#pragma once

namespace OS  {
namespace Drivers {
namespace StepperParts {

class PinSwitcherSTP
{
public:
	PinSwitcherSTP();
	
	void On();
	void Off();


}; //PinSwitcherSTP

}}}

#endif //__PINSWITCHERSTP_H__
