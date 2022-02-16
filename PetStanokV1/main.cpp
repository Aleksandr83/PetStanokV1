// Copyright © 2022 Lukin Aleksandr
// e-mail: lukin.a.g.spb@gmail.com
#include "PetStanok.h" 
#include "Controller.h"
#include "Interrupts.h"
 
using OS::System::Interrupts;
 

int main(void)
{	

	Controller::Init();
	PetStanok ::Init();
	
	Interrupts::EnableAll();

	Controller::Run();	
	PetStanok ::Run();
	
	//for(;;){}
}

