#include "flow.h"

/**
  * \return Flow
  */
Flow::Flow()
{
	sourceSystem = NULL;
	targetSystem = NULL;
	name[0] = '\0';
}

/**
  * \param id is the flow's name
  * \param source is the System that gonna give energy
  * \param target is the System that gonna recive the energy
  * \return Flow
  */
Flow::Flow(string id, System* source, System* target)
{
	sourceSystem = source;
	targetSystem = target;
	name = id;
}

/**
  * \return
  */
Flow::~Flow()
{
}

/**
  * \param id is the Flow's name
  * \return void
  */
void Flow::setName(string id)
{
	name = id;
}

/**
  * \return string
  */
string Flow::getName()
{
	return name;
}

/**
  * \return System*
  */
System* Flow::getSourceSystem()
{
	return sourceSystem;
}

/**
  * \return System*
  */
System* Flow::getTargetSystem()
{
	return targetSystem;
}

/** \param s is the system that will be connected to the source system
  * \return void
  *
  **/
void Flow:: setSourceSystem(System* s)
{
	sourceSystem = s;
}

/** \param s is the system that will be connected to the target system
  * \return void
  *
  **/
void Flow::setTargetSystem(System* s)
{
	targetSystem = s;
}

/**
  * \param flow is a flow that gonna be copied
  * \return Flow&
  */
Flow& Flow::operator= (const Flow& flow)
{
	if (this == &flow)
		return *this;

	name = flow.name;

	sourceSystem = flow.sourceSystem;
	targetSystem = flow.targetSystem;

	return *this;
}

/**
  * \param flow is a flow that gonna be compared with the Flow that call this function
  * \return bool
  */
bool Flow::operator== (const Flow& flow)
{
	if (name == flow.name && sourceSystem == flow.sourceSystem && targetSystem == flow.targetSystem)
		return true;

	return false;
}