// Copyright (c) 2022 Lukin Aleksandr
#include "PetStanok.h"
#include "Interrupts.h"

using OS::System::Interrupts;

Led				 PetStanok::_Led;
Heater			 PetStanok::_Heater;
AnalogComparator PetStanok::_AnalogComparator;
Stepper			 PetStanok::_Stepper;
Timer0			 PetStanok::_TimerCheckingTemperature;

void PetStanok::Init()
{
	LedToggleOnStart();
	_Stepper.Init();
	_AnalogComparator.Enable();	
	Interrupts::EnableAll();
}

void PetStanok::Run()
{
	Init();
	_TimerCheckingTemperature.Start(PetStanok::OnTimerCheckingTemperature);
	
	_Stepper.Sleep();
	while(!IsTemperatureCorrect());
	_Stepper.Unsleep();
	
	for(;;)
	{		
		_Stepper.Step();
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
		_Led.On();
		_delay_ms(__DELAY_LED_TOGGLE);
		_Led.Off();
		_delay_ms(__DELAY_LED_TOGGLE);
	}
#endif
}

