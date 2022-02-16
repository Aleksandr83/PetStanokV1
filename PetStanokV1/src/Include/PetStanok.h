// Copyright © 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com
#ifndef __PETSTANOK_H__
#define __PETSTANOK_H__

#include "PreCompiller.h"
#include "Led.h"
#include "Heater.h"
#include "AnalogComparator.h"
#include "Stepper.h"
#include "Timers.h"
#include "Controller.h"

#pragma once

using OS::System::Timer1;
using OS::Drivers::Stepper;

class PetStanok
{

private:	
	static Heater			_Heater;	
	static AnalogComparator _AnalogComparator;		
	static Stepper			_Stepper;	
	
	static bool             _IsInit;
	//static Timer1			_TimerCheckingTemperature;			
	static bool				_IsCancelWaitTemperature;
public:
	static void Init();	
	
	static void Run();
	
private:		
	static inline void LedToggleOnStart();	
	static bool IsTemperatureCorrect();	
	
	
private:
	static void OnTimerCheckingTemperature();

	friend class Controller;
	
}; //PetStanok

#endif //__PETSTANOK_H__
