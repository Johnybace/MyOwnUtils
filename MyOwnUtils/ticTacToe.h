#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <string>

class TicTacToe
{
private:
	char playerOnMove, nextPlayer, firstPlayerOnScreen, secondPlayerOnScreen;

	int  width, width01, width02, player, counter, field, sleeptime;

	bool field01, field02, field03, field04, field05,
		 field06, field07, field08, field09, winner, allReadyDone,
		 countSwapPlayer;

	std::string playerFieldLine01, playerFieldLine02, playerFieldLine03,
				playerFieldLine04, playerFieldLine05, playerFieldLine06,
				playerFieldLine07, playerFieldLine08, playerFieldLine09,
				playerFieldLine10, playerFieldLine11, playerFieldLine12,
				playerFieldLine13, playerFieldLine14, playerFieldLine15,
				playerFieldSpacer,
				playerXline01, playerXline02, playerXline03,
				playerOline01, playerOline02,
				fieldInUse;

public:
	int modus;

	int  setModus( int &modus );
	int  swapPlayer( int &player, int &modus );
	void emptyField() const;
	void startGame( int &modus );
	void realPlayerSelectField();
	void playerSetField( char &playerOnMove, int &field );
	void computerLogicO( char &field );
	void computerLogicX( char &field );
	void computerLogic( char &playerOnMove);
	void setField01( char &playerOnMove,  bool &field01 );
	void setField02( char &playerOnMove,  bool &field02 );
	void setField03( char &playerOnMove,  bool &field03 );
	void setField04( char &playerOnMove,  bool &field04 );
	void setField05( char &playerOnMove,  bool &field05 );
	void setField06( char &playerOnMove,  bool &field06 );
	void setField07( char &playerOnMove,  bool &field07 );
	void setField08( char &playerOnMove,  bool &field08 );
	void setField09( char &playerOnMove,  bool &field09 );

	void checkForWi();
	void gameOver();
	std::string fieldToScreen() const;

	TicTacToe();
	~TicTacToe();
};
#endif
