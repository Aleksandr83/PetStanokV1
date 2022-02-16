// Copyright © 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com
#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__

#pragma once

#include "Uart.h"
#include "Timers.h"
#include "PackageReader.h"

using OS::Drivers::Uart;
using OS::System::Timer0;

class Controller
{
private:
	enum TOperation
	{		
		Read   = 0,
		Write  = 1,
		Load   = 2,
		Save   = 3		
	};
	
	enum TCommand
	{		
		Sleep				= 0xF7,
		Pause				= 0x7B,
		StepperDir			= 0xEF,
		StepperMode			= 0xC6,
		StopWaitTemperature = 0x8A
	};	
	
	static Package _Package;
	
private:	
	static Timer0	_TimerCheckingRxControlPackages;
	static uint8_t  _State;
	static uint8_t  _Status;
	
public:
	static void Init();
	
	static void Run();
	
private:	
	static void Check();
	static void Execute();
	
	static inline uint8_t CalcPackageCheckSum();
	static		  bool    CheckPackageCheckSum();		
	
	static void OnTimerCheckingRxControlPackages();

}; //Controller

#endif //__CONTROLLER_H__
