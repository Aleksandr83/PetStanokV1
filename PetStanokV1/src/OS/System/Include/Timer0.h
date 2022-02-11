// Copyright (c) 2022 Lukin Aleksandr
#ifndef __TIMER0_H__
#define __TIMER0_H__

#pragma once

#include "Timers.h"

namespace OS {
namespace System {	
	
	
class Timer0
{
public:
	typedef void (* TimerCallbackMethod_t)();
private:	
	static Timer0* _Timer0;	
	
	TimerCallbackMethod_t _Callback;
	
public:
	Timer0();
			
	void SetTimerPrescaler(TTimerPrescaler value);

	void Start();
	void Start(TimerCallbackMethod_t callback);
	void Stop();

	static void OnTimerInterrupt();
	
private:
	void Init();
	void Reset();	
	
}; //Timer0

}}

#endif //__TIMER0_H__
