// Copyright © 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com
#include "StepperDirection.h"

namespace OS  {
namespace Drivers {
namespace StepperParts {

StepperDirection::TStepperDirection StepperDirection::Get()
{
	return _Direction;
}

void StepperDirection::Set(TStepperDirection direction)
{
	if (direction == TStepperDirection::Normal)
	{
		SetNormal();
		return;
	}
	if (direction == TStepperDirection::Reverse)
	{
		SetReverse();
		return;
	}
	
}

void StepperDirection::SetNormal()
{
	_Dir.Off();
	_Direction = TStepperDirection::Normal;
}

void StepperDirection::SetReverse()
{
	_Dir.On();
	_Direction = TStepperDirection::Reverse;
}

}}}


