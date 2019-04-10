#include <iomanip>
#include <iostream>

#include "ticTacToe.h"
#include "welcome.h"

#include "cinclearbuffer.cpp"

TicTacToe::TicTacToe()
:playerOnMove{'X'}, firstPlayerOnScreen{'X'}, secondPlayerOnScreen{'O'}
,width{17}, width01{58}, width02{52}
,player{1}, counter{0}, field{0}
,field01{true}, field02{true}, field03{true}, field04{true}
,field05{true}, field06{true}, field07{true}, field08{true}
,field09{true}, winner{false}, allReadyDone{false}, countSwapPlayer{false}
,playerFieldLine01{ "       |       |       " }
,playerFieldLine02{ "       |       |       " }		
,playerFieldLine03{ "       |       |       " }		
,playerFieldLine04{ "       |       |       " }		
,playerFieldLine05{ "   7   |   8   |   9   " }
,playerFieldLine06{ "       |       |       " }		
,playerFieldLine07{ "       |       |       " }		
,playerFieldLine08{ "       |       |       " }		
,playerFieldLine09{ "       |       |       " }		
,playerFieldLine10{ "   4   |   5   |   6   " }
,playerFieldLine11{ "       |       |       " }
,playerFieldLine12{ "       |       |       " }
,playerFieldLine13{ "       |       |       " }
,playerFieldLine14{ "       |       |       " }
,playerFieldLine15{ "   1   |   2   |   3   " }
,playerFieldSpacer{ "-------|-------|-------" }
,playerXline01{ "X   X" }
,playerXline02{ " X X " }
,playerXline03{ "  X  " }
,playerOline01{ " OOO " }
,playerOline02{ "O   O" }
,fieldInUse{ "Field already in use! Try again!   Press Enter   " }
,modus{}
{
}

void TicTacToe::emptyField() const
{
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
}

void TicTacToe::fieldToScreen() const
{
	ClearScreen();
	Welcome();
	std::cout << std::endl << std::endl;
	std::cout << std::setw(width)<< "1st Player \'" << firstPlayerOnScreen << "\'" << std::endl;
	std::cout << std::setw(width)<< "2nd Player \'" << secondPlayerOnScreen   << "\'" << std::endl;
	std::cout << std::endl << std::endl;
	this->emptyField();
	std::cout << std::endl << std::endl << std::endl;
	if( !winner && ( field01 || field02 || field03 
				||   field04 || field05 || field06 
				||   field07 || field08 || field09  ) )
	{
		std::cout << std::setw(10) << "Player " << playerOnMove << " Select Field: ";
	}
}

int TicTacToe::setModus(int &modus)
{
	do
	{
		ClearScreen();
		Welcome();
		std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
		this->emptyField();
		std::cout << std::endl << std::endl
				  << std::setw(18) << "Modus Selection" << std::endl << std::endl
				  << std::setw( 7)	<< "[1]" << std::setw(44) << "1st Player \'X\' vs 2nd Player Computer \'O\'" << std::endl
				  << std::setw( 7)	<< "[2]" << std::setw(44) << "1st Player Computer \'X\' vs 2nd Player \'O\'" << std::endl
				  << std::setw( 7)	<< "[3]" << std::setw(44) << "1st Player \'O\' vs 2nd Player Computer \'X\'" << std::endl
				  << std::setw( 7)	<< "[4]" << std::setw(44) << "1st Player Computer \'O\' vs 2nd Player \'X\'" << std::endl
				  << std::setw( 7)	<< "[5]" << std::setw(35) << "1st Player \'X\' vs 2nd Player \'O\'" << std::endl
				  << std::setw( 7)	<< "[6]" << std::setw(35) << "1st Player \'O\' vs 2nd Player \'X\'" << std::endl
				  << std::endl
				  << std::setw(17)	<< "Choose Modus: ";
		modus = readValue<int>();
	}while( modus < 1 || modus > 6 );
	return this-> modus;
}

void TicTacToe::startGame( int &modus )
{
	while( !winner &&
		 ( field01 || field02 || field03 ||
		   field04 || field05 || field06 ||
	       field07 || field08 || field09 ))
	{	   
		if( modus == 1 )
		{
			this->realPlayerSelectField();
			if( playerOnMove =='O' && !allReadyDone ) this->computerLogicO( playerOnMove );
			if( playerOnMove =='O' && !allReadyDone ) this->computerLogicX( playerOnMove );
			if( playerOnMove =='O' && !allReadyDone ) this->computerLogic( playerOnMove );
		}
		if( modus == 2 )
		{
			if( playerOnMove =='X' && !allReadyDone ) this->computerLogicX( playerOnMove );
			if( playerOnMove =='X' && !allReadyDone ) this->computerLogicO( playerOnMove );
			if( playerOnMove =='X' && !allReadyDone ) this->computerLogic( playerOnMove );
			this->realPlayerSelectField();
		}
		if( modus == 3 )
		{
			this->firstPlayerOnScreen = 'O';
			this->secondPlayerOnScreen = 'X';
			if( !countSwapPlayer )
			{
				this->swapPlayer( player );
				countSwapPlayer = true; 
			}
			this->realPlayerSelectField();
			if( playerOnMove =='X' && !allReadyDone ) this->computerLogicX( playerOnMove );
			if( playerOnMove =='X' && !allReadyDone ) this->computerLogicO( playerOnMove );
			if( playerOnMove =='X' && !allReadyDone ) this->computerLogic( playerOnMove );
		}
		if( modus == 4 )
		{
			this->firstPlayerOnScreen = 'O';
			this->secondPlayerOnScreen = 'X';
			if( !countSwapPlayer )
			{
				this->swapPlayer( player );
				countSwapPlayer = true; 
			}
			if( playerOnMove =='O' && !allReadyDone ) this->computerLogicO( playerOnMove );
			if( playerOnMove =='O' && !allReadyDone ) this->computerLogicX( playerOnMove );
			if( playerOnMove =='O' && !allReadyDone ) this->computerLogic( playerOnMove );
			this->realPlayerSelectField();
		}
		if( modus == 5 )
		{
			this->realPlayerSelectField();
		}
		if( modus == 6 )
		{
			this->firstPlayerOnScreen = 'O';
			this->secondPlayerOnScreen = 'X';
			if( !countSwapPlayer )
			{
				this->swapPlayer( player );
				countSwapPlayer = true; 
			}
			this->realPlayerSelectField();
		}
	}
	this->gameOver();
}

void TicTacToe::realPlayerSelectField()
{
	while( !allReadyDone )
	{
		this->fieldToScreen();
		field = readValue<int>();
		this->playerSetField( playerOnMove, field );
	}
	allReadyDone = false;
}

void TicTacToe::playerSetField( char &playerOnMove,int &field )
{
	if( field == 1 ) this->setField01( TicTacToe::playerOnMove, TicTacToe::field01 );
	if( field == 2 ) this->setField02( TicTacToe::playerOnMove, TicTacToe::field02 );
	if( field == 3 ) this->setField03( TicTacToe::playerOnMove, TicTacToe::field03 );
	if( field == 4 ) this->setField04( TicTacToe::playerOnMove, TicTacToe::field04 );
	if( field == 5 ) this->setField05( TicTacToe::playerOnMove, TicTacToe::field05 );
	if( field == 6 ) this->setField06( TicTacToe::playerOnMove, TicTacToe::field06 );
	if( field == 7 ) this->setField07( TicTacToe::playerOnMove, TicTacToe::field07 );
	if( field == 8 ) this->setField08( TicTacToe::playerOnMove, TicTacToe::field08 );
	if( field == 9 ) this->setField09( TicTacToe::playerOnMove, TicTacToe::field09 );
}

void TicTacToe::computerLogicX( char &playerOnMove )
{
	////////// 1-2-3 //////////
	if( playerFieldLine11[ 1] == 'X' && playerFieldLine11[ 9] == 'X' && field03 )
	{
		this->setField03( TicTacToe::playerOnMove, TicTacToe::field03 );
		return;
	}
	if( playerFieldLine11[ 1] == 'X' && playerFieldLine11[17] == 'X' && field02 )
	{
		this->setField02( TicTacToe::playerOnMove, TicTacToe::field02 );
		return;
	}
	if( playerFieldLine11[ 9] == 'X' && playerFieldLine11[17] == 'X' && field01 )
	{
		this->setField01( TicTacToe::playerOnMove, TicTacToe::field01 );
		return;
	}
	////////// 4-5-6 //////////
	if( playerFieldLine06[ 1] == 'X' && playerFieldLine06[ 9] == 'X' && field06 )
	{
		this->setField06( TicTacToe::playerOnMove, TicTacToe::field06 );
		return;
	}
	if( playerFieldLine06[ 1] == 'X' && playerFieldLine06[17] == 'X' && field05 )
	{
		this->setField05( TicTacToe::playerOnMove, TicTacToe::field05 );
		return;
	}
	if( playerFieldLine06[ 9] == 'X' && playerFieldLine06[17] == 'X' && field04 )
	{
		this->setField04( TicTacToe::playerOnMove, TicTacToe::field04 );
		return;
	}
	//////////  7-8-9 //////////
	if( playerFieldLine01[ 1] == 'X' && playerFieldLine01[ 9] == 'X' && field09 )
	{
		this->setField09( TicTacToe::playerOnMove, TicTacToe::field09 );
		return;
	}
	if( playerFieldLine01[ 1] == 'X' && playerFieldLine01[17] == 'X' && field08 )
	{
		this->setField08( TicTacToe::playerOnMove, TicTacToe::field08 );
		return;
	}
	if( playerFieldLine01[ 9] == 'X' && playerFieldLine01[17] == 'X' && field07 )
	{
		this->setField07( TicTacToe::playerOnMove, TicTacToe::field07 );
		return;
	}
	////////// 1-4-7 //////////
	if( playerFieldLine01[ 1] == 'X' && playerFieldLine06[ 1] == 'X' && field01 )
	{
		this->setField01( TicTacToe::playerOnMove, TicTacToe::field01 );
		return;
	}
	if( playerFieldLine01[ 1] == 'X' && playerFieldLine11[ 1] == 'X' && field04 )
	{
		this->setField04( TicTacToe::playerOnMove, TicTacToe::field04 );
		return;
	}
	if( playerFieldLine06[ 1] == 'X' && playerFieldLine11[ 1] == 'X' && field07 )
	{
		this->setField07( TicTacToe::playerOnMove, TicTacToe::field07 );
		return;
	}
	////////// 2-5-8 //////////
	if( playerFieldLine01[ 9] == 'X' && playerFieldLine06[ 9] == 'X' && field02 )
	{
		this->setField02( TicTacToe::playerOnMove, TicTacToe::field02 );
		return;
	}
	if( playerFieldLine01[ 9] == 'X' && playerFieldLine11[ 9] == 'X' && field05 )
	{
		this->setField05( TicTacToe::playerOnMove, TicTacToe::field05 );
		return;
	}
	if( playerFieldLine06[ 9] == 'X' && playerFieldLine11[ 9] == 'X' && field08 )
	{
		this->setField08( TicTacToe::playerOnMove, TicTacToe::field08 );
		return;
	}
	////////// 3-6-9 //////////
	if( playerFieldLine01[17] == 'X' && playerFieldLine06[17] == 'X' && field03 )
	{
		this->setField03( TicTacToe::playerOnMove, TicTacToe::field03 );
		return;
	}
	if( playerFieldLine01[17] == 'X' && playerFieldLine11[17] == 'X' && field06 )
	{
		this->setField06( TicTacToe::playerOnMove, TicTacToe::field06 );
		return;
	}
	if( playerFieldLine06[17] == 'X' && playerFieldLine11[17] == 'X' && field09 )
	{
		this->setField09( TicTacToe::playerOnMove, TicTacToe::field09 );
		return;
	}
	////////// 1-5-9 //////////
	if( playerFieldLine06[ 9] == 'X' && playerFieldLine01[17] == 'X' && field01 )
	{
		this->setField01( TicTacToe::playerOnMove, TicTacToe::field01 );
		return;
	}
	if( playerFieldLine11[ 1] == 'X' && playerFieldLine01[17] == 'X' && field05 )
	{
		this->setField05( TicTacToe::playerOnMove, TicTacToe::field05 );
		return;
	}
	if( playerFieldLine11[ 1] == 'X' && playerFieldLine06[ 9] == 'X' && field09 )
	{
		this->setField09( TicTacToe::playerOnMove, TicTacToe::field09 );
		return;
	}
	////////// 3-5-7 //////////
	if( playerFieldLine01[ 1] == 'X' && playerFieldLine06[ 9] == 'X' && field03 )
	{
		this->setField03( TicTacToe::playerOnMove, TicTacToe::field03 );
		return;
	}
	if( playerFieldLine01[ 1] == 'X' && playerFieldLine11[17] == 'X' && field05 )
	{
		this->setField05( TicTacToe::playerOnMove, TicTacToe::field05 );
		return;
	}
	if( playerFieldLine06[ 9] == 'X' && playerFieldLine11[17] == 'X' && field07 )
	{
		this->setField07( TicTacToe::playerOnMove, TicTacToe::field07 );
		return;
	}
}

void TicTacToe::computerLogicO( char &playerOnMove )
{
	////////// 1-2-3 //////////
	if( playerFieldLine11[ 2] == 'O' && playerFieldLine11[10] == 'O' && field03 )
	{
		this->setField03( TicTacToe::playerOnMove, TicTacToe::field03 );
		return;
	}
	if( playerFieldLine11[ 2] == 'O' && playerFieldLine11[18] == 'O' && field02 )
	{
		this->setField02( TicTacToe::playerOnMove, TicTacToe::field02 );
		return;
	}
	if( playerFieldLine11[10] == 'O' && playerFieldLine11[18] == 'O' && field01 )
	{
		this->setField01( TicTacToe::playerOnMove, TicTacToe::field01 );
		return;
	}
	////////// 4-5-6 //////////
	if( playerFieldLine06[ 2] == 'O' && playerFieldLine06[10] == 'O' && field06 )
	{
		this->setField06( TicTacToe::playerOnMove, TicTacToe::field06 );
		return;
	}
	if( playerFieldLine06[ 2] == 'O' && playerFieldLine06[18] == 'O' && field05 )
	{
		this->setField05( TicTacToe::playerOnMove, TicTacToe::field05 );
		return;
	}
	if( playerFieldLine06[10] == 'O' && playerFieldLine06[18] == 'O' && field04 )
	{
		this->setField04( TicTacToe::playerOnMove, TicTacToe::field04 );
		return;
	}
	////////// 7-8-9 //////////
	if( playerFieldLine01[ 2] == 'O' && playerFieldLine01[10] == 'O' && field09 )
	{
		this->setField09( TicTacToe::playerOnMove, TicTacToe::field09 );
		return;
	}
	if( playerFieldLine01[ 2] == 'O' && playerFieldLine01[18] == 'O' && field08 )
	{
		this->setField08( TicTacToe::playerOnMove, TicTacToe::field08 );
		return;
	}
	if( playerFieldLine01[10] == 'O' && playerFieldLine01[18] == 'O' && field07  )
	{
		this->setField07( TicTacToe::playerOnMove, TicTacToe::field07 );
		return;
	}
	////////// 1-4-7 //////////
	if( playerFieldLine01[ 2] == 'O' && playerFieldLine06[ 2] == 'O' && field01 )
	{
		this->setField01( TicTacToe::playerOnMove, TicTacToe::field01 );
		return;
	}
	if( playerFieldLine01[ 2] == 'O' && playerFieldLine11[ 2] == 'O' && field04 )
	{
		this->setField04( TicTacToe::playerOnMove, TicTacToe::field04 );
		return;
	}
	if( playerFieldLine06[ 2] == 'O' && playerFieldLine11[ 2] == 'O' && field07 )
	{
		this->setField07( TicTacToe::playerOnMove, TicTacToe::field07 );
		return;
	}
	////////// 2-5-8 //////////
	if( playerFieldLine01[10] == 'O' && playerFieldLine06[10] == 'O' && field02 )
	{
		this->setField02( TicTacToe::playerOnMove, TicTacToe::field02 );
		return;
	}
	if( playerFieldLine01[10] == 'O' && playerFieldLine11[10] == 'O' && field05 )
	{
		this->setField05( TicTacToe::playerOnMove, TicTacToe::field05 );
		return;
	}
	if( playerFieldLine06[10] == 'O' && playerFieldLine11[10] == 'O' && field08 )
	{
		this->setField08( TicTacToe::playerOnMove, TicTacToe::field08 );
		return;
	}
	////////// 3-6-9 //////////
	if( playerFieldLine01[18] == 'O' && playerFieldLine06[18] == 'O' && field03 )
	{
		this->setField03( TicTacToe::playerOnMove, TicTacToe::field03 );
		return;
	}
	if( playerFieldLine01[18] == 'O' && playerFieldLine11[18] == 'O' && field06 )
	{
		this->setField06( TicTacToe::playerOnMove, TicTacToe::field06 );
		return;
	}
	if( playerFieldLine06[18] == 'O' && playerFieldLine11[18] == 'O' && field09 )
	{
		this->setField09( TicTacToe::playerOnMove, TicTacToe::field09 );
		return;
	}
	////////// 1-5-9 //////////
	if( playerFieldLine06[10] == 'O' && playerFieldLine01[18] == 'O' && field01 )
	{
		this->setField01( TicTacToe::playerOnMove, TicTacToe::field01 );
		return;
	}
	if( playerFieldLine11[ 2] == 'O' && playerFieldLine01[18] == 'O' && field05 )
	{
		this->setField05( TicTacToe::playerOnMove, TicTacToe::field05 );
		return;
	}
	if( playerFieldLine11[ 2] == 'O' && playerFieldLine06[10] == 'O' && field09 )
	{
		this->setField09( TicTacToe::playerOnMove, TicTacToe::field09 );
		return;
	}
	////////// 3-5-7 //////////
	if( playerFieldLine01[ 2] == 'O' && playerFieldLine06[10] == 'O' && field03 )
	{
		this->setField03( TicTacToe::playerOnMove, TicTacToe::field03 );
		return;
	}
	if( playerFieldLine01[ 2] == 'O' && playerFieldLine11[18] == 'O' && field05 )
	{
		this->setField05( TicTacToe::playerOnMove, TicTacToe::field05 );
		return;
	}
	if( playerFieldLine06[10] == 'O' && playerFieldLine11[18] == 'O' && field07 )
	{
		this->setField07( TicTacToe::playerOnMove, TicTacToe::field07 );
		return;
	}
}

void TicTacToe::computerLogic(char & )
{
	if( field05 )
	{
		this->setField05( TicTacToe::playerOnMove, TicTacToe::field05 );
		return;
	}
	if( counter == 2)
	{
		if( !field05 && !field01 && field07 )
		{
			this->setField07( TicTacToe::playerOnMove, TicTacToe::field07 );
			return;
		}
		if( !field05 && !field02 && field09 )
		{
			this->setField09( TicTacToe::playerOnMove, TicTacToe::field09 );
			return;
		}
		if( !field05 && !field03 && field09 )
		{
			this->setField09( TicTacToe::playerOnMove, TicTacToe::field09 );
			return;
		}
		if( !field05 && !field04 && field09 )
		{
			this->setField09( TicTacToe::playerOnMove, TicTacToe::field09 );
			return;
		}
		if( !field05 && !field07 && field01 )
		{
			this->setField01( TicTacToe::playerOnMove, TicTacToe::field01 );
			return;
		}
		if( !field05 && !field09 && field07 )
		{
			this->setField07( TicTacToe::playerOnMove, TicTacToe::field07 );
			return;
		}
	}
	if( counter == 3 )
	{
		if( !field02 && !field07 && field01 )
		{
			this->setField01( TicTacToe::playerOnMove, TicTacToe::field01 );
			return;
		}
		if( playerFieldLine11[ 1] == 'X' && playerFieldLine06[10] == 'O' &&
			playerFieldLine01[17] == 'X' && field02 )
		{
			this->setField02( TicTacToe::playerOnMove, TicTacToe::field02 );
			return;
		}
		if( playerFieldLine11[ 2] == 'O' && playerFieldLine06[ 9] == 'X' &&
			playerFieldLine01[18] == 'O' && field02 )
		{
			this->setField02( TicTacToe::playerOnMove, TicTacToe::field02 );
			return;
		}
		if( !field06 && !field01 && field03 )
		{
			this->setField03( TicTacToe::playerOnMove, TicTacToe::field03 );
			return;
		}
		if( !field06 && !field07 && field09 )
		{
			this->setField09( TicTacToe::playerOnMove, TicTacToe::field09 );
			return;
		}
		if( !field02 && !field09 && field03 )
		{
			this->setField03( TicTacToe::playerOnMove, TicTacToe::field03 );
			return;
		}
		if( !field04 && !field03 && field01 )
		{
			this->setField01( TicTacToe::playerOnMove, TicTacToe::field01 );
			return;
		}
		if( !field04 && !field09 && field07 )
		{
			this->setField07( TicTacToe::playerOnMove, TicTacToe::field07 );
			return;
		}
		if( !field08 && !field01 && field07 )
		{
			this->setField07( TicTacToe::playerOnMove, TicTacToe::field07 );
			return;
		}
		if( !field08 && !field03 && field09 )
		{
			this->setField09( TicTacToe::playerOnMove, TicTacToe::field09 );
			return;
		}
		if( !field08 && !field06 && field09 )
		{
			this->setField09( TicTacToe::playerOnMove, TicTacToe::field09 );
			return;
		}
		if( !field07 && !field03 && field08 )
		{
			this->setField08( TicTacToe::playerOnMove, TicTacToe::field08 );
			return;
		}
	}
	if( counter == 5 )
	{
		if( !field01 && !field05 && !field02 && !field04 && !field09 && field07 )
		{
			this->setField07( TicTacToe::playerOnMove, TicTacToe::field07 );
			return;
		}
	}
	if( !field07 && field08 )
	{
		this->setField08( TicTacToe::playerOnMove, TicTacToe::field08 );
		return;
	}
	if( !field03 && field02 )
	{
		this->setField02( TicTacToe::playerOnMove, TicTacToe::field02 );
		return;
	}
	if( !field07 && field09	)
	{
		this->setField09( TicTacToe::playerOnMove, TicTacToe::field09 );
		return;
	}
	if( !field09 && field03	)
	{
		this->setField03( TicTacToe::playerOnMove, TicTacToe::field03 );
		return;
	}
	if( !field03 && field01 )
	{
		this->setField01( TicTacToe::playerOnMove, TicTacToe::field01 );
		return;
	}
	if( field01 )
	{
		this->setField01( TicTacToe::playerOnMove, TicTacToe::field01 );
		return;
	}
	if( field04 )
	{
		this->setField04( TicTacToe::playerOnMove, TicTacToe::field04 );
		return;
	}
	if( field06 )
	{
		this->setField06( TicTacToe::playerOnMove, TicTacToe::field06 );
		return;
	}
	if( field07 )
	{
		this->setField07( TicTacToe::playerOnMove, TicTacToe::field07 );
		return;
	}
}

void TicTacToe::setField01( char &playerOnMove, bool & )
{
	if( playerOnMove == 'X' && field01 )
	{
		this->playerFieldLine11.replace(1, 5, playerXline01);
		this->playerFieldLine12.replace(1, 5, playerXline02);
		this->playerFieldLine13.replace(1, 5, playerXline03);
		this->playerFieldLine14.replace(1, 5, playerXline02);
		this->playerFieldLine15.replace(1, 5, playerXline01);
	}
	if( playerOnMove == 'O' && field01 )
	{
		this->playerFieldLine11.replace(1, 5, playerOline01);
		this->playerFieldLine12.replace(1, 5, playerOline02);
		this->playerFieldLine13.replace(1, 5, playerOline02);
		this->playerFieldLine14.replace(1, 5, playerOline02);
		this->playerFieldLine15.replace(1, 5, playerOline01);
	}
	if( !field01 )
	{
		std::cout << std::endl << std::setw(width02) << fieldInUse;
		std::cin.get();
		return;
	}
	counter++;
	this->field01 = false;
	allReadyDone = true;
	this->checkForWi();
}

void TicTacToe::setField02( char &playerOnMove, bool & )
{
	if( playerOnMove == 'X' && field02 )
	{
		this->playerFieldLine11.replace(9, 5, playerXline01);
		this->playerFieldLine12.replace(9, 5, playerXline02);
		this->playerFieldLine13.replace(9, 5, playerXline03);
		this->playerFieldLine14.replace(9, 5, playerXline02);
		this->playerFieldLine15.replace(9, 5, playerXline01);
	}
	if( playerOnMove == 'O' && field02 )
	{
		this->playerFieldLine11.replace(9, 5, playerOline01);
		this->playerFieldLine12.replace(9, 5, playerOline02);
		this->playerFieldLine13.replace(9, 5, playerOline02);
		this->playerFieldLine14.replace(9, 5, playerOline02);
		this->playerFieldLine15.replace(9, 5, playerOline01);
	}
	if( !field02 )
	{
		std::cout << std::endl << std::setw(width02) << fieldInUse;
		std::cin.get();
		return;
	}
	counter++;
	this->field02 = false;
	allReadyDone = true;
	this->checkForWi();
}

void TicTacToe::setField03( char &playerOnMove, bool & )
{
	if( playerOnMove == 'X' && field03 )
	{
		this->playerFieldLine11.replace(17, 5,playerXline01);
		this->playerFieldLine12.replace(17, 5,playerXline02);
		this->playerFieldLine13.replace(17, 5,playerXline03);
		this->playerFieldLine14.replace(17, 5,playerXline02);
		this->playerFieldLine15.replace(17, 5,playerXline01);
	}
	if( playerOnMove == 'O' && field03 )
	{
		this->playerFieldLine11.replace(17, 5,playerOline01);
		this->playerFieldLine12.replace(17, 5,playerOline02);
		this->playerFieldLine13.replace(17, 5,playerOline02);
		this->playerFieldLine14.replace(17, 5,playerOline02);
		this->playerFieldLine15.replace(17, 5,playerOline01);
	}
	if( !field03 )
	{
		std::cout << std::endl << std::setw(width02) << fieldInUse;
		std::cin.get();
		return;
	}
	counter++;
	this->field03 = false;
	allReadyDone = true;
	this->checkForWi();
} 

void TicTacToe::setField04( char &playerOnMove, bool & )
{
	if( playerOnMove == 'X' && field04 )
	{
		this->playerFieldLine06.replace(1, 5, playerXline01);
		this->playerFieldLine07.replace(1, 5, playerXline02);
		this->playerFieldLine08.replace(1, 5, playerXline03);
		this->playerFieldLine09.replace(1, 5, playerXline02);
		this->playerFieldLine10.replace(1, 5, playerXline01);
	}
	if( playerOnMove == 'O' && field04 )
	{
		this->playerFieldLine06.replace(1, 5, playerOline01);
		this->playerFieldLine07.replace(1, 5, playerOline02);
		this->playerFieldLine08.replace(1, 5, playerOline02);
		this->playerFieldLine09.replace(1, 5, playerOline02);
		this->playerFieldLine10.replace(1, 5, playerOline01);
	}
	if( !field04 )
	{
		std::cout << std::endl << std::setw(width02) << fieldInUse;
		std::cin.get();
		return;
	}
	counter++;
	this->field04 = false;
	allReadyDone = true;
	this->checkForWi();
}

void TicTacToe::setField05( char &playerOnMove, bool & )
{
	if( playerOnMove == 'X' && field05 )
	{
		this->playerFieldLine06.replace(9, 5, playerXline01);
		this->playerFieldLine07.replace(9, 5, playerXline02);
		this->playerFieldLine08.replace(9, 5, playerXline03);
		this->playerFieldLine09.replace(9, 5, playerXline02);
		this->playerFieldLine10.replace(9, 5, playerXline01);
	}
	if( playerOnMove == 'O' && field05 )
	{
		this->playerFieldLine06.replace(9, 5, playerOline01);
		this->playerFieldLine07.replace(9, 5, playerOline02);
		this->playerFieldLine08.replace(9, 5, playerOline02);
		this->playerFieldLine09.replace(9, 5, playerOline02);
		this->playerFieldLine10.replace(9, 5, playerOline01);
	}
	if( !field05 )
	{
		std::cout << std::endl << std::setw(width02) << fieldInUse;
		std::cin.get();
		return;
	}
	counter++;
	this->field05 = false;
	allReadyDone = true;
	this->checkForWi();
}

void TicTacToe::setField06( char &playerOnMove, bool & )
{
	if( playerOnMove == 'X' && field06 )
	{
		this->playerFieldLine06.replace(17, 5,playerXline01);
		this->playerFieldLine07.replace(17, 5,playerXline02);
		this->playerFieldLine08.replace(17, 5,playerXline03);
		this->playerFieldLine09.replace(17, 5,playerXline02);
		this->playerFieldLine10.replace(17, 5,playerXline01);
	}
	if( playerOnMove == 'O' && field06 )
	{
		this->playerFieldLine06.replace(17, 5,playerOline01);
		this->playerFieldLine07.replace(17, 5,playerOline02);
		this->playerFieldLine08.replace(17, 5,playerOline02);
		this->playerFieldLine09.replace(17, 5,playerOline02);
		this->playerFieldLine10.replace(17, 5,playerOline01);
	}
	if( !field06 )
	{
		std::cout << std::endl << std::setw(width02) << fieldInUse;
		std::cin.get();
		return;
	}
	counter++;
	this->field06 = false;
	allReadyDone = true;
	this->checkForWi();
}

void TicTacToe::setField07( char &playerOnMove, bool & )
{
	if( playerOnMove == 'X' && field07 )
	{
		this->playerFieldLine01.replace(1, 5, playerXline01);
		this->playerFieldLine02.replace(1, 5, playerXline02);
		this->playerFieldLine03.replace(1, 5, playerXline03);
		this->playerFieldLine04.replace(1, 5, playerXline02);
		this->playerFieldLine05.replace(1, 5, playerXline01);
	}
	if( playerOnMove == 'O' && field07 )
	{
		this->playerFieldLine01.replace(1, 5, playerOline01);
		this->playerFieldLine02.replace(1, 5, playerOline02);
		this->playerFieldLine03.replace(1, 5, playerOline02);
		this->playerFieldLine04.replace(1, 5, playerOline02);
		this->playerFieldLine05.replace(1, 5, playerOline01);
	}
	if( !field07 )
	{
		std::cout << std::endl << std::setw(width02) << fieldInUse;
		std::cin.get();
		return;
	}
	counter++;
	this->field07 = false;
	allReadyDone = true;
	this->checkForWi();
}

void TicTacToe::setField08( char &playerOnMove, bool & )
{
	if( playerOnMove == 'X' && field08 )
	{
		this->playerFieldLine01.replace(9, 5, playerXline01);
		this->playerFieldLine02.replace(9, 5, playerXline02);
		this->playerFieldLine03.replace(9, 5, playerXline03);
		this->playerFieldLine04.replace(9, 5, playerXline02);
		this->playerFieldLine05.replace(9, 5, playerXline01);
	}
	if( playerOnMove == 'O' && field08 )
	{
		this->playerFieldLine01.replace(9, 5, playerOline01);
		this->playerFieldLine02.replace(9, 5, playerOline02);
		this->playerFieldLine03.replace(9, 5, playerOline02);
		this->playerFieldLine04.replace(9, 5, playerOline02);
		this->playerFieldLine05.replace(9, 5, playerOline01);
	}
	if( !field08 )
	{
		std::cout << std::endl << std::setw(width02) << fieldInUse;
		std::cin.get();
		return;
	}
	counter++;
	this->field08 = false;
	allReadyDone = true;
	this->checkForWi();
}

void TicTacToe::setField09( char &playerOnMove, bool & )
{
	if( playerOnMove == 'X' && field09 )
	{
		this->playerFieldLine01.replace(17, 5,playerXline01);
		this->playerFieldLine02.replace(17, 5,playerXline02);
		this->playerFieldLine03.replace(17, 5,playerXline03);
		this->playerFieldLine04.replace(17, 5,playerXline02);
		this->playerFieldLine05.replace(17, 5,playerXline01);
	}
	if( playerOnMove == 'O' && field09 )
	{
		this->playerFieldLine01.replace(17, 5,playerOline01);
		this->playerFieldLine02.replace(17, 5,playerOline02);
		this->playerFieldLine03.replace(17, 5,playerOline02);
		this->playerFieldLine04.replace(17, 5,playerOline02);
		this->playerFieldLine05.replace(17, 5,playerOline01);
	}
	if( !field09 )
	{
		std::cout << std::endl << std::setw(width02) << fieldInUse;
		std::cin.get();
		return;
	}
	counter++;
	this->field09 = false;
	allReadyDone = true;
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
	this->swapPlayer( player );
}

int TicTacToe::swapPlayer( int &player )
{
	if( player == 1 )
	{
		player = 2;
		playerOnMove = 'O';
		return playerOnMove;
	}
	if( player == 2 )
	{
		player = 1;
		playerOnMove = 'X';
		return playerOnMove;
	}
	return playerOnMove;
}

void TicTacToe::gameOver() const
{
	this->fieldToScreen();
	if( winner )
	{
		std::cout << std::setw(46)<< "Player " << playerOnMove << " Wins!" << std::endl << std::endl;
	}
	std::cout << std::setw(51) << "GAME OVER!"<< std::endl;
}

TicTacToe::~TicTacToe()
{
}