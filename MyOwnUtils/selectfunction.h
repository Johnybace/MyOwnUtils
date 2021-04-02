#ifndef SELECTFUNCTION_H
#define SELECTFUNCTION_H

#include <string>

class SelectFunction
{
private:
	char loop	 { ' ' }
		 ,equal  { '=' }
		 ,doloop { 'n' };

	double dumyForTubeAva{}, dumyForTubeAvb{};

	std::string dumyForWhat{};

	const std::string insertFunction			{ "Please choose your Function:" }
					  ,warning					{ "WARNING!!!! No Valid Entry!" }
					  ,printIinsertProjectName	{ "Please give a Project-Name: " }
					  ,printProject				{ "Project:               "}
					  ,printPipes				{ "Pipe-Averages" }
					  ,printDucts				{ "Duct-Averages" };

protected:
public:
	int Form{};

	void selectfunction();

	SelectFunction();
	~SelectFunction();
};	
#endif
