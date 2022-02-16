// Copyright © 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com
#include "Uart.h"
#include "Interrupts.h"

namespace OS {
namespace Drivers {
		
using OS::System::Interrupts;	

#if (__IS_USE_UART_RX != 0)	
Fifo Uart::_RxBuffer;	
#endif

#if (__IS_USE_UART_TX != 0)
Fifo Uart::_TxBuffer;
#endif

bool Uart::_IsSendComplete;
		
void Uart::Init()
{
	Flush();
	SetBaudRate();
	SetFrameFormat();
	SetMode(TUartMode::Asynchronous);	
#if (__IS_USE_UART_RX != 0)
	EnableReceiver();
	_RxBuffer.Clear();
#endif
#if (__IS_USE_UART_TX != 0)
	EnableTransmitter();
	_TxBuffer.Clear();	
	_IsSendComplete = true;
#endif		
#if (__IS_USE_UART_RX != 0)	
	Interrupts::EnableRxUart();
#endif
#if (__IS_USE_UART_TX != 0)
	Interrupts::EnableTxUart();
#endif
	UDR = '\n';		
}

void Uart::SetMode(TUartMode mode)
{
	if (mode == TUartMode::Asynchronous)
		__RESET_BIT(UCSRC, UMSEL);
	else
		__SET_BIT(UCSRC, UMSEL);
}

void Uart::SetBaudRate()
{	
	uint16_t baud = 25;	// 4800 on 16 MHz
	UBRRH = (unsigned char)(baud>>8);
	UBRRL = (unsigned char) baud;
}

void Uart::Flush()
{
	uint8_t dummy = 0;
	while (__IS_SET_BIT(UCSRA,RXC))
	{
		dummy = UDR;
	}
	if (dummy == 0){}
	UDR = 0x20;			
}

void Uart::EnableReceiver()
{	
	__SET_BIT(UCSRB,RXEN);
}

void Uart::EnableTransmitter()
{
	__SET_BIT(UCSRB,TXEN);
}

void Uart::SetFrameFormat()
{	
	// 8data, 2stop bit
	UCSRC |= (1<<USBS)|(3<<UCSZ0); 
}

void Uart::RunSend()
{
#if (__IS_USE_UART_TX != 0)
	if (!_TxBuffer.IsEmpty()&& _IsSendComplete)
	{
		_IsSendComplete = false;		
		__RESET_BIT(UCSRA, TXC);
		UDR = 0x20;
	}	
#endif
}

void Uart::PushInTxBuffer(uint8_t value)
{
	_TxBuffer.Enqueue(value);
}

void Uart::Send(const char* format, ...)
{			
#if (__IS_USE_UART_TX != 0)	
	uint8_t n = strlen(format);	
	for (uint8_t i = 0; i < n; i++)
	{		
		_TxBuffer.Enqueue(*(format+i));		
	}	
	
	RunSend();	
#endif	
}

Fifo* Uart::GetRxBuffer()
{
	return &_RxBuffer;
}

Fifo* Uart::GetTxBuffer()
{
	return &_TxBuffer;
}

void Uart::OnTxData()
{
	uint8_t value;
	if (_TxBuffer.IsEmpty()) 
	{
		_IsSendComplete = true;
		return;
	}
	value = _TxBuffer.Dequeue();		
	UDR   = value;
}

void Uart::OnRxData(uint8_t value)
{
	_RxBuffer.Enqueue(value);	
}

ISR(USART_RX_vect)
{
#if (__IS_USE_UART_RX != 0)
	Interrupts::DisableRxUart();
	while (!__IS_SET_BIT(UCSRA, RXC));	
	Uart::OnRxData(UDR);
	Interrupts::EnableRxUart();
#endif
}

ISR(USART_TX_vect)
{
#if (__IS_USE_UART_TX != 0)
	Interrupts::DisableTxUart();
	while (!__IS_SET_BIT(UCSRA, UDRE));
	Uart::OnTxData();
	Interrupts::EnableTxUart();
#endif
}

}}

