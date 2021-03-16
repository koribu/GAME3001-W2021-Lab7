#include "AttackAction.h"

#include <iostream>

AttackAction::AttackAction()
{
	name = "Move To Player Action";
}

AttackAction::~AttackAction()
= default;

void AttackAction::Action()
{
	std::cout << "Performing Player Action" << std::endl;
}


