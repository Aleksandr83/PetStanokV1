// Copyright © 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com
#include "PackageReader.h"
#include "Uart.h"

using OS::Drivers::Uart;

uint8_t   PackageReader::_Byte;
uint8_t	  PackageReader::_State = 0;
bool	  PackageReader::_IsStartPackage = false;
bool      PackageReader::_IsEndPackage   = false;
Package*  PackageReader::_Package;
Fifo*     PackageReader::_Buffer;

PackageReader::TStepFunc PackageReader::_Table[8];

void PackageReader::Init()
{
	_Table[0] = PackageReader::Stage0;
	_Table[1] = PackageReader::Stage1;
	_Table[2] = PackageReader::Stage2;
	_Table[3] = PackageReader::Stage3;
	_Table[4] = PackageReader::Stage4;
	_Table[5] = PackageReader::Stage5;
	_Table[6] = PackageReader::Stage6;
	_Table[7] = PackageReader::Stage7;

} 

void PackageReader::SetBuffer(Fifo* buffer)
{
	_Buffer = buffer;
}

void PackageReader::SetPackage(Package* package)
{
	_Package = package;
}

bool PackageReader::Read()
{
	bool result = false;

	while (!_Buffer->IsEmpty()&&!_IsEndPackage)
	{		
		_Byte = _Buffer->Dequeue();		
		_Table[_State++]();
	} 

	if (_IsStartPackage&&_IsEndPackage)
	{	
		_IsEndPackage = false;
		result = true;
	}	
	return result;
}

void PackageReader::Stage0()
{
	if (_Byte != __START_PACKAGE)
	{
		_State = -1;
		return;
	}
	_IsStartPackage = true;
}

void PackageReader::Stage1()
{
	_Package->DestAddrH  = _Byte;
}

void PackageReader::Stage2()
{
	_Package->DestAddrL  = _Byte;
}

void PackageReader::Stage3()
{
	_Package->Operation  = _Byte;
}

void PackageReader::Stage4()
{
	_Package->Command  = _Byte;
}

void PackageReader::Stage5()
{
	_Package->CommandParameter = _Byte;
}

void PackageReader::Stage6()
{
	_Package->Checksum = _Byte;
}

void PackageReader::Stage7()
{
	if (_Byte == __END_PACKAGE)
	{		
		_IsEndPackage = true;
	}
	_State = 0;
}

