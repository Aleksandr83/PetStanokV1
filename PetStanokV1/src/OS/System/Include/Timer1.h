// Copyright © 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com
#ifndef __TIMER1_H__
#define __TIMER1_H__

#pragma once

#include "PreCompiller.h"
#include "Timers.h"

namespace OS {
namespace System {

class Timer1
{
public:
	typedef void (* TimerCallbackMethod_t)();
private:
	static Timer1* _Timer1;

	TimerCallbackMethod_t _Callback;
	
public:
	Timer1();
	
	void SetTimerPrescaler(TTimerPrescaler value);

	void Start();
	void Start(TimerCallbackMethod_t callback);
	void Stop();

	static void OnTimerInterrupt();

private:
	void Init();
	void Reset();	

}; //Timer1


}}

#endif //__TIMER1_H__
