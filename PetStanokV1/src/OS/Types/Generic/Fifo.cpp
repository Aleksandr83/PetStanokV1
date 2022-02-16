// Copyright © 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com
#include "Fifo.h"

namespace OS {
namespace Types {
namespace Generic {

Fifo::Fifo()
{	
} 

bool Fifo::IsFull()
{
	return (_Count == __MAX_BUFFER_SIZE);
}

bool Fifo::IsEmpty()
{
	return ((AddOne(_Rear) == _Front)&&(!_Count))? true :false;	
}

uint8_t Fifo::GetCount()
{
	return _Count;
}

uint8_t Fifo::GetValue()
{
	return _Data[_Front];
}

void Fifo::Clear()
{
	uint8_t i;
	_Count = 0;
	_Front = 0;
	_Rear  = __MAX_BUFFER_SIZE -1;
	for (i = 0;i < __MAX_BUFFER_SIZE;i++)
	{
		_Data[i] = __EMPTY_VALUE;
	}	
}

uint8_t Fifo::AddOne(uint8_t value)
{
	return ((value+1) % (__MAX_BUFFER_SIZE));		
}

bool Fifo::Enqueue(uint8_t value)
{	
	if (!((AddOne(AddOne(_Rear)) == _Front)&&(_Count < __MAX_BUFFER_SIZE)))
	{
		_Rear = AddOne(_Rear);
		_Data[_Rear] = value;
		_Count++;
		return true;
	}
	return false;
}

uint8_t Fifo::Dequeue()
{
	uint8_t result = 0;
	if (!IsEmpty())
	{
		result = GetValue();
		_Front = AddOne(_Front);
		_Count--;
	}	
	return result;
}

}}}
