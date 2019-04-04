#ifndef WELCOME_H
#define WELCOME_H

#include <string>

class Welcome
{
private:
	std::string Adress03    { "8052 Zuerich" }
				,Adress01   { "Max Keller AG" }
				,secondLine { "Ventilation-System" }
				,telefon    { "Tel: 044/ 302 06 28" }
				,Adress02   { "Schaffhauserstrasse 466" }
				,thirdLine  { "Created by_   Johnybace" }
				,firstLine  { "A simply tool to calculate Airvolume in" };

public:
	Welcome();
	~Welcome();
};

class AirVolMenu
{
private:
	const std::string zero						{ "[ 0]" }
					 ,first						{ "[ 1]" }
					 ,second					{ "[ 2]" }
					 ,third						{ "[ 3]" }
					 ,fourth					{ "[ 4]" }
					 ,fifth						{ "[ 5]" }
					 ,sixth						{ "[ 6]" }
					 ,seventh					{ "[ 7]" }
					 ,eight						{ "[ 8]" }
					 ,ninenth					{ "[ 9]" }
					 ,tenth						{ "[10]" }
					 ,eleventh					{ "[11]" }
					 ,twelveth					{ "[12]" }
					 ,thirteenth				{ "[13]" }
					 ,fourteenth				{ "[14]" }
					 ,fifteenth					{ "[15]" }
					 ,sixteenth					{ "[16]" }
					 ,seventeenth				{ "[17]" }
					 ,eightteenth				{ "[18]" }
					 ,nineteenth				{ "[19]" }
					 ,twentieth					{ "[20]" }
					 ,exit						{ "Exit" }
					 ,notUsed					{ "empty" }
					 ,printLastEntries			{ "Print last Entries"}
					 ,VAV						{ "VAV-Protocol" }
					 ,tubecalc					{ "Pipe-Protocol" }
					 ,functionChoosing			{ "Choose Funktion" }
					 ,rectanglecalc				{ "Duct-Protocol" }
					 ,ventilatorPr				{ "Airvolume by Differential Pressure"}
					 ,averageTube				{ "Average Speed in Pipe" }
					 ,averageRect				{ "Average Speed in Duct" }
					 ,tictactoe					{ "Tic Tac Toe" };

protected:
public:
	AirVolMenu();
	~AirVolMenu();
};

class ClearScreen
{
public:
	ClearScreen();
	~ClearScreen();
};

class Goodbey
{
private:
	std::string goodbey01  { "************************************************" }
			   ,goodbey02  { "******************  Goodbey!  ******************" }
			   ,goodbey03  { "************************************************" };

public:
	Goodbey();
	~Goodbey();
};
#endif