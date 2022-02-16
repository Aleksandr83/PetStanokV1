// Copyright © 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com
#ifndef __FIFO_H__
#define __FIFO_H__

#pragma once

#include "PreCompiller.h"

namespace OS {
namespace Types {
namespace Generic {

class Fifo
{
public:
	static const uint8_t __EMPTY_VALUE		= 0;
	static const uint8_t __MAX_BUFFER_SIZE	= __BUFFER_SIZE;
	
private:
	uint8_t _Count;
	uint8_t _Front;
	uint8_t _Rear;
	uint8_t _Data[__MAX_BUFFER_SIZE];
	
public:
	Fifo();

	bool	IsFull();
	bool    IsEmpty();
	uint8_t GetCount();	
	uint8_t GetValue();
	
	bool    Enqueue(uint8_t value);	
	uint8_t Dequeue();
	   
	void Clear();
	
private:
	inline uint8_t AddOne(uint8_t value);

}; //Fifo

}}}

#endif //__FIFO_H__
