#ifndef WELCOME_H
#define WELCOME_H

#include <string>

class Welcome
{
private:
	std::string Adress01, Adress02, Adress03, firstLine, secondLine, thirdLine, telefon;

public:
	void welcomeOnScreen();

	Welcome();
	~Welcome();
};

class AirVolMenu
{
private:
	const std::string zero						
					  ,first						
					  ,second					
					  ,third						
					  ,fourth					
					  ,fifth						
					  ,sixth						
					  ,seventh					
					  ,eight						
					  ,ninenth					
					  ,tenth						
					  ,eleventh					
					  ,twelveth					
					  ,thirteenth				
					  ,fourteenth				
					  ,fifteenth					
					  ,sixteenth					
					  ,seventeenth				
					  ,eightteenth				
					  ,nineteenth				
					  ,twentieth					
					  ,exit						
					  ,notUsed					
					  ,printLastEntries
					  ,VAV						
					  ,tubecalc
					  ,functionChoosing			
					  ,rectanglecalc				
					  ,ventilatorPr				
					  ,averageTube				
					  ,averageRect				
					  ,tictactoe;
					 
public:
	void menuOnScreen();

	AirVolMenu();
	~AirVolMenu();
};

class ClearScreen
{
public:
	void clearTheScreen();

	ClearScreen();
	~ClearScreen();
};

class Goodbey
{
private:
	std::string goodbey01, goodbey02, goodbey03;

public:
	void goodBeyScreen();

	Goodbey();
	~Goodbey();
};
#endif