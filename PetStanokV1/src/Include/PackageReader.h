// Copyright © 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com
#ifndef __PACKAGEREADER_H__
#define __PACKAGEREADER_H__

#pragma once 

#include "Fifo.h"
#include "Package.h"

using OS::Types::Generic::Fifo;

class PackageReader
{
private:
	static const uint8_t __START_PACKAGE = '$';
	static const uint8_t __END_PACKAGE   = '#';

	typedef void (* TStepFunc)();

	static uint8_t   _Byte;
	static TStepFunc _Table[8];
	static uint8_t	 _State;
	static bool		 _IsStartPackage;
	static bool      _IsEndPackage;

	static Fifo*     _Buffer;
	static Package*  _Package;

public:	
	static void Init();	
	
	static void SetBuffer(Fifo* buffer);
	static void SetPackage(Package* package);

	static bool Read();

private:
	static void Stage0(); // Read Start Package
	static void Stage1(); // Read Device Address High Byte
	static void Stage2(); // Read Device Address Low Byte
	static void Stage3(); // Read Operation
	static void Stage4(); // Read Command
	static void Stage5(); // Read Command Parameter
	static void Stage6(); // Read Checksum
	static void Stage7(); // Read End Package
	


}; //PackageReader

#endif //__PACKAGEREADER_H__
