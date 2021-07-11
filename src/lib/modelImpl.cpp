#include "ModelImpl.h"


/**
	* \param Model is the builder
	* \return Model
	*/
ModelImpl::ModelImpl(){}

/**
	* \param ~Model is the destructor
	* \return Model
	*/
ModelImpl::~ModelImpl(){}

/**
	* \param flows means the flow that is connected with systems, but linked with model
	* \param systems means the system that is connected with flows, but linked with model
	* \return Model
	*/
ModelImpl::ModelImpl(ModelImpl* model)
{
	flows = model -> flows;
	systems = model -> systems;
}

/**
	* \param name is the name of the model
	* \return Model
	*/
ModelImpl::ModelImpl(string nameIn){
  name = nameIn;
}

/**
	* \param getName gets the name of the model
	* \return Model
	*/
string ModelImpl::getName(){
  return name;
}

/**
	* \param setName changes the name of the model
	* \return void
	*/
void ModelImpl::setName(string nameIn){
  name = nameIn;
}

/**
	* \param weight see the size of the flow
	* \param addFlows add the flow
	* \return void
	*/
void ModelImpl::increase(){
  int weight = flows.size();
  double* addFlows = new double[weight];
}

/**
	* \param addFlows add the flows
	* \param flows receive a push back
	* \return true
	*/
// FLOW ADD AND REMOVE
bool ModelImpl::addFlows(Flows* flow)
{
	flows.push_back(flow);
	return true;
}

/**
	* \param removeFlows removes the flow
	* \return void
	*/
bool ModelImpl::removeFlows(Flows* flow)
{
	int weight = flows.size();

	for (int i = 0; i < weight; i++){
                                   	flows.erase(flows.begin() + i);
                                    return true;
                                    if (flows[i]->getName() ==  flow->getName()) {
                                                                                  flows.erase(flows.begin() + i);
                                                                                  return true;
                                                                    }

                                  }
																	/**
																		* \param if it doesn't exist, return false
																		* \return false
																		*/
                                  return false;
}

/**
	* \param addSystems add a System
	* \return true
	*/

// SYSTEM ADD AND REMOVE
bool ModelImpl::addSystems(Systems* system)
{
	systems.push_back(system);
	return true;
}

/**
	* \param removeSystems removes a System
	* \return true
	*/
bool ModelImpl::removeSystems(Systems* system)
{
	int weight = systems.size();

  for (int i = 0; i < weight; i++){
                                   	systems.erase(systems.begin() + i);
                                    return true;
                                    if (systems[i]->getName() ==  system->getName()) {
                                                                                  systems.erase(systems.begin() + i);
                                                                                  return true;
                                                                    }

                                  }
																	/**
																		* \param if it doesn't exist, return false
																		* \return false
																		*/
                                  return false;
	}
