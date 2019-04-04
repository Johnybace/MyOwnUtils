#include <algorithm>
#include <iomanip>
#include <iostream>
#include <sstream>

#include "welcome.h"
#include "ticTacToe.h"

#include "cinclearbuffer.cpp"

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

void TicTacToe::startGame(char &)
{
	ClearScreen();
	Welcome();
	std::cout << std::endl << std::endl;
	std::cout << std::setw(width)<< "1st Player \'X\'" << std::endl;
	std::cout << std::setw(width)<< "2nd Player \'O\'" << std::endl;
	this->gameFieldToString();
	std::cout << std::setw(10) << "Player " << playerOnMove << " Select Field: ";
	if( player == 2) this->computerLogic(player);
	if( player == 1)
	{
		field = readValue<int>();
		if( field == 1 ) this->setField01( TicTacToe::player, TicTacToe::field01 );
		if( field == 2 ) this->setField02( TicTacToe::player, TicTacToe::field02 );
		if( field == 3 ) this->setField03( TicTacToe::player, TicTacToe::field03 );
		if( field == 4 ) this->setField04( TicTacToe::player, TicTacToe::field04 );
		if( field == 5 ) this->setField05( TicTacToe::player, TicTacToe::field05 );
		if( field == 6 ) this->setField06( TicTacToe::player, TicTacToe::field06 );
		if( field == 7 ) this->setField07( TicTacToe::player, TicTacToe::field07 );
		if( field == 8 ) this->setField08( TicTacToe::player, TicTacToe::field08 );
		if( field == 9 ) this->setField09( TicTacToe::player, TicTacToe::field09 );
	}
}

void TicTacToe::computerLogic(int&  )
{
	++counter;
	
	////////// 1-2-3 mit O //////////////////
	if( playerFieldLine11[ 2] == 'O' && playerFieldLine11[10] == 'O' && field03 == true )
	{
		this->setField03( TicTacToe::player, TicTacToe::field03 );
		return;
	}
	if( playerFieldLine11[ 2] == 'O' && playerFieldLine11[18] == 'O' && field02 == true )
	{
		this->setField02( TicTacToe::player, TicTacToe::field02 );
		return;
	}
	if( playerFieldLine11[10] == 'O' && playerFieldLine11[18] == 'O' && field01 == true )
	{
		this->setField01( TicTacToe::player, TicTacToe::field01 );
		return;
	}
	////////// 4-5-6 mit O //////////////////
	if( playerFieldLine06[ 2] == 'O' && playerFieldLine06[10] == 'O' && field06 == true )
	{
		this->setField06( TicTacToe::player, TicTacToe::field06 );
		return;
	}
	if( playerFieldLine06[ 2] == 'O' && playerFieldLine06[18] == 'O' && field05 == true )
	{
		this->setField05( TicTacToe::player, TicTacToe::field04 );
		return;
	}
	if( playerFieldLine06[10] == 'O' && playerFieldLine06[18] == 'O' && field04 == true )
	{
		this->setField04( TicTacToe::player, TicTacToe::field07 );
		return;
	}
	//////////  7-8-9 mit O ////////////////
	if( playerFieldLine01[ 2] == 'O' && playerFieldLine01[10] == 'O' && field09 == true )
	{
		this->setField09( TicTacToe::player, TicTacToe::field09 );
		return;
	}
	if( playerFieldLine01[ 2] == 'O' && playerFieldLine01[18] == 'O' && field08 == true )
	{
		this->setField08( TicTacToe::player, TicTacToe::field08 );
		return;
	}
	if( playerFieldLine01[10] == 'O' && playerFieldLine01[18] == 'O' && field07 == true )
	{
		this->setField07( TicTacToe::player, TicTacToe::field08 );
		return;
	}
	////////// 1-4-7 mit O //////////////////
	if( playerFieldLine01[ 2] == 'O' && playerFieldLine06[ 2] == 'O' && field01 == true )
	{
		this->setField01( TicTacToe::player, TicTacToe::field01 );
		return;
	}
	if( playerFieldLine01[ 2] == 'O' && playerFieldLine11[ 2] == 'O' && field04 == true )
	{
		this->setField04( TicTacToe::player, TicTacToe::field04 );
		return;
	}
	if( playerFieldLine06[ 2] == 'O' && playerFieldLine11[ 2] == 'O' && field07 == true )
	{
		this->setField07( TicTacToe::player, TicTacToe::field07 );
		return;
	}
	////////// 2-5-8 mit O ////////////////
	if( playerFieldLine01[10] == 'O' && playerFieldLine06[10] == 'O' && field02 == true )
	{
		this->setField02( TicTacToe::player, TicTacToe::field02 );
		return;
	}
	if( playerFieldLine01[10] == 'O' && playerFieldLine11[10] == 'O' && field05 == true )
	{
		this->setField05( TicTacToe::player, TicTacToe::field05 );
		return;
	}
	if( playerFieldLine06[10] == 'O' && playerFieldLine11[10] == 'O' && field08 == true )
	{
		this->setField08( TicTacToe::player, TicTacToe::field08 );
		return;
	}
	////////// 3-6-9 mit O ////////////////
	if( playerFieldLine01[18] == 'O' && playerFieldLine06[18] == 'O' && field03 == true )
	{
		this->setField03( TicTacToe::player, TicTacToe::field03 );
		return;
	}
	if( playerFieldLine01[18] == 'O' && playerFieldLine11[18] == 'O' && field06 == true )
	{
		this->setField06( TicTacToe::player, TicTacToe::field06 );
		return;
	}
	if( playerFieldLine06[18] == 'O' && playerFieldLine11[18] == 'O' && field09 == true )
	{
		this->setField09( TicTacToe::player, TicTacToe::field09 );
		return;
	}
	////////// 1-5-9 mit O ////////////////
	if( playerFieldLine06[10] == 'O' && playerFieldLine01[18] == 'O' && field01 == true )
	{
		this->setField01( TicTacToe::player, TicTacToe::field01 );
		return;
	}
	if( playerFieldLine11[ 2] == 'O' && playerFieldLine01[18] == 'O' && field05 == true )
	{
		this->setField05( TicTacToe::player, TicTacToe::field05 );
		return;
	}
	if( playerFieldLine11[ 2] == 'O' && playerFieldLine06[10] == 'O' && field09 == true )
	{
		this->setField09( TicTacToe::player, TicTacToe::field09 );
		return;
	}
	////////// 3-5-7 mit O ////////////////
	if( playerFieldLine01[ 2] == 'O' && playerFieldLine06[10] == 'O' && field03 == true )
	{
		this->setField03( TicTacToe::player, TicTacToe::field03 );
		return;
	}
	if( playerFieldLine01[ 2] == 'O' && playerFieldLine11[18] == 'O' && field05 == true )
	{
		this->setField05( TicTacToe::player, TicTacToe::field05 );
		return;
	}
	if( playerFieldLine06[10] == 'O' && playerFieldLine11[18] == 'O' && field07 == true )
	{
		this->setField07( TicTacToe::player, TicTacToe::field07 );
		return;
	}
	////////// 1-2-3 mit X //////////////////
	if( playerFieldLine11[ 1] == 'X' && playerFieldLine11[ 9] == 'X' && field03 == true )
	{
		this->setField03( TicTacToe::player, TicTacToe::field03 );
		return;
	}
	if( playerFieldLine11[ 1] == 'X' && playerFieldLine11[17] == 'X' && field02 == true )
	{
		this->setField02( TicTacToe::player, TicTacToe::field02 );
		return;
	}
	if( playerFieldLine11[ 9] == 'X' && playerFieldLine11[17] == 'X' && field01 == true )
	{
		this->setField01( TicTacToe::player, TicTacToe::field01 );
		return;
	}
	////////// 4-5-6 mit X //////////////////
	if( playerFieldLine06[ 1] == 'X' && playerFieldLine06[ 9] == 'X' && field06 == true )
	{
		this->setField06( TicTacToe::player, TicTacToe::field06 );
		return;
	}
	if( playerFieldLine06[ 1] == 'X' && playerFieldLine06[17] == 'X' && field05 == true )
	{
		this->setField05( TicTacToe::player, TicTacToe::field04 );
		return;
	}
	if( playerFieldLine06[ 9] == 'X' && playerFieldLine06[17] == 'X' && field04 == true )
	{
		this->setField04( TicTacToe::player, TicTacToe::field07 );
		return;
	}
	//////////  7-8-9 mit X ////////////////
	if( playerFieldLine01[ 1] == 'X' && playerFieldLine01[ 9] == 'X' && field09 == true )
	{
		this->setField09( TicTacToe::player, TicTacToe::field09 );
		return;
	}
	if( playerFieldLine01[ 1] == 'X' && playerFieldLine01[17] == 'X' && field08 == true )
	{
		this->setField08( TicTacToe::player, TicTacToe::field08 );
		return;
	}
	if( playerFieldLine01[ 9] == 'X' && playerFieldLine01[17] == 'X' && field07 == true )
	{
		this->setField07( TicTacToe::player, TicTacToe::field08 );
		return;
	}
	////////// 1-4-7 mit X //////////////////
	if( playerFieldLine01[ 1] == 'X' && playerFieldLine06[ 1] == 'X' && field01 == true )
	{
		this->setField01( TicTacToe::player, TicTacToe::field01 );
		return;
	}
	if( playerFieldLine01[ 1] == 'X' && playerFieldLine11[ 1] == 'X' && field04 == true )
	{
		this->setField04( TicTacToe::player, TicTacToe::field04 );
		return;
	}
	if( playerFieldLine06[ 1] == 'X' && playerFieldLine11[ 1] == 'X' && field07 == true )
	{
		this->setField07( TicTacToe::player, TicTacToe::field07 );
		return;
	}
	////////// 2-5-8 mit X ////////////////
	if( playerFieldLine01[ 9] == 'X' && playerFieldLine06[ 9] == 'X' && field02 == true )
	{
		this->setField02( TicTacToe::player, TicTacToe::field02 );
		return;
	}
	if( playerFieldLine01[ 9] == 'X' && playerFieldLine11[ 9] == 'X' && field05 == true )
	{
		this->setField05( TicTacToe::player, TicTacToe::field05 );
		return;
	}
	if( playerFieldLine06[ 9] == 'X' && playerFieldLine11[ 9] == 'X' && field08 == true )
	{
		this->setField08( TicTacToe::player, TicTacToe::field08 );
		return;
	}
	////////// 3-6-9 mit X ////////////////
	if( playerFieldLine01[17] == 'X' && playerFieldLine06[17] == 'X' && field03 == true )
	{
		this->setField03( TicTacToe::player, TicTacToe::field03 );
		return;
	}
	if( playerFieldLine01[17] == 'X' && playerFieldLine11[17] == 'X' && field06 == true )
	{
		this->setField06( TicTacToe::player, TicTacToe::field06 );
		return;
	}
	if( playerFieldLine06[17] == 'X' && playerFieldLine11[17] == 'X' && field09 == true )
	{
		this->setField09( TicTacToe::player, TicTacToe::field09 );
		return;
	}
	////////// 1-5-9 mit X ////////////////
	if( playerFieldLine06[ 9] == 'X' && playerFieldLine01[17] == 'X' && field01 == true )
	{
		this->setField01( TicTacToe::player, TicTacToe::field01 );
		return;
	}
	if( playerFieldLine11[ 1] == 'X' && playerFieldLine01[17] == 'X' && field05 == true )
	{
		this->setField05( TicTacToe::player, TicTacToe::field05 );
		return;
	}
	if( playerFieldLine11[ 1] == 'X' && playerFieldLine06[ 9] == 'X' && field09 == true )
	{
		this->setField09( TicTacToe::player, TicTacToe::field09 );
		return;
	}
	////////// 3-5-7 mit X ////////////////
	if( playerFieldLine01[ 1] == 'X' && playerFieldLine06[ 9] == 'X' && field03 == true )
	{
		this->setField03( TicTacToe::player, TicTacToe::field03 );
		return;
	}
	if( playerFieldLine01[ 1] == 'X' && playerFieldLine11[17] == 'X' && field05 == true )
	{
		this->setField05( TicTacToe::player, TicTacToe::field05 );
		return;
	}
	if( playerFieldLine06[ 9] == 'X' && playerFieldLine11[17] == 'X' && field07 == true )
	{
		this->setField07( TicTacToe::player, TicTacToe::field07 );
		return;
	}
	////////////////////////////////
	if( field05 == true )
	{
		this->setField05( TicTacToe::player, TicTacToe::field05 );
		return;
	}
	if ( counter == 2)
	{
		if( field06 == false && field01 == false )
		{
			this->setField03( TicTacToe::player, TicTacToe::field03 );
			return;
		}
		if( field06 == false && field07 == false )
		{
			this->setField09( TicTacToe::player, TicTacToe::field09 );
			return;
		}
		if( field02 == false && field07 == false )
		{
			this->setField01( TicTacToe::player, TicTacToe::field01 );
			return;
		}
		if( field02 == false && field09 == false )
		{
			this->setField03( TicTacToe::player, TicTacToe::field03 );
			return;
		}
		if( field04 == false && field03 == false )
		{
			this->setField01( TicTacToe::player, TicTacToe::field01 );
			return;
		}
		if( field04 == false && field09 == false )
		{
			this->setField07( TicTacToe::player, TicTacToe::field07 );
			return;
		}
		if( field08 == false && field01 == false )
		{
			this->setField07( TicTacToe::player, TicTacToe::field07 );
			return;
		}
		if( field08 == false && field03 == false )
		{
			this->setField09( TicTacToe::player, TicTacToe::field09 );
			return;
		}
		if ( playerFieldLine06[ 9] == 'X' && field09 == false && field07 == true )
		{
		this->setField07( TicTacToe::player, TicTacToe::field07 );
		return;
		}
	}
	if( field07 == false && field08 == true )
	{
		this->setField08( TicTacToe::player, TicTacToe::field08 );
		return;
	}
	if( field09 == false && field06 == true )
	{
		this->setField06( TicTacToe::player, TicTacToe::field06 );
		return;
	}
	if( field03 == false && field02 == true )
	{
		this->setField02( TicTacToe::player, TicTacToe::field02 );
		return;
	}
	if( field01 == false && field07 == true )
	{
		this->setField07( TicTacToe::player, TicTacToe::field07 );
		return;
	}
	if( field07 == false && field09 == true	)
	{
		this->setField09( TicTacToe::player, TicTacToe::field09 );
		return;
	}
	if( field09 == false && field03 == true	)
	{
		this->setField03( TicTacToe::player, TicTacToe::field03 );
		return;
	}
	if( field03 == false && field01 == true	)
	{
		this->setField01( TicTacToe::player, TicTacToe::field01 );
		return;
	}
	if( field08 == false && field03 == false && field09 == true && counter <=3 )
	{
		this->setField09( TicTacToe::player, TicTacToe::field09 );
		return;
	}
	if( field08 == false && field01 == false && field07 == true && counter <=4 )
	{
		this->setField07( TicTacToe::player, TicTacToe::field07 );
		return;
	}
	if( field06 == false && field01 == false && field02 == true && counter <=5 )
	{
		this->setField02( TicTacToe::player, TicTacToe::field02 );
		return;
	}
	if( field06 == false && field07 == false && field09 == true && counter <=4 )
	{
		this->setField09( TicTacToe::player, TicTacToe::field09 );
		return;
	}
	if( field02 == false && field07 == false && field01 == true && counter <=4 )
	{
		this->setField01( TicTacToe::player, TicTacToe::field01 );
		return;
	}
	if( field02 == false && field09 == false && field03 == true && counter <=4 )
	{
		this->setField03( TicTacToe::player, TicTacToe::field03 );
		return;
	}
	if( field04 == false && field03 == false && field01 == true && counter <=4 )
	{
		this->setField01( TicTacToe::player, TicTacToe::field01 );
		return;
	}
	if( field04 == false && field09 == false && field07 == true && counter <=4 )
	{
		this->setField07( TicTacToe::player, TicTacToe::field07 );
		return;
	}
	if ( field01 == true )
	{
		this->setField01( TicTacToe::player, TicTacToe::field01 );
		return;
	}
	if ( field02 == true )
	{
		this->setField02( TicTacToe::player, TicTacToe::field02 );
		return;
	}
	if ( field03 == true )
	{
		this->setField03( TicTacToe::player, TicTacToe::field03 );
		return;
	}
	if ( field04 == true )
	{
		this->setField04( TicTacToe::player, TicTacToe::field04 );
		return;
	}
	if ( field05 == true )
	{
		this->setField05( TicTacToe::player, TicTacToe::field05 );
		return;
	}
	if ( field06 == true )
	{
		this->setField06( TicTacToe::player, TicTacToe::field06 );
		return;
	}
	if ( field08 == true )
	{
		this->setField08( TicTacToe::player, TicTacToe::field08 );
		return;
	}
	if ( field09 == true )
	{
		this->setField09( TicTacToe::player, TicTacToe::field09 );
		return;
	}
}

void TicTacToe::setField01( int&, bool& )
{
	if( player == 1 && field01 == true )
	{
		this->playerFieldLine11.replace(1, 5, playerXline01);
		this->playerFieldLine12.replace(1, 5, playerXline02);
		this->playerFieldLine13.replace(1, 5, playerXline03);
		this->playerFieldLine14.replace(1, 5, playerXline02);
		this->playerFieldLine15.replace(1, 5, playerXline01);
	}
	if( player == 2 && field01 == true )
	{
		this->playerFieldLine11.replace(1, 5, playerOline01);
		this->playerFieldLine12.replace(1, 5, playerOline02);
		this->playerFieldLine13.replace(1, 5, playerOline02);
		this->playerFieldLine14.replace(1, 5, playerOline02);
		this->playerFieldLine15.replace(1, 5, playerOline01);
	}
	if( field01 == false )
	{
		std::cout << std::endl << std::setw(width02) << "Field already in use! Try again!   Press Enter   ";
		std::cin.get();
		return;
	}
	this->field01 = false;
	this->checkForWi();
}

void TicTacToe::setField02( int&, bool& )
{
	if( player == 1 && field02 == true )
	{
		this->playerFieldLine11.replace(9, 5, playerXline01);
		this->playerFieldLine12.replace(9, 5, playerXline02);
		this->playerFieldLine13.replace(9, 5, playerXline03);
		this->playerFieldLine14.replace(9, 5, playerXline02);
		this->playerFieldLine15.replace(9, 5, playerXline01);
	}
	if( player == 2 && field02 == true )
	{
		this->playerFieldLine11.replace(9, 5, playerOline01);
		this->playerFieldLine12.replace(9, 5, playerOline02);
		this->playerFieldLine13.replace(9, 5, playerOline02);
		this->playerFieldLine14.replace(9, 5, playerOline02);
		this->playerFieldLine15.replace(9, 5, playerOline01);
	}
	if( field02 == false )
	{
		std::cout << std::endl << std::setw(width02) << "Field already in use! Try again!   Press Enter   ";
		std::cin.get();
		return;
	}
	this->field02 = false;
	this->checkForWi();
}

void TicTacToe::setField03( int&, bool& )
{
	if( player == 1 && field03 == true )
	{
		this->playerFieldLine11.replace(17, 5,playerXline01);
		this->playerFieldLine12.replace(17, 5,playerXline02);
		this->playerFieldLine13.replace(17, 5,playerXline03);
		this->playerFieldLine14.replace(17, 5,playerXline02);
		this->playerFieldLine15.replace(17, 5,playerXline01);
	}
	if( player == 2 && field03 == true )
	{
		this->playerFieldLine11.replace(17, 5,playerOline01);
		this->playerFieldLine12.replace(17, 5,playerOline02);
		this->playerFieldLine13.replace(17, 5,playerOline02);
		this->playerFieldLine14.replace(17, 5,playerOline02);
		this->playerFieldLine15.replace(17, 5,playerOline01);
	}
	if( field03 == false )
	{
		std::cout << std::endl << std::setw(width02) << "Field already in use! Try again!   Press Enter   ";
		std::cin.get();
		return;
	}
	this->field03 = false;
	this->checkForWi();
} 

void TicTacToe::setField04( int &, bool& )
{
	if( player == 1 && field04 == true )
	{
		this->playerFieldLine06.replace(1, 5, playerXline01);
		this->playerFieldLine07.replace(1, 5, playerXline02);
		this->playerFieldLine08.replace(1, 5, playerXline03);
		this->playerFieldLine09.replace(1, 5, playerXline02);
		this->playerFieldLine10.replace(1, 5, playerXline01);
	}
	if( player == 2 && field04 == true )
	{
		this->playerFieldLine06.replace(1, 5, playerOline01);
		this->playerFieldLine07.replace(1, 5, playerOline02);
		this->playerFieldLine08.replace(1, 5, playerOline02);
		this->playerFieldLine09.replace(1, 5, playerOline02);
		this->playerFieldLine10.replace(1, 5, playerOline01);
	}
	if( field04 == false )
	{
		std::cout << std::endl << std::setw(width02) << "Field already in use! Try again!   Press Enter   ";
		std::cin.get();
		return;
	}
	this->field04 = false;
	this->checkForWi();
}

void TicTacToe::setField05( int&, bool& )
{
	if( player == 1 && field05 == true )
	{
		this->playerFieldLine06.replace(9, 5, playerXline01);
		this->playerFieldLine07.replace(9, 5, playerXline02);
		this->playerFieldLine08.replace(9, 5, playerXline03);
		this->playerFieldLine09.replace(9, 5, playerXline02);
		this->playerFieldLine10.replace(9, 5, playerXline01);
	}
	if( player == 2 && field05 == true )
	{
		this->playerFieldLine06.replace(9, 5, playerOline01);
		this->playerFieldLine07.replace(9, 5, playerOline02);
		this->playerFieldLine08.replace(9, 5, playerOline02);
		this->playerFieldLine09.replace(9, 5, playerOline02);
		this->playerFieldLine10.replace(9, 5, playerOline01);
	}
	if( field05 == false )
	{
		std::cout << std::endl << std::setw(width02) << "Field already in use! Try again!   Press Enter   ";
		std::cin.get();
		return;
	}
	this->field05 = false;
	this->checkForWi();
}

void TicTacToe::setField06( int&, bool& )
{
	if( player == 1 && field06 == true )
	{
		this->playerFieldLine06.replace(17, 5,playerXline01);
		this->playerFieldLine07.replace(17, 5,playerXline02);
		this->playerFieldLine08.replace(17, 5,playerXline03);
		this->playerFieldLine09.replace(17, 5,playerXline02);
		this->playerFieldLine10.replace(17, 5,playerXline01);
	}
	if( player == 2 && field06 == true )
	{
		this->playerFieldLine06.replace(17, 5,playerOline01);
		this->playerFieldLine07.replace(17, 5,playerOline02);
		this->playerFieldLine08.replace(17, 5,playerOline02);
		this->playerFieldLine09.replace(17, 5,playerOline02);
		this->playerFieldLine10.replace(17, 5,playerOline01);
	}
	if( field06 == false )
	{
		std::cout << std::endl << std::setw(width02) << "Field already in use! Try again!   Press Enter   ";
		std::cin.get();
		return;
	}
	this->field06 = false;
	this->checkForWi();
}

void TicTacToe::setField07( int&, bool& )
{
	if( player == 1 && field07 == true )
	{
		this->playerFieldLine01.replace(1, 5, playerXline01);
		this->playerFieldLine02.replace(1, 5, playerXline02);
		this->playerFieldLine03.replace(1, 5, playerXline03);
		this->playerFieldLine04.replace(1, 5, playerXline02);
		this->playerFieldLine05.replace(1, 5, playerXline01);
	}
	if( player == 2 && field07 == true )
	{
		this->playerFieldLine01.replace(1, 5, playerOline01);
		this->playerFieldLine02.replace(1, 5, playerOline02);
		this->playerFieldLine03.replace(1, 5, playerOline02);
		this->playerFieldLine04.replace(1, 5, playerOline02);
		this->playerFieldLine05.replace(1, 5, playerOline01);
	}
	if( field07 == false )
	{
		std::cout << std::endl << std::setw(width02) << "Field already in use! Try again!   Press Enter   ";
		std::cin.get();
		return;
	}
	this->field07 = false;
	this->checkForWi();
}

void TicTacToe::setField08( int &, bool& )
{
	if( player == 1 && field08 == true )
	{
		this->playerFieldLine01.replace(9, 5, playerXline01);
		this->playerFieldLine02.replace(9, 5, playerXline02);
		this->playerFieldLine03.replace(9, 5, playerXline03);
		this->playerFieldLine04.replace(9, 5, playerXline02);
		this->playerFieldLine05.replace(9, 5, playerXline01);
	}
	if( player == 2 && field08 == true )
	{
		this->playerFieldLine01.replace(9, 5, playerOline01);
		this->playerFieldLine02.replace(9, 5, playerOline02);
		this->playerFieldLine03.replace(9, 5, playerOline02);
		this->playerFieldLine04.replace(9, 5, playerOline02);
		this->playerFieldLine05.replace(9, 5, playerOline01);
	}
	if( field08 == false )
	{
		std::cout << std::endl << std::setw(width02) << "Field already in use! Try again!   Press Enter   ";
		std::cin.get();
		return;
	}
	this->field08 = false;
	this->checkForWi();
}

void TicTacToe::setField09( int&, bool& )
{
	if( player == 1 && field09 == true )
	{
		this->playerFieldLine01.replace(17, 5,playerXline01);
		this->playerFieldLine02.replace(17, 5,playerXline02);
		this->playerFieldLine03.replace(17, 5,playerXline03);
		this->playerFieldLine04.replace(17, 5,playerXline02);
		this->playerFieldLine05.replace(17, 5,playerXline01);
	}
	if( player == 2 && field09 == true )
	{
		this->playerFieldLine01.replace(17, 5,playerOline01);
		this->playerFieldLine02.replace(17, 5,playerOline02);
		this->playerFieldLine03.replace(17, 5,playerOline02);
		this->playerFieldLine04.replace(17, 5,playerOline02);
		this->playerFieldLine05.replace(17, 5,playerOline01);
	}
	if( field09 == false )
	{
		std::cout << std::endl << std::setw(width02) << "Field already in use! Try again!   Press Enter   ";
		std::cin.get();
		return;
	}
	this->field09 = false;
	this->checkForWi();
}

void TicTacToe::checkForWi()
{
	if( ( playerFieldLine01[ 1] == 'X' && playerFieldLine01[ 9] == 'X' && playerFieldLine01[17] == 'X' ) ||
		( playerFieldLine06[ 1] == 'X' && playerFieldLine06[ 9] == 'X' && playerFieldLine06[17] == 'X' ) ||
		( playerFieldLine11[ 1] == 'X' && playerFieldLine11[ 9] == 'X' && playerFieldLine11[17] == 'X' ) ||
		( playerFieldLine01[ 1] == 'X' && playerFieldLine06[ 1] == 'X' && playerFieldLine11[ 1] == 'X' ) ||
		( playerFieldLine01[ 9] == 'X' && playerFieldLine06[ 9] == 'X' && playerFieldLine11[ 9] == 'X' ) ||
		( playerFieldLine01[17] == 'X' && playerFieldLine06[17] == 'X' && playerFieldLine11[17] == 'X' ) ||
		( playerFieldLine01[ 1] == 'X' && playerFieldLine06[ 9] == 'X' && playerFieldLine11[17] == 'X' ) ||
		( playerFieldLine01[17] == 'X' && playerFieldLine06[ 9] == 'X' && playerFieldLine11[ 1] == 'X' ) )
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
	if( ( playerFieldLine01[ 2] == 'O' && playerFieldLine01[10] == 'O' && playerFieldLine01[18] == 'O' ) ||
		( playerFieldLine06[ 2] == 'O' && playerFieldLine06[10] == 'O' && playerFieldLine06[18] == 'O' ) ||
		( playerFieldLine11[ 2] == 'O' && playerFieldLine11[10] == 'O' && playerFieldLine11[18] == 'O' ) ||
		( playerFieldLine01[ 2] == 'O' && playerFieldLine06[ 2] == 'O' && playerFieldLine11[ 2] == 'O' ) ||
		( playerFieldLine01[10] == 'O' && playerFieldLine06[10] == 'O' && playerFieldLine11[10] == 'O' ) ||
		( playerFieldLine01[18] == 'O' && playerFieldLine06[18] == 'O' && playerFieldLine11[18] == 'O' ) ||
		( playerFieldLine01[ 2] == 'O' && playerFieldLine06[10] == 'O' && playerFieldLine11[18] == 'O' ) ||
		( playerFieldLine01[18] == 'O' && playerFieldLine06[10] == 'O' && playerFieldLine11[ 2] == 'O' ) )
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

int TicTacToe::swapPlayer( int& )
{
	switch( player )
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
	ClearScreen();
	Welcome();
	std::cout << std::endl << std::endl << std::endl << std::endl;
	this->gameFieldToString();
	if( winner )
	{
		std::cout << std::setw(46)<< "Player " << playerOnMove << " Wins!" << std::endl << std::endl;
	}
	std::cout << std::setw(51) << "GAME OVER!"<< std::endl;
}

TicTacToe::~TicTacToe()
{
}