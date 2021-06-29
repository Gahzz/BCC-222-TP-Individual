#include "model.h"
Flow::Flow()
{
	sourceSystem = NULL;
	targetSystem = NULL;
	name[0] = '\0';
}

Flow::Flow(string id, System* source, System* target)
{
	sourceSystem = source;
	targetSystem = target;
	name = id;
}

Flow::~Flow()
{
}

void Flow::setName(string id)
{
	name = id;
}

string Flow::getName()
{
	return name;
}

System* Flow::getSourceSystem()
{
	return sourceSystem;
}

System* Flow::getTargetSystem()
{
	return targetSystem;
}

void Flow:: setSourceSystem(System* s)
{
	sourceSystem = s;
}

void Flow::setTargetSystem(System* s)
{
	targetSystem = s;
}


Flow& Flow::operator= (const Flow& flow)
{
	if (this == &flow)
		return *this;

	name = flow.name;

	sourceSystem = flow.sourceSystem;
	targetSystem = flow.targetSystem;

	return *this;
}

bool Flow::operator== (const Flow& flow)
{
	if (name == flow.name && sourceSystem == flow.sourceSystem && targetSystem == flow.targetSystem)
		return true;

	return false;
}