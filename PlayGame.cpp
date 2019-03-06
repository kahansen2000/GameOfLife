#include <iostream>
#include "PlayGame.h"
#include <math.h>
#include <cstdlib>
#include <fstream>
#include <time.h>

using namespace std;

int PlayGame::PickMode(){
	int mode;
	cout << "Pick your mode" <<endl;
	cout <<"Type 1 for Classic\n2 for Donut\nor 3 for Mirror" << endl;
	int answer;
	cin >>answer;
	while(answer!=1&&answer!=2&&answer!=3){
		cout << "Invalid, try again" <<endl;
		cin >> answer;
	}
	if(answer==1){
		cout <<"You've selected Classic Mode" << endl;
		return 1;
	}
	else if(answer==2){
		cout <<"You've selected Donut Mode" <<endl;
		return 2;
	}
	else{
		cout <<"You've selected Mirror Mode"<<endl;
		return 3;
	}
}
void PlayGame::GameSettings(){ 
	genCount=0;
	//How info is outputted
	cout << "How would you like the information to be outputted? With a pause, hit enter, or to a file?" <<endl;
	cout <<"Type 1 for pause\nType 2 for enter\nType 3 for a file" <<endl;
	cin >> outputStyle;
		while(outputStyle!=1&&outputStyle!=2&&outputStyle!=3){
		cout << "Invalid, try again" <<endl;
		cin >> outputStyle;
	}

	//Board type: random or from a file	
	cout << "Would you me to make a random board or would you like to provide the board?" <<endl;
	cout <<"Type 1 for random\nType 2 to provide the board" << endl;
	int answer;
	cin >> answer;
	while(answer!=1&&answer!=2){
		cout << "Invalid, try again" <<endl;
		cin >> answer;
	}
	if(answer==1){
		PlayGame::RandomBoard();
	}
	else{
		PlayGame::FromFileBoard();
	}
	//selecting the mode
	int mode=PlayGame::PickMode();
	
	int count=0;
	//while(countCells!=rows*cols&&countCells!=0){
	while(count<10){
		count++;
		if(mode==1){
			for(int i=0;i<rows;i++){
				for(int j=0;j<cols;j++){
					int numNeighbors=PlayGame::ClassicNeighbors(i,j);
					if(numNeighbors<=1){
						tempBoard[i][j]='-';
					}
					else if(numNeighbors==2){
						tempBoard[i][j]=board[i][j];
					}
					else if(numNeighbors==3){
						tempBoard[i][j]=='X';
					}
					else{
						tempBoard[i][j]='-';
					}
				}
			}
		}
		else if(mode==2){
			for(int i=0;i<rows;i++){
				for(int j=0;j<cols;j++){
					int numNeighbors=PlayGame::DonutNeighbors(i,j);
					if(numNeighbors<=1){
						tempBoard[i][j]='-';
					}
					else if(numNeighbors==2){
						tempBoard[i][j]=board[i][j];
					}
					else if(numNeighbors==3){
						tempBoard[i][j]=='X';
					}
					else{
						tempBoard[i][j]='-';
					}
				}
			}
		}
		else{
			for(int i=0;i<rows;i++){
				for(int j=0;j<cols;j++){
					int numNeighbors=PlayGame::MirrorNeighbors(i,j);
					if(numNeighbors<=1){
						tempBoard[i][j]='-';
					}
					else if(numNeighbors==2){
						tempBoard[i][j]=board[i][j];
					}
					else if(numNeighbors==3){
						tempBoard[i][j]=='X';
					}
					else{
						tempBoard[i][j]='-';
					}
				}
			}
		}
		//changing temp board to old board
		for(int i=0; i<rows;i++){
			for(int j=0;j<cols;j++){
				board[i][j]=tempBoard[i][j];
			}
		}
		//printing board
		if(outputStyle==1){//brief pause
			cout <<"Generation ";
			cout << genCount <<endl;
			PlayGame::PrintBoard();
		}
		else if(outputStyle==2){//oress enter
			cout << "Press Enter to Continue";
			cin.ignore();
			cout <<"\nGeneration ";
			cout << genCount <<endl;
			PlayGame::PrintBoard();
		}
		else{//to an output file ***************************** NOT DONE WITH THIS ONE !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
			//NEED TO FINISH THIS PART VERY BADLY
		}	
	}
}
void PlayGame::RandomBoard(){
	cout << "Now I need the dimensions of the world" <<endl;
	cout << "How many rows would you like?" <<endl;
	cin >>rows;
	cout << "And how many columns?" <<endl;
	cin >>cols;
	cout <<"Give me a number between 0 and 1 that will be the density of the population." <<endl;
	cin >> density;
	double numCells=rows*cols;
	numCells*=density;
	int randNum = rand() % 2;
	int count=0;
	int cellsLeft = rows*cols;
	board = new char*[cols];
	tempBoard= new char*[cols];
	for(int i=0; i<rows;i++){
		board[i]=new char[rows];
		tempBoard[i]=new char[rows];
	}
	//Filling the board randomly
	for(int i=0; i<rows;i++){
		for(int j=0; j<cols;j++){
			if((count<numCells&&randNum==1)||(cellsLeft<=(numCells-count))){
				board[i][j]='X';
				count++;
			}
			else{
				board[i][j]='-';
			}
			randNum=rand()%2;
			cellsLeft--;
		}
	}
	PlayGame::PrintBoard();
	
}
void PlayGame::FromFileBoard(){
	cout <<"What is the name of the file you'd like to read from?" <<endl;
	cin >> inputFile;
	std::ifstream infile(inputFile.c_str());
	cout <<"check2";
	if(infile.fail()){
		cout << "Your file didn't work" << endl;
	}
	//reading each line from the file
	else{
		int count=0;
		string line;
		//while(infile>>line){
			//cout <<line;
			cout << count;
		//}
	}
	
}
void PlayGame::PrintBoard(){
	for(int i=0; i<rows;i++){
		for(int j=0; j<cols;j++){
			cout <<board[i][j];
		}
		cout << endl;
	}
}
int PlayGame::ClassicNeighbors(int i, int j){
	//counting neighbors in classic mode
	int count=0;
	if(i==0&&j==0){
		if(board[i][j+1]=='X'){
			count++;
		}
		if(board[i+1][j+1]=='X'){
			count++;
		}
		if(board[i+1][j]=='X'){
			count++;
		}
	}
	else if(i==0&&j==cols-1){
		if(board[i][j-1]=='X'){
			count++;
		}
		if(board[i+1][j-1]=='X'){
			count++;
		}
		if(board[i+1][j]=='X'){
			count++;
		}
	}
	else if(i==rows-1&&j==0){
		if(board[i][j+1]=='X'){
			count++;
		}
		if(board[i-1][j+1]=='X'){
			count++;
		}
		if(board[i-1][j]=='X'){
			count++;
		}
	}
	else if(i==rows-1&&j==cols-1){
		if(board[i][j-1]=='X'){
			count++;
		}
		if(board[i-1][j-1]=='X'){
			count++;
		}
		if(board[i-1][j]=='X'){
			count++;
		}
	}
	else if(i==rows-1){
		if(board[i-1][j-1]=='X'){
			count++;
		}
		if(board[i-1][j]=='X'){
			count++;
		}
		if(board[i-1][j+1]=='X'){
			count++;
		}
		if(board[i][j-1]=='X'){
			count++;
		}
		if(board[i][j+1]=='X'){
			count++;
		}
	}
	else if(j==cols-1){
		if(board[i-1][j-1]=='X'){
			count++;
		}
		if(board[i-1][j]=='X'){
			count++;
		}
		if(board[i-1][j-1]=='X'){
			count++;
		}
		if(board[i-1][j+1]=='X'){
			count++;
		}
		if(board[i+1][j]=='X'){
			count++;
		}
	}
	else if(i==0){
		if(board[i-1][j]=='X'){
			count++;
		}
		if(board[i-1][j+1]=='X'){
			count++;
		}
		if(board[i][j+1]=='X'){
			count++;
		}
		if(board[i+1][j+1]=='X'){
			count++;
		}
		if(board[i+1][j]=='X'){
			count++;
		}
	}
	else if(j==0){
		if(board[i-1][j]=='X'){
			count++;
		}
		if(board[i][j+1]=='X'){
			count++;
		}
		if(board[i+1][j+1]=='X'){
			count++;
		}
		if(board[i+1][j]=='X'){
			count++;
		}
		if(board[i][j+1]=='X'){
			count++;
		}
	}
	else{
		if(board[i-1][j-1]=='X'){
			count++;
		}
		if(board[i-1][j]='X'){
			count++;
		}
		if(board[i-1][j+1]=='X'){
			count++;
		}
		if(board[i][j-1]=='X'){
			count++;
		}
		if(board[i][j+1]=='X'){
			count++;
		}
		if(board[i+1][j-1]=='X'){
			count++;
		}
		if(board[i+1][j]=='X'){
			count++;
		}
		if(board[i+1][j+1]=='X'){
			count++;
		}
	}
	return count;
}
int PlayGame::DonutNeighbors(int i, int j){
	int count=0;
	//if it is a middle cell, it acts normally
	if(i!=0&&j!=0&&i!=rows-1&&j!=rows-1){
		count=ClassicNeighbors(i,j);
	}
	//if it is a corner cell
	else if((i==0&&j==0)||(i==0&&j==cols-1)||(i==rows-1&&j==0)||(i==rows-1&&j==cols-1)){
		count=PlayGame::ClassicNeighbors(i,j); //get initial count from classic mode
		if(i==0&&j==0){
			if(board[rows-1][j]=='X'){
				count++;
			}
			if(board[rows-1][j+1]=='X'){
				count++;
			}
			if(board[i][cols-1]=='X'){
				count++;
			}
			if(board[i+1][cols-1]=='X'){
				count++;
			}
			if(board[rows-1][cols-1]=='X'){
				count++;
			}
		}
		else if(i==0&&j==cols-1){
			if(board[i][0]=='X'){
				count++;
			}
			if(board[i+1][0]=='X'){
				count++;
			}
			if(board[rows-1][0]=='X'){
				count++;
			}
			if(board[rows-1][j-1]=='X'){
				count++;
			}
			if(board[rows-1][j]=='X'){
				count++;
			}
		}
		else if(i==rows-1&&j==0){
			if(board[0][0]=='X'){
				count++;
			}
			if(board[0][j+1]=='X'){
				count++;
			}
			if(board[0][cols-1]=='X'){
				count++;
			}
			if(board[i-1][cols-1]=='X'){
				count++;
			}
			if(board[i][cols-1]=='X'){
				count++;
			}
		}
		else{
			if(board[0][0]=='X'){
				count++;
			}
			if(board[0][j]=='X'){
				count++;
			}
			if(board[0][j-1]=='X'){
				count++;
			}
			if(board[i-1][0]=='X'){
				count++;
			}
			if(board[i][0]=='X'){
				count++;
			}
		}
	}
	//edge but not corner
	else{
		count=PlayGame::ClassicNeighbors(i,j);
		if(i==0){
			if(board[rows-1][j]=='X'){
				count++;
			}
			if(board[rows-1][j-1]=='X'){
				count++;
			}
			if(board[rows-1][j+1]=='X'){
				count++;
			}
		}
		else if(j==0){
			if(board[i-1][cols-1]=='X'){
				count++;
			}
			if(board[i][cols-1]=='X'){
				count++;
			}
			if(board[i+1][cols-1]=='X'){
				count++;
			}
		}
		else if(i==rows-1){
			if(board[0][j-1]=='X'){
				count++;
			}
			if(board[0][j]=='X'){
				count++;
			}
			if(board[0][j+1]=='X'){
				count++;
			}
		}
		else{
			if(board[i-1][0]=='X'){
				count++;
			}
			if(board[i][0]=='X'){
				count++;
			}
			if(board[i+1][0]=='X'){
				count++;
			}
		}
	}
	return count;
}
int PlayGame::MirrorNeighbors(int i, int j){
	int count=0;
	//if it is a middle piece, it acts normal
	if(i!=0&&j!=0&&i!=rows-1&&j!=rows-1){
		count=ClassicNeighbors(i,j);
	}
	//if cell is a corner
	else if((i==0&&j==0)||(i==0&&j==cols-1)||(i==rows-1&&j==0)||(i==rows-1&&j==cols-1)){
		count=PlayGame::ClassicNeighbors(i,j);
		if(board[i][j]=='X'){
			count+=3;
		}
		
		if(i==0&&j==0){
			if(board[i][j+1]=='X'){
				count++;
			}
			if(board[i+1][j]=='X'){
				count++;
			}
		}
		else if(i==0&&j==cols-1){
			if(board[i][j-1]=='X'){
				count++;
			}
			if(board[i+1][j]=='X'){
				count++;
			}
		}
		else if(i==rows-1&&j==0){
			if(board[i][j+1]=='X'){
				count++;
			}
			if(board[i-1][j]=='X'){
				count++;
			}
		}
		else if(i==rows-1&&j==cols-1){
			if(board[i][j-1]=='X'){
				count++;
			}
			if(board[i-1][j]=='X'){
				count++;
			}
	}
	}
	//if it is an edge, but not a corner
	else{
		count=ClassicNeighbors(i,j);
		if(board[i][j]=='X'){
			count++;
		}
		if(i==0||i==rows-1){
			if(board[i][j-1]=='X'){
				count++;
			}
			if(board[i][j+1]=='X'){
				count++;
			}
		}
		else{
			if(board[i-1][j]=='X'){
				count++;
			}
			if(board[i+1][j]=='X'){
				count++;
			}
		}
	}
	return count;
}	

