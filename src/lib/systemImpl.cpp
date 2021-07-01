#include "systemImpl.h"

/**
  * \return System
  */
SystemImpl::SystemImpl()
{
	value = 0;
	name = "";
}

/**
  * \param valueSystem is the current amount or energy
  * \param nameSystem is the name of the system
  * \return System
  */
SystemImpl::SystemImpl(string nameSystem, float valueSystem)
{
	value = valueSystem;
	name = nameSystem;
}

/**
  * \param system is a System, and the new one gonna be a copy of it
  * \return System
  */
SystemImpl::SystemImpl(SystemImpl* system)
{
	value = system->value;
	name = system->name;
}

/**
  * \return
  */
SystemImpl::~SystemImpl()
{
}

/**
  * \param quantity is the new system value
  * \return void
  */
void SystemImpl::setValue(float quantity)
{
	value = quantity;
}

/**
  * \param id is the new name of the system
  * \return void
  */
void SystemImpl::setName(string id)
{
	name = id;
}

/**
  * \return double
  */
double SystemImpl::getValue()
{
	return value;
}

/**
  * \return string
  */
string SystemImpl::getName()
{
	return name;
}

/** \param valueSytem is the quantity that gonna be add to the System quantity
  * \return void
  *
  **/
void SystemImpl::increaseQuantity(float valueSystem)
{
	value += valueSystem;
}

/** \param valueSystem is the quantity that gonna be remove to the System quantity
  * \return void
  *
  **/
void SystemImpl::decreaseQuantity(float valueSystem)
{
	value -= valueSystem;
}

/**
  * \param system is the System that gonna be copied
  * \return System&
  */
SystemImpl& SystemImpl::operator= (const SystemImpl& system)
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
bool SystemImpl::operator== (const SystemImpl& system)
{
	if (name == system.name && value == system.value)
		return true;

	return false;
}