// Copyright © 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com
#ifndef PACKAGE_H_
#define PACKAGE_H_

#pragma once

#include "PreCompiller.h"


struct Package
{
	uint8_t  DestAddrH;
	uint8_t  DestAddrL;
	uint8_t  Operation;
	uint8_t  Command;
	uint8_t  CommandParameter;
	uint8_t  Checksum;
};


#endif /* PACKAGE_H_ */