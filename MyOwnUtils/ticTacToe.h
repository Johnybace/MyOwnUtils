#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <string>

class TicTacToe
{
private:
	char playerOnMove, firstPlayerOnScreen, secondPlayerOnScreen;

	int  width, width01, width02, player, counter, field;

	bool field01, field02, field03, field04, field05, field06,
		 field07, field08, field09, winner, allReadyDone, countSwapPlayer;

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

	int  setModus( int& );
	int  swapPlayer( int& );

	void emptyField() const;
	void startGame( int& );
	void realPlayerSelectField();
	void playerSetField( char&, int& );
	void computerLogicO( char& );
	void computerLogicX( char& );
	void computerLogic( char&);
	void setField01( char&, bool& );
	void setField02( char&, bool& );
	void setField03( char&, bool& );
	void setField04( char&, bool& );
	void setField05( char&, bool& );
	void setField06( char&, bool& );
	void setField07( char&, bool& );
	void setField08( char&, bool& );
	void setField09( char&, bool& );
	void checkForWi();
	void gameOver() const;
	void fieldToScreen() const;

	TicTacToe();
	~TicTacToe();
};
#endif
