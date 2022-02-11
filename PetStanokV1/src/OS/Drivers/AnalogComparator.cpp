// Copyright (c) 2022 Lukin Aleksandr
#include "PreCompiller.h"
#include "AnalogComparator.h"

void AnalogComparator::Enable()
{	
	__RESET_BIT(DIDR, AIN0D);
	__RESET_BIT(DIDR, AIN1D);
	
	__RESET_BIT(ACSR, ACD);
}

void AnalogComparator::Disable()
{		
	__SET_BIT(ACSR, ACD);
}

bool AnalogComparator::GetValue()
{
	return __IS_SET_BIT(ACSR, ACO);	
}

