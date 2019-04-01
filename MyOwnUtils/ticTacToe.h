#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <string>

class TicTacToe
{
private:
	char playerOnMove{'X'};

	int  width{16}, width01{57}, width02{51};

	std::string  playerFieldLine01 {"       |       |       "}	
				,playerFieldLine02 {"       |       |       "}		
				,playerFieldLine03 {"       |       |       "}		
				,playerFieldLine04 {"       |       |       "}		
				,playerFieldLine05 {"   7   |   8   |   9   "}			
				,playerFieldLine06 {"       |       |       "}		
				,playerFieldLine07 {"       |       |       "}		
				,playerFieldLine08 {"       |       |       "}		
				,playerFieldLine09 {"       |       |       "}		
				,playerFieldLine10 {"   4   |   5   |   6   "}		
				,playerFieldLine11 {"       |       |       "}
				,playerFieldLine12 {"       |       |       "}
				,playerFieldLine13 {"       |       |       "}
				,playerFieldLine14 {"       |       |       "}
				,playerFieldLine15 {"   1   |   2   |   3   "}
				,playerFieldSpacer {"-------|-------|-------"}
				,playerXline01	   {"X   X"}
				,playerXline02	   {" X X "}
				,playerXline03	   {"  X  "}
				,playerOline01	   {" OOO "}
				,playerOline02	   {"O   O"};

public:
	bool field01{true}, field02{true}, field03{true}, field04{true}
		,field05{true}, field06{true}, field07{true}, field08{true}
		,field09{true}, winner{false};

	std::string gameFieldToString() const;
	void startGame(char &playerOnMove) const;
	void gameOver() const;
	void setField07(int  &player,  bool & );
	void setField08(int  &player,  bool & );
	void setField09(int  &player,  bool & );
	void setField04(int  &player,  bool & );
	void setField05(int  &player,  bool & );
	void setField06(int  &player,  bool & );
	void setField01(int  &player,  bool & );
	void setField02(int  &player,  bool & );
	void setField03(int  &player,  bool & );
	void checkForWi(bool &field01, bool &field02, bool &field03, 
					bool &field04, bool &field05, bool &field06, bool &winner,
					bool &field07, bool &field08, bool &field09, int  &player);
	int  swapPlayer(int  &player);

	~TicTacToe();
};
#endif
