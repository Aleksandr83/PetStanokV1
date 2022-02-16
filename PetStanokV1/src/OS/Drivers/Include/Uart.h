// Copyright © 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com
#ifndef __UART_H__
#define __UART_H__

#pragma once

#include "Fifo.h"

#ifndef UMSEL
#define UMSEL 6
#endif

namespace OS {
namespace Drivers {
	
using OS::Types::Generic::Fifo;	
	
class Uart
{	
private:
	enum TUartMode
	{
		Asynchronous = 0,
		Synchronous  = 1
	};
	
//public:
	static Fifo _RxBuffer;
	static Fifo _TxBuffer;
	
	static bool _IsSendComplete;

public:
	static void Init();

	static Fifo* GetRxBuffer();
	static Fifo* GetTxBuffer();

	static void PushInTxBuffer(uint8_t value);
	static void Send(const char* format, ...);
	static void RunSend();		
	
	static inline void OnTxData();
	static inline void OnRxData(uint8_t value);
	
private:
	static inline void SetMode(TUartMode mode);
	static inline void SetBaudRate();
	
	static inline void Flush();
	static inline void EnableReceiver();
	static inline void EnableTransmitter();
	static inline void SetFrameFormat();	
		
}; //Uart

}}

#endif //__UART_H__
