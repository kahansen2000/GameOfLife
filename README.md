# GameOfLife
//Katherine Hansen
//2326665
//CPSC350-01
//Assignment 2: Game of Life
//This program runs the game of life module giving the user a choice of input and output styles and modes

Source Files:
main.cpp
PlayGame.h
PlayGame.cpp
test.txt //an example text file

I used the following resources:
cplusplus.com
tutorialspoint.com
geeksforgeeks.org
stackoverflow.com

Errors:
I am getting segmentation fault error 11 each time I run the program, and I was unable to debug this
From what I could understand online, it may be due to the fact that my 2D array board was sized based on variables, but I am unsure of how to fix this
This causes the program to cutoff short, and it never reaches the output part.
If the program were to run past this, I elected to have the simulation stop after 1000 if it is infinite
I also was unable to do the pause option for the output styles correctly

To run:
I used g++ to test the programs, but I have also included a makefile

g++ *.cpp
./a.out
