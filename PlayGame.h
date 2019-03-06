#include <iostream>

using namespace std;

class PlayGame{
	public:
		int PickMode();//lets the user choose their choice mode
		void GameSettings();//Allows the user to choose their settings
		
		void FromFileBoard();//creates a board from the given file
		void RandomBoard();//creates a randomized board
		void PrintBoard();//prints the board
		
		int ClassicNeighbors(int x, int y);//returns num neighbors in classic mode
		int DonutNeighbors(int x, int y);//returns num neighbors in donut mode
		int MirrorNeighbors(int x, int y);//returns num neighbors in mirror mode
		
		int rows;
		int cols;
		int outputStyle;
		string outputFile;
		double density;
		char** board;
		char** tempBoard;
		string inputFile;
		int genCount;
		int countCells;
};
