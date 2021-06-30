#include "system.h"

/**
  * \return System
  */
System::System()
{
	value = 0;
	name = "";
}

/**
  * \param valueSystem is the current amount or energy
  * \param nameSystem is the name of the system
  * \return System
  */
System::System(string nameSystem, float valueSystem)
{
	value = valueSystem;
	name = nameSystem;
}

/**
  * \param system is a System, and the new one gonna be a copy of it
  * \return System
  */
System::System(System* system)
{
	value = system->value;
	name = system->name;
}

/**
  * \return
  */
System::~System()
{
}

/**
  * \param quantity is the new system value
  * \return void
  */
void System::setValue(float quantity)
{
	value = quantity;
}

/**
  * \param id is the new name of the system
  * \return void
  */
void System::setName(string id)
{
	name = id;
}

/**
  * \return double
  */
double System::getValue()
{
	return value;
}

/**
  * \return string
  */
string System::getName()
{
	return name;
}

/** \param valueSytem is the quantity that gonna be add to the System quantity
  * \return void
  *
  **/
void System::increaseQuantity(float valueSystem)
{
	value += valueSystem;
}

/** \param valueSystem is the quantity that gonna be remove to the System quantity
  * \return void
  *
  **/
void System::decreaseQuantity(float valueSystem)
{
	value -= valueSystem;
}

/**
  * \param system is the System that gonna be copied
  * \return System&
  */
System& System::operator= (const System& system)
{
	if (this == &system)
		return *this;

	name = system.name;
	value = system.value;

	return *this;
}

/**
  * \param system is the System that gonna be compared with the System that call this function
  * \return bool
  */
bool System::operator== (const System& system)
{
	if (name == system.name && value == system.value)
		return true;

	return false;
}