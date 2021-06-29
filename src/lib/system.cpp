#include "system.h"

System::System()
{
	value = 0;
	name = "";
}

System::System(string name2, double value2)
{
	value = value2;
	name = name2;
}

System::System(System* system)
{
	value = system->value;
	name = system->name;
}

System::~System()
{
}

void System::setValue(double quantity)
{
	value = quantity;
}

void System::setName(string id)
{
	name = id;
}

double System::getValue()
{
	return value;
}

string System::getName()
{
	return name;
}

void System::increaseQuantity(double value2)
{
	value += value2;
}

void System::decreaseQuantity(double value2)
{
	value -= value2;
}

System& System::operator= (const System& system)
{
	if (this == &system)
		return *this;

	name = system.name;
	value = system.value;

	return *this;
}

bool System::operator== (const System& system)
{
	if (name == system.name && value == system.value)
		return true;

	return false;
}