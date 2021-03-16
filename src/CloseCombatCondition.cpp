#include "CloseCombatCondition.h"

#include <iostream>

CloseCombatCondition::CloseCombatCondition(bool withinCombatRange)
{
	setIsWithinCombatRange(withinCombatRange);
	name = "Close Combat Condition";
}

CloseCombatCondition::~CloseCombatCondition()
= default;

void CloseCombatCondition::setIsWithinCombatRange(bool state)
{
	m_isWithinCombatRange = state;
	data = state;
}


bool CloseCombatCondition::Condition()
{
	return m_isWithinCombatRange;
}


