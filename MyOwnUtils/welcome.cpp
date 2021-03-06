#include <iomanip>
#include <iostream>

#include "welcome.h"
#include <windows.h>

ClearScreen clearScr;

Welcome::Welcome()
:Adress03	{ "8052 Zuerich" }
,Adress01	{ "MAX KELLER AG" }
,secondLine	{ "Ventilation-System" }
,telefon	{ "TEL. 044/ 302 44 06" }
,Adress02	{ "Schaffhauserstrasse 466" }
,thirdLine	{ "Created by_   Johnybace" }
,firstLine	{ "A simply tool to calculate Airvolume in" }
{
}

void Welcome::welcomeOnScreen()
{
	std::cout	<< std::endl << std::setw(65) << std::right << firstLine << std::endl
				<< std::setw(55) << secondLine << std::endl
				<< std::setw(57) << thirdLine << std::endl << std::endl
				<< std::setw(49) << Adress01 << std::endl
				<< std::setw(59) << Adress02 << std::endl
				<< std::setw(48) << Adress03 << std::endl
				<< std::setw(55) << telefon << std::endl << std::endl;
}
Welcome::~Welcome()
{
}

AirVolMenu::AirVolMenu()
:zero				{ "[ 0]" }
,first				{ "[ 1]" }
,second				{ "[ 2]" }
,third				{ "[ 3]" }
,fourth				{ "[ 4]" }
,fifth				{ "[ 5]" }
,sixth				{ "[ 6]" }
,seventh			{ "[ 7]" }
,eight				{ "[ 8]" }
,ninenth			{ "[ 9]" }
,tenth				{ "[10]" }
,eleventh			{ "[11]" }
,twelveth			{ "[12]" }
,thirteenth			{ "[13]" }
,fourteenth			{ "[14]" }
,fifteenth			{ "[15]" }
,sixteenth			{ "[16]" }
,seventeenth		{ "[17]" }
,eightteenth		{ "[18]" }
,nineteenth			{ "[19]" }
,twentieth			{ "[20]" }
,exit				{ "Exit" }
,notUsed			{ "empty" }
,printLastEntries	{ "Print last Entries" }
,VAV				{ "VAV-Protocol" }
,tubecalc			{ "Pipe-Protocol" }
,functionChoosing	{ "Choose Funktion" }
,rectanglecalc		{ "Duct-Protocol" }
,ventilatorPr		{ "Airvolume by Differential Pressure" }
,averageTube		{ "Average Speed in Tube" }
,averageRect		{ "Average Speed in Duct" }
,tictactoe			{ "Tic Tac Toe" }
{
}

void AirVolMenu::menuOnScreen()
{
	std::cout << std::endl << std::setw(18) << functionChoosing << std::endl << std::endl
	<< std::setw(8) << first << std::setw(15) << tubecalc
	<< std::setw(32) << eleventh << std::setw(7) << notUsed << std::endl
	<< std::setw(8) << second << std::setw(15) << rectanglecalc
	<< std::setw(32) << twelveth << std::setw(7) << notUsed << std::endl
	<< std::setw(8) << third << std::setw(14) << VAV
	<< std::setw(33) << thirteenth << std::setw(7) << notUsed << std::endl
	<< std::setw(8) << fourth << std::setw(23) << averageTube
	<< std::setw(24) << fourteenth << std::setw(7) << notUsed << std::endl
	<< std::setw(8) << fifth << std::setw(23) << averageRect
	<< std::setw(24) << fifteenth << std::setw(7) << notUsed << std::endl
	<< std::setw(8) << sixth << std::setw(36) << ventilatorPr
	<< std::setw(11) << sixteenth << std::setw(7) << notUsed << std::endl
	<< std::setw(8) << seventh << std::setw(20) << printLastEntries
	<< std::setw(27) << seventeenth << std::setw(7) << notUsed << std::endl
	<< std::setw(8) << eight << std::setw(7) << notUsed
	<< std::setw(40) << eightteenth << std::setw(7) << notUsed << std::endl
	<< std::setw(8) << ninenth << std::setw(7) << notUsed
	<< std::setw(40) << nineteenth << std::setw(7) << notUsed << std::endl
	<< std::setw(8) << tenth << std::setw(7) << notUsed
	<< std::setw(40) << twentieth << std::setw(13) << tictactoe << std::endl << std::endl
	<< std::setw(8) << zero << std::setw(6) << exit << std::endl << std::endl;
}
AirVolMenu::~AirVolMenu()
{
}

ClearScreen::ClearScreen()
{
}

void ClearScreen::clearTheScreen()
{
	system("cls");
}
ClearScreen::~ClearScreen()
{
}

Goodbey::Goodbey()
:goodbey01{ "************************************************" } 
,goodbey02{ "******************  Goodbey!  ******************" }
,goodbey03{ "************************************************" }
{
}

void Goodbey::goodBeyScreen()
{
	clearScr.clearTheScreen();
	std::cout << std::endl << std::endl << std::endl << std::endl << std::setw(71) << goodbey01 << std::endl;
	Sleep(250);
	std::cout << std::setw(71) << goodbey02 << std::endl;
	Sleep(250);
	std::cout << std::setw(71) << goodbey03 << std::endl;
	Sleep(1000);
	system("cls");
}

Goodbey::~Goodbey()
{
}