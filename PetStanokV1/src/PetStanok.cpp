// Copyright © 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com
#include "PetStanok.h"
#include "Interrupts.h"
#include "Uart.h"

using OS::System::Interrupts;

Heater			 PetStanok::_Heater;
AnalogComparator PetStanok::_AnalogComparator;
Stepper			 PetStanok::_Stepper;

bool             PetStanok::_IsInit  = false;
//Timer1			 PetStanok::_TimerCheckingTemperature;
bool			 PetStanok::_IsCancelWaitTemperature;

void PetStanok::Init()
{
	Led::Init();
	LedToggleOnStart();
	_Stepper.Init();
	_AnalogComparator.Enable();		
	_IsInit = true;
}

void PetStanok::Run()
{
	//Init();
	//_TimerCheckingTemperature.Start(PetStanok::OnTimerCheckingTemperature);
	
	_Stepper.Sleep();
	_IsCancelWaitTemperature = false;
	while(!IsTemperatureCorrect())
	{ 
		if (_IsCancelWaitTemperature) break; 
	};
	_Stepper.Unsleep();		
	for(;;)
	{		
		PetStanok::_Stepper.Step();	
	}
}


bool PetStanok::IsTemperatureCorrect()
{
	return (bool)_AnalogComparator.GetValue();
}

void PetStanok::OnTimerCheckingTemperature()
{	
	if (!IsTemperatureCorrect())
	{
		_Heater.On();	
	}
	else
	{
		_Heater.Off();	
	}
}

void PetStanok::LedToggleOnStart()
{
#if (__ENABLE_LED_TOGLE_ON_START != 0)
	for (int i = 0; i < __COUNT_LED_TOGGLE; i++)
	{
		Led::Toggle();			
	}
#endif
}

