#include "modelImpl.h"

/**
  * \return Model
  */
ModelImpl::ModelImpl()
{
	flows.clear();
	systems.clear();
	name = "";
}

/**
  * \param nameModel is the name of the Model
  * \return Model
  */
ModelImpl::ModelImpl(string nameModel)
{
	name = nameModel;
}

/**
  * \param model is a Model, and the new one gonna be a copy of it
  * \return Model
  */
ModelImpl::ModelImpl(ModelImpl* model)
{
	flows = model->flows;
	systems = model->systems;
}

/**
  * \return 
  */
ModelImpl::~ModelImpl()
{
}

/**
  * \return string
  */
string ModelImpl::getName()
{
	return name;
}

/**
  *\param nameModel is s the name of the Model
  * \return void
  */
void ModelImpl::setName(string nameModel)
{
	name = nameModel;
}

/** \param flow is the Flow that gonna be added to the Model
  * \return bool
  **/
bool ModelImpl::add(Flow* flow)
{
	flows.push_back(flow);
	return true;
}

/** \param system is the System that gonna be added to the Model
  * \return bool
  **/
bool ModelImpl::add(System* system)
{
	systems.push_back(system);
	return true;
}

/** \param flow is the Flow that gonna be removed from Model
  * \return bool
  **/
bool ModelImpl::remove(Flow* flow)
{
	int size = flows.size();

	for (int i = 0; i < size; i++)
	{
		if (flows[i]->getName() == flow->getName())
		{
			flows.erase(flows.begin() + i);
			return true;
		}
	}

	return false; // the Flow doesn't exist
}

/** \param system is the System that gonna be removed from Model
  * \return bool
  **/
bool ModelImpl::remove(System* system)
{
	int size = systems.size();

	for (int i = 0; i < size; i++)
	{
		if (systems[i]->getName() == system->getName())
		{
			systems.erase(systems.begin() + i);
			return true;
		}
	}

	return false; // the System doesn't exist
}


/** \param begin is the begin of the simualtion
  * \param end is the end of the simulation
  * \return void
  *
  **/
void ModelImpl::execute(int begin, int end)
{
	
	int size = this->flows.size(); // get a vector size
	float *v = new float[size]; // alocate a float vector

	for (int i = begin; i < end; i++)
	{
		
		for (int j = 0; j < size; j++)
			v[j] = flows[j]->execute(); // save the results of executes
			

		for (int k = 0; k < size; k++)
		{
			// set the new systens' value
			if (flows[k]->getTargetSystem() != NULL)
				flows[k]->getTargetSystem()->increaseQuantity(v[k]);
			

			if (flows[k]->getSourceSystem() != NULL)
				flows[k]->getSourceSystem()->decreaseQuantity(v[k]);
			
		}
	}

	delete [] v;

}

/**
  * \param model is a Model that gonna be copied
  * \return Model&
  */
ModelImpl& ModelImpl::operator= (const ModelImpl& model)
{
	if (this == &model)
		return *this;


	for (vector<Flow*>::iterator it = flows.begin(); it != this->flows.end(); it++)
		delete* it;

	flows.clear();

	for (vector<System*>::iterator it = this->systems.begin(); it != this->systems.end(); it++)
		delete* it;

	this->systems.clear();


	for (int i = 0, size = model.flows.size(); i < size; i++)
	{

		flows.push_back(model.flows[i]);
	}

	for (int i = 0, size = model.systems.size(); i < size; i++)
	{
		systems.push_back(model.systems[i]);
	}

	
	return *this;
}

/**
  * \param model is a Model that gonna be compared with the Model that call this function
  * \return bool
  */
bool ModelImpl::operator== (const ModelImpl& model)
{
	if (this == &model)
		return true;

	if (flows.size() != model.flows.size() || systems.size() != model.systems.size())
		return false;

	for (int i = 0, size = model.flows.size(); i < size; i++)
		if (!(flows[i] == model.flows[i]))
			return false;

	for (int i = 0, size = model.systems.size(); i < size; i++)
		if (!(systems[i] == model.systems[i]))
			return false;

	return true;
}