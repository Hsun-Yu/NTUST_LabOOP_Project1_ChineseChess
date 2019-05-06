#include <iostream>
#include <iomanip>
#include <fstream>
#include <Windows.h>
#include <conio.h>
#include "Board.h"
#include "Position.h"

#define BLACK 0
#define WHITE FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY
#define GRAY FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE
#define RED FOREGROUND_RED
#define GREEN FOREGROUND_GREEN | FOREGROUND_INTENSITY
#define BLUE FOREGROUND_BLUE | FOREGROUND_INTENSITY
#define CYAN FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY
#define PURPLE FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY

class Game
{
public:
	Game();
	~Game();

	void initialize();
	bool getInitialType();
	void newGame();
	void lastGame();
	
	void display();

	void setTextStyle(int color, int backgroundColor);
	void setCursorBoardXY(Position);
	void setCursorXY(int x, int y);
	void moveCursor(int x, int y);
	void outputCount(string str, int count);
	void markOnScreen(Position, int);
	void unmarkOnScreen(Position);

	void saveGame(string filename);

	void inGame(); //use while loop to scan the keyboard code
	Position Up(vector<Position> objPosition);
	Position Down(vector<Position> objPosition);
	Position Left(vector<Position> objPosition);
	Position Right(vector<Position> objPosition);
	
	void selectChess(int& enterCount);				//type enter
	//void move(Position);
	//void showOption();

	vector<Position> getAllRedPosition();
	vector<Position> getAllBlackPosition();
private:
	Board board;
	bool whoPlay;	//red true, black false

	static HANDLE outputHandle;
	static COORD cursorXY; //cursor position on whole window

	Position chessMarkPosition;
	Position lastPosition;
	//int selectType;
};

