#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include <iomanip>
#include "flow.h"

/**interface declaration*/
class Model {

public:
	
    /** Get Model Name */
	virtual string getName() = 0;
	/** Change Model name */
	virtual void setName(string) = 0;
	/** Add a Flow to the model */
	/** Model destructor */
	virtual ~Model() {};
	/** Add a Flow to the model */
	virtual bool add(Flow*) = 0;
	/** Add a System to the model */
	virtual bool add(System*) = 0;
	/**Remove a Flow from the model */
	virtual bool remove(Flow*) = 0;
	/**Remove a System from the model */
	virtual bool remove(System*) = 0;
	/**Run the simulation */
	virtual void execute(int, int) = 0;
};


#endif
