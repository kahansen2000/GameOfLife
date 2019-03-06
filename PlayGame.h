//Katherine Hansen
//2326665
//kahansen@chapman.edu
//CPSC350-01
//Assignment 2: Game of Life
#include <iostream>
  
using namespace std;

class PlayGame{
        public:
                PlayGame();//constructor
                ~PlayGame();//destructor

                void  pickMode();//lets the user choose their choice mode
                void gameSettings();//Allows the user to choose their settings

                void fromFileBoard();//creates a board from the given file
                void randomBoard();//creates a randomized board
                void printBoard();//prints the board

                int classicNeighbors(int x, int y);//returns num neighbors in classic mode
                int donutNeighbors(int x, int y);//returns num neighbors in donut mode
                int mirrorNeighbors(int x, int y);//returns num neighbors in mirror mode

                int mode;
                int outputStyle;
                string outputFile;
                double density;
                char** board;
                char** tempBoard;
                string inputFile;
                int genCount;
                int countCells;
};

