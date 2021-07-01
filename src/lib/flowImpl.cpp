#include "flowImpl.h"

/**
  * \return Flow
  */
FlowImpl::FlowImpl()
{
	sourceSystem = NULL;
	targetSystem = NULL;
	name[0] = '\0';
}

/**
  * \param flow is the flow to be copied
  * \return Flow
  */
FlowImpl::FlowImpl(FlowImpl* flow)
{
	sourceSystem = flow->sourceSystem;
	targetSystem = flow->targetSystem;
	name = flow->name;
}

/**
  * \param id is the flow's name
  * \param source is the System that gonna give energy
  * \param target is the System that gonna recive the energy
  * \return Flow
  */
FlowImpl::FlowImpl(string id, System* source, System* target)
{
	sourceSystem = source;
	targetSystem = target;
	name = id;
}

/**
  * \return
  */
FlowImpl::~FlowImpl()
{
}

/**
  * \param id is the Flow's name
  * \return void
  */
void FlowImpl::setName(string id)
{
	name = id;
}

/**
  * \return string
  */
string FlowImpl::getName()
{
	return name;
}

/**
  * \return System*
  */
System* FlowImpl::getSourceSystem()
{
	return sourceSystem;
}

/**
  * \return System*
  */
System* FlowImpl::getTargetSystem()
{
	return targetSystem;
}

/** \param s is the system that will be connected to the source system
  * \return void
  *
  **/
void FlowImpl:: setSourceSystem(System* s)
{
	sourceSystem = s;
}

/** \param s is the system that will be connected to the target system
  * \return void
  *
  **/
void FlowImpl::setTargetSystem(System* s)
{
	targetSystem = s;
}

/**
  * \param flow is a flow that gonna be copied
  * \return Flow&
  */
FlowImpl& FlowImpl::operator= (const FlowImpl& flow)
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
bool FlowImpl::operator== (const FlowImpl& flow)
{
	if (name == flow.name && sourceSystem == flow.sourceSystem && targetSystem == flow.targetSystem)
		return true;

	return false;
}