// Copyright © 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com
#ifndef __INTERRUPTS_H__
#define __INTERRUPTS_H__

#pragma once

namespace OS {
namespace System {

class Interrupts
{
public:
	static void EnableAll();
	static void DisableAll();
	static void EnableTimer0();
	static void DisableTimer0();
	static void EnableTimer1();
	static void DisableTimer1();
	static void EnableRxUart();
	static void DisableRxUart();
	static void EnableTxUart();
	static void DisableTxUart();

}; //Interrupts

}}

#endif //__INTERRUPTS_H__
