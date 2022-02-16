// Copyright © 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com
#ifndef __LED_H__
#define __LED_H__

#pragma once

class Led 
{

public:
	Led();
	
	static void Init();
		
	static void On();
	static void Off();

	static void Toggle();
	
}; //Led

#endif //__LED_H__
