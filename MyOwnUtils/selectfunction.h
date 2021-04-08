#ifndef SELECTFUNCTION_H
#define SELECTFUNCTION_H

#include <string>

class SelectFunction
{
private:
	char loop, equal, doloop;

	double dumyForTubeAva, dumyForTubeAvb;

	std::string dumyForWhat;

	const std::string insertFunction, warning, printIinsertProjectName, printProject, printPipes, printDucts;

protected:
public:
	int Form;

	void selectfunction();

	SelectFunction();
	~SelectFunction();
};	
#endif
