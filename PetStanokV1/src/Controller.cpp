// Copyright © 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com
#include "Controller.h"
#include "Led.h"
#include "PetStanok.h"
#include "StepperState.h"

#define __IS_READ_PACKAGE		0
#define __IS_CHECK_DEVICEADDR	1

using OS::Drivers::StepperDirection;
using OS::Drivers::StepperMode;

Package Controller::_Package;
Timer0	Controller::_TimerCheckingRxControlPackages;
uint8_t Controller::_State  = 0;
uint8_t Controller::_Status = 0;

void Controller::Init()
{		
	Uart::Init();	
	PackageReader::Init();
	PackageReader::SetBuffer(Uart::GetRxBuffer());
	PackageReader::SetPackage(&_Package);	
}

void Controller::Run()
{
	Init();	
	
	_TimerCheckingRxControlPackages.Start(Controller::OnTimerCheckingRxControlPackages);
}

uint8_t Controller::CalcPackageCheckSum()
{
	uint8_t  crc = 0;
	uint8_t* ptr = (uint8_t*)&_Package;
	for (uint8_t i=0; i<5; i++)
	{						
		crc = crc ^ (*(uint8_t*)(ptr+i));			
		for (uint8_t j=0; j<8; j++)
		{
			if (crc & 0x01) 
				crc = (crc >> 1) ^ __CRC8_POLY;
			else 
				crc >>= 1;
		}
	}	
	return crc;
}

bool Controller::CheckPackageCheckSum()
{
	return (_Package.Checksum == CalcPackageCheckSum());	
}

#define __MAX_TIMER_ACTIONS 4

void Controller::OnTimerCheckingRxControlPackages()
{	
	if (!PetStanok::_IsInit) return;
	int n;
	n = (_State % __MAX_TIMER_ACTIONS);
	switch (n)
	{
		case 0:			
			PetStanok::OnTimerCheckingTemperature();
			break;
		case 1:
			if (PackageReader::Read())
			{
				__SET_BIT(_Status,__IS_READ_PACKAGE);								
			}
			break;
		case 2:
			if (__IS_SET_BIT(_Status,__IS_READ_PACKAGE))
			{
				Check();
			}
			break;
		case 3:
			if (__IS_SET_BIT(_Status,__IS_READ_PACKAGE))
			{				
				Controller::Execute();				
			}
			__RESET_BIT(_Status,__IS_READ_PACKAGE);			
			break;
		default:
			_State = -1;		
			break;
	}
	_State++;
}

void Controller::Check()
{
	uint16_t devAddr;
	devAddr  = _Package.DestAddrH << 8;
	devAddr |= _Package.DestAddrL;
	if (devAddr != __DEVICE_ADDR)
		__RESET_BIT(_Status,__IS_READ_PACKAGE);	
	//if (!CheckPackageCheckSum())
	//	__RESET_BIT(_Status,__IS_READ_PACKAGE);	
}

void Controller::Execute()
{		
	if (_Package.Command ==  TCommand::Sleep)
	{
		//Led::Toggle();	
		if (_Package.CommandParameter)
			PetStanok::_Stepper.Sleep();
		else	
			PetStanok::_Stepper.Unsleep();
		return;
	}
	if (_Package.Command == TCommand::Pause)
	{			
		switch (_Package.CommandParameter)
		{			
			case 0:
				StepperState::_IsPause = false;				
				break;
			case 0xFF:
				StepperState::_IsPause = true;
				break;			
		}				
		return;
	}
	
	if (_Package.Command ==  TCommand::StopWaitTemperature)
	{		
		//Led::Toggle();
		PetStanok::_IsCancelWaitTemperature = true;
		return;
	}
	if (_Package.Command == TCommand::StepperDir)
	{		
		//Led::Toggle();		
		if (_Package.CommandParameter == StepperDirection::TStepperDirection::Normal)
			PetStanok::_Stepper.SetDirection(StepperDirection::TStepperDirection::Normal);
		else
		  if (_Package.CommandParameter == StepperDirection::TStepperDirection::Reverse)
			PetStanok::_Stepper.SetDirection(StepperDirection::TStepperDirection::Reverse);
		return;
	}
	if (_Package.Command == TCommand::StepperMode)
	{
		//Led::Toggle();
		if (_Package.CommandParameter == StepperMode::TStepperMode::FullStep)
		{
			PetStanok::_Stepper.SetMode(StepperMode::TStepperMode::FullStep);
			return;
		}
		if (_Package.CommandParameter == StepperMode::TStepperMode::Step_1_2)
		{
			PetStanok::_Stepper.SetMode(StepperMode::TStepperMode::Step_1_2);
			return;
		}
		if (_Package.CommandParameter == StepperMode::TStepperMode::Step_1_4)
		{
			PetStanok::_Stepper.SetMode(StepperMode::TStepperMode::Step_1_4);
			return;
		}
		if (_Package.CommandParameter == StepperMode::TStepperMode::Step_1_8)
		{
			PetStanok::_Stepper.SetMode(StepperMode::TStepperMode::Step_1_8);
			return;
		}
		if (_Package.CommandParameter == StepperMode::TStepperMode::Step_1_16)
		{
			PetStanok::_Stepper.SetMode(StepperMode::TStepperMode::Step_1_16);
			return;
		}
	}
	
}


