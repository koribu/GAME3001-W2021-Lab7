#include "MoveToLOSAction.h"

#include <iostream>

MoveToLOSAction::MoveToLOSAction()
{
	name = "Move To LOS Action";
}

MoveToLOSAction::~MoveToLOSAction()
= default;

void MoveToLOSAction::Action()
{
	std::cout << "Performing MoveToLOS Action" << std::endl;
}


