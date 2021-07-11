#include "SystemsImpl.h"

/**
	* \return Systems
	*/
SystemsImpl::SystemsImpl()
{
	name = "";
}

/**
	* \param content means what is inside the System
	* \return Systems
	*/
SystemsImpl::SystemsImpl(string nameIn,double content){
  name = nameIn;
  setContent(content);
}

string SystemsImpl::getName(){
  return name;
}
/**
	* \param nameIn means the name of the System
	* \return Systems
	*/
void SystemsImpl::setName(string nameIn){
  name = nameIn;
}

/**
	* \param getContent gets the content
	* \param content means what is inside the System
	* \return content
	*/
double SystemsImpl::getContent(){
  return content;
}


	/**
		* \param setContent changes the content
		* \return void
		*/
void SystemsImpl::setContent(double contentIn){
  content = contentIn;
}

/**
	* \param increase the value on the System
	* \return void
	*/
//INCREASE THE VALUE
void SystemsImpl::increase(double increase){
  content += increase;
}

/**
	* \param decrease the value on the System
	* \return void
	*/
//DECREASE THE VALUE
void SystemsImpl::decrease(double decrease){
  content -= decrease;
}
