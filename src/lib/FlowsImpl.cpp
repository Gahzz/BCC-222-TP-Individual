#include "FlowsImpl.h"
#include "Model.h"


/**
  * \param origin means the origin of the flow
  * \param destiny means the destiny of the flows
  * \param name means the name of the flow
  * \return Flows
  */
FlowsImpl::FlowsImpl(){
  origin = NULL;
  destiny = NULL;
  name[0]= '\0';
}

/**
  * \param originIn means the origin of the flow
  * \param destinyIn means the destiny of the flows
  * \param nameIn means the name of the flow
  * \return Flows
  */
FlowsImpl::FlowsImpl(string nameIn,Systems* originIn,Systems* destinyIn){
  name = nameIn;
  origin = originIn;
  destiny = destinyIn;
}

/**
	* \param Flows is the destructor
	* \return Flows
	*/
FlowsImpl::~FlowsImpl(){}


/**
	* \param getName gets the name of the flow
	* \return name
	*/
string FlowsImpl::getName(){
  return name;
}

/**
	* \param setName changes the name of the flow
	* \return void
	*/
void FlowsImpl::setName(string nameIn){
  name = nameIn;
}

/**
	* \param GetDestiny gets the destiny of the flow
	* \return destiny
	*/
Systems* FlowsImpl::getDestiny(){
  return destiny;
}

/**
	* \param setDestiny changes the destiny of the flow
	* \return void
	*/
void FlowsImpl::setDestiny(Systems *destinyIn){
  destiny = destinyIn;
}

/**
	* \param getOrigin gets the origin of the flow
	* \return origin
	*/
Systems* FlowsImpl::getOrigin(){
  return origin;
}

/**
	* \param setOrigin changes the origin of the flow
	* \return void
	*/
void FlowsImpl::setOrigin(Systems *originIn){
  origin = originIn;
}

/**
	* \param connect means the connection of the flow with his origin to his destiny
	* \return void
	*/
void FlowsImpl::connect(Systems *originIn,Systems *destinyIn){
  origin = originIn;
  destiny = destinyIn;
}
/**
  * \param flow is a flow that gonna be copied
  * \return Flow&
  */
FlowsImpl& FlowsImpl::operator= (const FlowsImpl& flows)
{
	if (this == &flows)
		return *this;

	name = flows.name;

	origin = flows.origin;
  destiny = flows.destiny;

	return *this;
}

/**
  * \param flow is a flow that gonna be compared with the Flow that call this function
  * \return bool
  */
bool FlowsImpl::operator== (const FlowsImpl& flows)
{
	if (name == flows.name && origin == flows.origin && destiny == flows.destiny)
		return true;

	return false;
}
