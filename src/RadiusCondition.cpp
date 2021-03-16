#include "RadiusCondition.h"

#include <iostream>

RadiusCondition::RadiusCondition(bool withinRadius)
{
	setIsWithinRadius(withinRadius);
	name = "Radius Condition";
}

RadiusCondition::~RadiusCondition()
= default;

void RadiusCondition::setIsWithinRadius(bool state)
{
	m_isWithinRadius = state;
	data = state;
}


bool RadiusCondition::Condition()
{
	return m_isWithinRadius;
}


