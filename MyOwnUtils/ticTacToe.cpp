#include <algorithm>
#include <iomanip>
#include <iostream>
#include <sstream>

#include "welcome.h"
#include "ticTacToe.h"

std::string TicTacToe::gameFieldToString() const
{
	std::stringstream ss;
	std::cout << std::endl << std::endl;
	std::cout << std::setw(width01) << playerFieldLine01 << std::endl;
	std::cout << std::setw(width01) << playerFieldLine02 << std::endl;
	std::cout << std::setw(width01) << playerFieldLine03 << std::endl;
	std::cout << std::setw(width01) << playerFieldLine04 << std::endl;
	std::cout << std::setw(width01) << playerFieldLine05 << std::endl;
	std::cout << std::setw(width01) << playerFieldSpacer << std::endl;
	std::cout << std::setw(width01) << playerFieldLine06 << std::endl;
	std::cout << std::setw(width01) << playerFieldLine07 << std::endl;
	std::cout << std::setw(width01) << playerFieldLine08 << std::endl;
	std::cout << std::setw(width01) << playerFieldLine09 << std::endl;
	std::cout << std::setw(width01) << playerFieldLine10 << std::endl;
	std::cout << std::setw(width01) << playerFieldSpacer << std::endl;
	std::cout << std::setw(width01) << playerFieldLine11 << std::endl;
	std::cout << std::setw(width01) << playerFieldLine12 << std::endl;
	std::cout << std::setw(width01) << playerFieldLine13 << std::endl;
	std::cout << std::setw(width01) << playerFieldLine14 << std::endl;
	std::cout << std::setw(width01) << playerFieldLine15 << std::endl;
	std::cout << std::endl << std::endl << std::endl;
	return ss.str();
}

void TicTacToe::checkForWi( bool &, bool &, bool &, 
							bool &, bool &, bool &, bool &,
							bool &, bool &, bool &, int  &player)
{
	if( (playerFieldLine01[ 1] == 'X' && playerFieldLine01[ 9] == 'X' && playerFieldLine01[17] == 'X') ||
		(playerFieldLine06[ 1] == 'X' && playerFieldLine06[ 9] == 'X' && playerFieldLine06[17] == 'X') ||
		(playerFieldLine11[ 1] == 'X' && playerFieldLine11[ 9] == 'X' && playerFieldLine11[17] == 'X') ||
		(playerFieldLine01[ 1] == 'X' && playerFieldLine06[ 1] == 'X' && playerFieldLine11[ 1] == 'X') ||
		(playerFieldLine01[ 9] == 'X' && playerFieldLine06[ 9] == 'X' && playerFieldLine11[ 9] == 'X') ||
		(playerFieldLine01[17] == 'X' && playerFieldLine06[17] == 'X' && playerFieldLine11[17] == 'X') ||
		(playerFieldLine01[ 1] == 'X' && playerFieldLine06[ 9] == 'X' && playerFieldLine11[17] == 'X') ||
		(playerFieldLine01[17] == 'X' && playerFieldLine06[ 9] == 'X' && playerFieldLine11[ 1] == 'X') )
	{
		field01 = false;
		field02 = false;
		field03 = false;
		field04 = false;
		field05 = false;
		field06 = false;
		field07 = false;
		field08 = false;
		field09 = false;
		winner = true;
		return;
	}
	if( (playerFieldLine01[ 2] == 'O' && playerFieldLine01[10] == 'O' && playerFieldLine01[18] == 'O') ||
		(playerFieldLine06[ 2] == 'O' && playerFieldLine06[10] == 'O' && playerFieldLine06[18] == 'O') ||
		(playerFieldLine11[ 2] == 'O' && playerFieldLine11[10] == 'O' && playerFieldLine11[18] == 'O') ||
		(playerFieldLine01[ 2] == 'O' && playerFieldLine06[ 2] == 'O' && playerFieldLine11[ 2] == 'O') ||
		(playerFieldLine01[10] == 'O' && playerFieldLine06[10] == 'O' && playerFieldLine11[10] == 'O') ||
		(playerFieldLine01[18] == 'O' && playerFieldLine06[18] == 'O' && playerFieldLine11[18] == 'O') ||
		(playerFieldLine01[ 2] == 'O' && playerFieldLine06[10] == 'O' && playerFieldLine11[18] == 'O') ||
		(playerFieldLine01[18] == 'O' && playerFieldLine06[10] == 'O' && playerFieldLine11[ 2] == 'O') )
	{
		field01 = false;
		field02 = false;
		field03 = false;
		field04 = false;
		field05 = false;
		field06 = false;
		field07 = false;
		field08 = false;
		field09 = false;
		winner = true;
		return;
	}
	swapPlayer(player);
}

void TicTacToe::startGame(char &) const
{
	system("cls");
	Welcome();
	std::cout << std::endl << std::endl;
	std::cout << std::setw(width)<< "1st Player \'X\'" << std::endl;
	std::cout << std::setw(width)<< "2nd Player \'O\'" << std::endl;
	this->gameFieldToString();
	std::cout << std::setw(9) << "Player " << playerOnMove << " Select Field: ";
}

void TicTacToe::setField07( int & player, bool& )
{
	if(player == 1 && field07 == true)
	{
		this->playerFieldLine01.replace(1, 5, playerXline01);
		this->playerFieldLine02.replace(1, 5, playerXline02);
		this->playerFieldLine03.replace(1, 5, playerXline03);
		this->playerFieldLine04.replace(1, 5, playerXline02);
		this->playerFieldLine05.replace(1, 5, playerXline01);
		this->field07 = false;
		this->checkForWi( field01, field02, field03, 
						  field04, field05, field06, winner,
						  field07, field08, field09, player );
		return;
	}
	if(player == 2 && field07 == true)
	{
		this->playerFieldLine01.replace(1, 5, playerOline01);
		this->playerFieldLine02.replace(1, 5, playerOline02);
		this->playerFieldLine03.replace(1, 5, playerOline02);
		this->playerFieldLine04.replace(1, 5, playerOline02);
		this->playerFieldLine05.replace(1, 5, playerOline01);
		this->field07 = false;
		this->checkForWi( field01, field02, field03, 
						  field04, field05, field06, winner,
						  field07, field08, field09, player );
		return;
	}
	if(field07 == false)
	{
		std::cout << std::endl << std::setw(width02) << "Field already in use! Try again!   Press any Key ";
		std::cin.ignore();
		std::cin.get();
	}
}

void TicTacToe::setField08( int & player, bool& )
{
	if(player == 1 && field08 == true)
	{
		this->playerFieldLine01.replace(9, 5, playerXline01);
		this->playerFieldLine02.replace(9, 5, playerXline02);
		this->playerFieldLine03.replace(9, 5, playerXline03);
		this->playerFieldLine04.replace(9, 5, playerXline02);
		this->playerFieldLine05.replace(9, 5, playerXline01);
		this->field08 = false;
		this->checkForWi( field01, field02, field03, 
						  field04, field05, field06, winner,
						  field07, field08, field09, player );
		return;
	}
	if(player == 2 && field08 == true)
	{
		this->playerFieldLine01.replace(9, 5, playerOline01);
		this->playerFieldLine02.replace(9, 5, playerOline02);
		this->playerFieldLine03.replace(9, 5, playerOline02);
		this->playerFieldLine04.replace(9, 5, playerOline02);
		this->playerFieldLine05.replace(9, 5, playerOline01);
		this->field08 = false;
		this->checkForWi( field01, field02, field03, 
						  field04, field05, field06, winner,
						  field07, field08, field09, player );
		return;
	}
	if(field08 == false)
	{
		std::cout << std::endl << std::setw(width02) << "Field already in use! Try again!   Press any Key ";
		std::cin.ignore();
		std::cin.get();
	}
}

void TicTacToe::setField09( int & player, bool& )
{
	if(player == 1 && field09 == true)
	{
		this->playerFieldLine02.replace(17, 5,playerXline02);
		this->playerFieldLine03.replace(17, 5,playerXline03);
		this->playerFieldLine04.replace(17, 5,playerXline02);
		this->playerFieldLine05.replace(17, 5,playerXline01);
		this->playerFieldLine01.replace(17, 5,playerXline01);
		this->field09 = false;
		this->checkForWi( field01, field02, field03, 
						  field04, field05, field06, winner,
						  field07, field08, field09, player );
		return;
	}
	if(player == 2 && field09 == true)
	{
		this->playerFieldLine01.replace(17, 5,playerOline01);
		this->playerFieldLine02.replace(17, 5,playerOline02);
		this->playerFieldLine03.replace(17, 5,playerOline02);
		this->playerFieldLine04.replace(17, 5,playerOline02);
		this->playerFieldLine05.replace(17, 5,playerOline01);
		this->field09 = false;
		this->checkForWi( field01, field02, field03, 
						  field04, field05, field06, winner,
						  field07, field08, field09, player );
		return;
	}
	if(field09 == false)
	{
		std::cout << std::endl << std::setw(width02) << "Field already in use! Try again!   Press any Key ";
		std::cin.ignore();
		std::cin.get();
	}
}
	
void TicTacToe::setField04( int & player, bool& )
{
	if(player == 1 && field04 == true)
	{
		this->playerFieldLine06.replace(1, 5, playerXline01);
		this->playerFieldLine07.replace(1, 5, playerXline02);
		this->playerFieldLine08.replace(1, 5, playerXline03);
		this->playerFieldLine09.replace(1, 5, playerXline02);
		this->playerFieldLine10.replace(1, 5, playerXline01);
		this->field04 = false;
		this->checkForWi( field01, field02, field03, 
						  field04, field05, field06, winner,
						  field07, field08, field09, player );
		return;
	}
	if(player == 2 && field04 == true)
	{
		this->playerFieldLine06.replace(1, 5, playerOline01);
		this->playerFieldLine07.replace(1, 5, playerOline02);
		this->playerFieldLine08.replace(1, 5, playerOline02);
		this->playerFieldLine09.replace(1, 5, playerOline02);
		this->playerFieldLine10.replace(1, 5, playerOline01);
		this->field04 = false;
		this->checkForWi( field01, field02, field03, 
						  field04, field05, field06, winner,
						  field07, field08, field09, player );
		return;
	}
	if(field04 == false)
	{
		std::cout << std::endl << std::setw(width02) << "Field already in use! Try again!   Press any Key ";
		std::cin.ignore();
		std::cin.get();
	}
}

void TicTacToe::setField05( int & player, bool & )
{
	if(player == 1 && field05 == true)
	{
		this->playerFieldLine06.replace(9, 5, playerXline01);
		this->playerFieldLine07.replace(9, 5, playerXline02);
		this->playerFieldLine08.replace(9, 5, playerXline03);
		this->playerFieldLine09.replace(9, 5, playerXline02);
		this->playerFieldLine10.replace(9, 5, playerXline01);
		this->field05 = false;
		this->checkForWi( field01, field02, field03,
						  field04, field05, field06, winner,
						  field07, field08, field09, player );
		return;
	}
	if(player == 2 && field05 == true)
	{
		this->playerFieldLine06.replace(9, 5, playerOline01);
		this->playerFieldLine07.replace(9, 5, playerOline02);
		this->playerFieldLine08.replace(9, 5, playerOline02);
		this->playerFieldLine09.replace(9, 5, playerOline02);
		this->playerFieldLine10.replace(9, 5, playerOline01);
		this->field05 = false;
		this->checkForWi( field01, field02, field03, 
						  field04, field05, field06, winner,
						  field07, field08, field09, player );
		return;
	}
	if(field05 == false)
	{
		std::cout << std::endl << std::setw(width02) << "Field already in use! Try again!   Press any Key ";
		std::cin.ignore();
		std::cin.get();
	}
}

void TicTacToe::setField06( int & player, bool & )
{
	if(player == 1 && field06 == true)
	{
		this->playerFieldLine06.replace(17, 5,playerXline01);
		this->playerFieldLine07.replace(17, 5,playerXline02);
		this->playerFieldLine08.replace(17, 5,playerXline03);
		this->playerFieldLine09.replace(17, 5,playerXline02);
		this->playerFieldLine10.replace(17, 5,playerXline01);
		this->field06 = false;
		this->checkForWi( field01, field02, field03, 
						  field04, field05, field06, winner,
						  field07, field08, field09, player );
		return;
	}
	if(player == 2 && field06 == true)
	{
		this->playerFieldLine06.replace(17, 5,playerOline01);
		this->playerFieldLine07.replace(17, 5,playerOline02);
		this->playerFieldLine08.replace(17, 5,playerOline02);
		this->playerFieldLine09.replace(17, 5,playerOline02);
		this->playerFieldLine10.replace(17, 5,playerOline01);
		this->field06 = false;
		this->checkForWi( field01, field02, field03, 
						  field04, field05, field06, winner,
						  field07, field08, field09, player );
		return;
	}
	if(field06 == false)
	{
		std::cout << std::endl << std::setw(width02) << "Field already in use! Try again!   Press any Key ";
		std::cin.ignore();
		std::cin.get();
	}
}

void TicTacToe::setField01( int & player, bool & )
{
	if(player == 1 && field01 == true)
	{
		this->playerFieldLine11.replace(1, 5, playerXline01);
		this->playerFieldLine12.replace(1, 5, playerXline02);
		this->playerFieldLine13.replace(1, 5, playerXline03);
		this->playerFieldLine14.replace(1, 5, playerXline02);
		this->playerFieldLine15.replace(1, 5, playerXline01);
		this->field01 = false;
		this->checkForWi( field01, field02, field03, 
						  field04, field05, field06, winner,
						  field07, field08, field09, player );
		return;
	}
	if(player == 2&& field01 == true)
	{
		this->playerFieldLine11.replace(1, 5, playerOline01);
		this->playerFieldLine12.replace(1, 5, playerOline02);
		this->playerFieldLine13.replace(1, 5, playerOline02);
		this->playerFieldLine14.replace(1, 5, playerOline02);
		this->playerFieldLine15.replace(1, 5, playerOline01);
		this->field01 = false;
		this->checkForWi( field01, field02, field03, 
						  field04, field05, field06, winner,
						  field07, field08, field09, player );
		return;
	}
	if(field01 == false)
	{
		std::cout << std::endl << std::setw(width02) << "Field already in use! Try again!   Press any Key ";
		std::cin.ignore();
		std::cin.get();
	}
}

void TicTacToe::setField02( int & player, bool& )
{
	if(player == 1 && field02 == true)
	{
		this->playerFieldLine11.replace(9, 5, playerXline01);
		this->playerFieldLine12.replace(9, 5, playerXline02);
		this->playerFieldLine13.replace(9, 5, playerXline03);
		this->playerFieldLine14.replace(9, 5, playerXline02);
		this->playerFieldLine15.replace(9, 5, playerXline01);
		this->field02 = false;
		this->checkForWi( field01, field02, field03, 
						  field04, field05, field06, winner,
						  field07, field08, field09, player );
		return;
	}
	if(player == 2 && field02 == true)
	{
		this->playerFieldLine11.replace(9, 5, playerOline01);
		this->playerFieldLine12.replace(9, 5, playerOline02);
		this->playerFieldLine13.replace(9, 5, playerOline02);
		this->playerFieldLine14.replace(9, 5, playerOline02);
		this->playerFieldLine15.replace(9, 5, playerOline01);
		this->field02 = false;
		this->checkForWi( field01, field02, field03, 
						  field04, field05, field06, winner,
						  field07, field08, field09, player );
		return;
	}
	if(field02 == false)
	{
		std::cout << std::endl << std::setw(width02) << "Field already in use! Try again!   Press any Key ";
		std::cin.ignore();
		std::cin.get();
	}
}

void TicTacToe::setField03( int & player, bool & )
{
	if(player == 1 && field03 == true)
	{
		this->playerFieldLine11.replace(17, 5,playerXline01);
		this->playerFieldLine12.replace(17, 5,playerXline02);
		this->playerFieldLine13.replace(17, 5,playerXline03);
		this->playerFieldLine14.replace(17, 5,playerXline02);
		this->playerFieldLine15.replace(17, 5,playerXline01);
		this->field03 = false;
		this->checkForWi( field01, field02, field03, 
						  field04, field05, field06, winner,
						  field07, field08, field09, player );
		return;
	}
	if(player == 2 && field03 == true)
	{
		this->playerFieldLine11.replace(17, 5,playerOline01);
		this->playerFieldLine12.replace(17, 5,playerOline02);
		this->playerFieldLine13.replace(17, 5,playerOline02);
		this->playerFieldLine14.replace(17, 5,playerOline02);
		this->playerFieldLine15.replace(17, 5,playerOline01);
		this->field03 = false;
		this->checkForWi( field01, field02, field03, 
						  field04, field05, field06, winner,
						  field07, field08, field09, player );
		return;
	}
	if(field03 == false)
	{
		std::cout << std::endl << std::setw(width02) << "Field already in use! Try again!   Press any Key ";
		std::cin.ignore();
		std::cin.get();
	}
} 

int TicTacToe::swapPlayer( int & player)
{
	switch(player)
	{
		case 1:
		player = 2;
		playerOnMove = 'O';
		break;

		case 2:
		player = 1;
		playerOnMove = 'X';
		break;
	}
	return playerOnMove;
}

void TicTacToe::gameOver() const
{
	system("cls");
	Welcome();
	std::cout << std::endl << std::endl << std::endl << std::endl;
	this->gameFieldToString();
	if(winner)
	{
		std::cout << std::setw(45)<< "Player " << playerOnMove << " Wins!" << std::endl << std::endl;
	}
	std::cout << std::setw(50) << "GAME OVER!"<< std::endl;
}

TicTacToe::~TicTacToe()
{
}
