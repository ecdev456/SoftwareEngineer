// Project 1 NonoGram.cpp : Defines the entry point for the console application.
//

#include "ecdev456.h"


int main()
{

	DefaultArray();
	//ReadSpecialFile();
	PrintArray();

	NonoArray[2][3] = 'X';
	SaveToSpecialFile();
	ReadSpecialFile();
	PrintArray();
    return 0;
}

