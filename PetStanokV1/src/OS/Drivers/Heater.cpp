// Copyright (c) 2022 Lukin Aleksandr
#include "Heater.h"
#include "PreCompiller.h"

Heater::Heater() 	
{	
	__SET_BIT(__HEATER_DIR_REGISTER, __HEATER);
	__RESET_BIT(__HEATER_PORT, __HEATER);
}

void Heater::On() 
{
	__SET_BIT(__HEATER_PORT, __HEATER);
	_Led.On();
}

 void Heater::Off()
 {
	 __RESET_BIT(__HEATER_PORT, __HEATER);
	 _Led.Off();
 }

//Heater::~Heater()
//{
//} 
