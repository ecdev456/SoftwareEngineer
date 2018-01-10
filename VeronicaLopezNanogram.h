#pragma once
#ifndef VERONICALOPEZNANOGRAM_H
#define VERONICALOPEZNANOGRAM_H

#include <iostream>

using namespace std;


int rCord, cCord;
char currentBoard[5][5];
int winRow[13] = { 0,1,2,3,4,1,2,1,0,1,2,3,4 };
int winCol[13] = { 0,0,0,0,0,1,2,3,4,4,4,4,4 };

int emptyRow[12] = { 0,2,3,4,0,1,3,4,0,2,3,4 };
int emptyCol[12] = { 1,1,1,1,2,2,2,2,3,3,3,3 };


/*int validCheck()
{
	cout << "Enter row coordinate (1-5): ";
	cin >> rCord;
	while (rCord < 1 || rCord >5)
	{
		validCheck();
	}
	return rCord;
}
*/
void printBoard()
{
	cout << "      _5_ _1_ _1_ _1_ _5_" << endl;
	for (int row = 0; row < 5; row++)
	{
		if (row == 2)
		{
			cout << "1 1 1";
		}
		if (row == 1)
		{
			cout << "  2 2";
		}
		if (row == 0|| row == 3 || row == 4)
		{
			cout << "  1 1";
		}
		for (int column = 0; column < 5; column++)
		{
			
			cout << "|_";
			cout << currentBoard[row][column];
			cout << "_";
		}
		cout << "|";
		cout << endl;
	}
}

void freshBoard()
{
	for (int row = 0; row < 5; row++)
	{
		for (int column = 0; column < 5; column++)
		{
			currentBoard[row][column] = '_';
		}
	}	
	printBoard();
}


void displayCurrentBoard()
{
	currentBoard[rCord][cCord] = 'X';
	printBoard();
}
void userInput()
{
	cout << "Enter row coordinate (0-4): ";
	cin >> rCord;
	if (rCord < 0 || rCord > 4)
	{
		cout << "Invalid Input" << endl;
		cout << "Enter row coordinate (0-4): ";
		cin >> rCord;
	}
	
	cout << "Enter column coordinate (0-4): ";
	cin >> cCord;
	if (cCord < 0 || cCord > 4)
	{
		cout << "Invalid Input" << endl;
		cout << "Enter column coordinate (0-4): ";
		cin >> cCord;
	}

	displayCurrentBoard();
}

void remove() //takes in new coordinates for row and column and removed the X value
{
	cout << "Enter row coordinate (0-4): ";
	cin >> rCord;

	cout << "Enter column coordinate (0-4): ";
	cin >> cCord;

	currentBoard[rCord][cCord] = '_'; //replace any value to underscore
	printBoard(); 
}

bool checkWin()
{
	int count = 0;
	bool win;
	for (int i = 0; i < 13; i++)
	{
		if (currentBoard[winRow[i]][winCol[i]] == 'X')
		{
			count++;
		}
	}
	if (count == 13)
	{
		for (int j = 0; j < 12; j++)
		{
			if (currentBoard[emptyRow[j]][emptyCol[j]] == 'X')
			{
				win = false;
				return win;
			}
		}
		win = true;
		return win;
	}
	else
	{
		win = false;
		return win;
	}
		
}
#endif