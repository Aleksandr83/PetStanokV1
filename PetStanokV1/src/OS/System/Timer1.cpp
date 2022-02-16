// Copyright © 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com
#include "Timer1.h"
#include "Interrupts.h"

namespace OS {
namespace System {

using OS::System::Interrupts;

Timer1* Timer1::_Timer1 = NULL;

Timer1::Timer1()
{
	if (Timer1::_Timer1 == NULL)
	Timer1::_Timer1 = this;
	Init();
} 

void Timer1::Init()
{
	TCCR1A  = 0;
	OCR1A   = 0;
	OCR1B   = 0;
	SetTimerPrescaler(TTimerPrescaler::ClockPrescaling64);
	Reset();
	Interrupts::DisableTimer1();
}

void Timer1::Reset()
{
	TCNT1 = 0;
	__RESET_BIT(TIFR, TOV1);
}

void Timer1::SetTimerPrescaler(TTimerPrescaler value)
{
	TCCR1B |= (uint8_t) value;
}

void Timer1::Start()
{
	_Callback = NULL;
	Reset();
	Interrupts::EnableTimer1();
}

void Timer1::Start(TimerCallbackMethod_t callback)
{
	_Callback = callback;
	Reset();
	Interrupts::EnableTimer1();
}

void Timer1::Stop()
{
	Interrupts::DisableTimer1();
}

void Timer1::OnTimerInterrupt()
{
	if (Timer1::_Timer1 == NULL) return;
	if (Timer1::_Timer1->_Callback != NULL)
	Timer1::_Timer1->_Callback();
	Timer1::_Timer1->Reset();
}

ISR(TIMER1_OVF_vect)
{
	Interrupts::DisableAll();
	//Timer1::OnTimerInterrupt();
	Interrupts::EnableAll();
	return;
}

}}