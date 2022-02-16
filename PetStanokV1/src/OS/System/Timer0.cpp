// Copyright © 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com
#include "Timer0.h"
#include "Interrupts.h"

namespace OS {
namespace System {

using OS::System::Interrupts;

Timer0* Timer0::_Timer0 = NULL;


Timer0::Timer0()
{
	if (Timer0::_Timer0 == NULL)
		Timer0::_Timer0 = this;
	Init();
} 

void Timer0::Init()
{	
	TCCR0A  = 0;
	OCR0A   = 0;
	OCR0B   = 0;
	SetTimerPrescaler(TTimerPrescaler::ClockPrescaling64);
	Reset();	
	Interrupts::DisableTimer0();
}

void Timer0::Reset()
{
	TCNT0 = 0;
	__RESET_BIT(TIFR, TOV0);	
}

void Timer0::SetTimerPrescaler(TTimerPrescaler value)
{
	TCCR0B |= (uint8_t) value;
}

void Timer0::Start()
{
	_Callback = NULL;
	Reset();
	Interrupts::EnableTimer0();
}

void Timer0::Start(TimerCallbackMethod_t callback)
{	
	_Callback = callback;	
	Reset();
	Interrupts::EnableTimer0();
}

void Timer0::Stop()
{
	Interrupts::DisableTimer0();
}

void Timer0::OnTimerInterrupt()
{
	//if (Timer0::_Timer0 == NULL) return;
	//if (Timer0::_Timer0->_Callback != NULL)	
		Timer0::_Timer0->_Callback();
	Timer0::_Timer0->Reset();
}



ISR(TIMER0_OVF_vect)
{
	Interrupts::DisableAll();
	Timer0::OnTimerInterrupt();
	Interrupts::EnableAll();
	return;
}

}}