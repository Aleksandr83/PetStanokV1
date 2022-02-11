// Copyright (c) 2022 Lukin Aleksandr
#ifndef __PETSTANOK_H__
#define __PETSTANOK_H__

#include "PreCompiller.h"
#include "Led.h"
#include "Heater.h"
#include "AnalogComparator.h"
#include "Stepper.h"
#include "Timers.h"

#pragma once

using OS::System::Timer0;
using OS::Drivers::Stepper;

class PetStanok
{
//private:
public:
	static Led				_Led;
	static Heater			_Heater;	
	static AnalogComparator _AnalogComparator;		
	static Stepper			_Stepper;
	
	static Timer0			_TimerCheckingTemperature;
			

public:
	static void Run();
	
private:
	static void Init();	
	static void LedToggleOnStart();	
	static bool IsTemperatureCorrect();	

	static void OnTimerCheckingTemperature();

}; //PetStanok

#endif //__PETSTANOK_H__
