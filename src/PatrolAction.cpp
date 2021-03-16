#include "PatrolAction.h"

#include <iostream>

PatrolAction::PatrolAction()
{
	name = "Patrol Action";
}

PatrolAction::~PatrolAction()
= default;

bool PatrolAction::Action()
{
	std::cout << "Performing Patrol Action" << std::endl;
}


