// Copyright (c) 2022 Lukin Aleksandr
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

}; //Interrupts

}}

#endif //__INTERRUPTS_H__
