#include "MoveToPlayerAction.h"

#include <iostream>

MoveToPlayerAction::MoveToPlayerAction()
{
	name = "Move To Player Action";
}

MoveToPlayerAction::~MoveToPlayerAction()
= default;

bool MoveToPlayerAction::Action()
{
	std::cout << "Performing Player Action" << std::endl;
}


