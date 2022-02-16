// Copyright © 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com
#include "Interrupts.h"
#include "PreCompiller.h"

namespace OS {
namespace System {

void Interrupts::EnableAll()
{
	sei();
}

void Interrupts::DisableAll()
{
	cli();
}

void Interrupts::EnableTimer0()
{	
	__SET_BIT(TIMSK,TOIE0);
}

void Interrupts::DisableTimer0()
{		
	__RESET_BIT(TIMSK,TOIE0);
}

void Interrupts::EnableTimer1()
{
	__SET_BIT(TIMSK,TOIE1);
}

void Interrupts::DisableTimer1()
{
	__RESET_BIT(TIMSK,TOIE1);
}

void Interrupts::EnableRxUart()
{
	__SET_BIT(UCSRB,RXCIE);
}

void Interrupts::DisableRxUart()
{
	__RESET_BIT(UCSRB,RXCIE);
}

void Interrupts::EnableTxUart()
{
	__SET_BIT(UCSRB,TXCIE);
}

void Interrupts::DisableTxUart()
{
	__RESET_BIT(UCSRB,TXCIE);
}

}}
