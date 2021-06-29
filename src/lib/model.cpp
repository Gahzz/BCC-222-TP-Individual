#include "model.h"

Model::Model()
{
	name = "";
}

Model::Model(string name2)
{
	name = name2;
}

Model::Model(Model* model)
{
	flows = model->flows;
	systems = model->systems;
}

Model::~Model()
{
}

string Model::getName()
{
	return name;
}

void Model::setName(string name2)
{
	name = name2;
}


bool Model::add(Flow* flow)
{
	flows.push_back(flow);
	return true;
}

bool Model::add(System* system)
{
	systems.push_back(system);
	return true;
}

bool Model::remove(Flow* flow)
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

	return false; // the flow didn't exist
}

bool Model::remove(System* system)
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

	return false; // the system didn't exist 
}

void Model::execute(int begin, int end)
{
	
	int size = this->flows.size(); // get a vector size
	double* v = new double[size]; // alocate a float vector

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

}

Model& Model::operator= (const Model& model)
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

bool Model::operator== (const Model& model)
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