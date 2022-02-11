// Copyright (c) 2022 Lukin Aleksandr
#ifndef TIMERS_H_
#define TIMERS_H_

#pragma once

#include "PreCompiller.h"

namespace OS {
namespace System {

enum TTimerPrescaler
{
	NoClockSource		= 0,
	NoClockPrescaling	= 1,
	ClockPrescaling8	= 2,
	ClockPrescaling64	= 3,
	ClockPrescaling256	= 4,
	ClockPrescaling1024	= 5,
};


}}

#include "Timer0.h"
	

#endif /* TIMERS_H_ */