#ifndef SELECTFUNCTION_H
#define SELECTFUNCTION_H

#include <string>

class SelectFunction
{
private:
		  char loop	  { ' ' }
			  ,equal  { '=' }
			  ,doloop { 'n' };

	int Form {};

	const std::string insertFunction			{ "Please choose your Function:" }
					 ,warning					{ "WARNING!!!! No Valid Entry!" }
					 ,printIinsertProjectName	{ "Please give a Project-Name: " }
					 ,printProject				{ "Project:               "}
					 ,printPipes				{ "Pipe-Averages" }
					 ,printDucts				{ "Duct-Averages" };

protected:

public:
	SelectFunction();
	~SelectFunction();
};
#endif
