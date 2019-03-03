//SPACING.CPP v1.1 BY ALEXANDER MOT
//Created 01/03/2017
//Updated 07/04/2017

#include "../include/spacing.h"

//outputs a character multiple times to the console
void printChar(int charNum, char charType) {
	for (int x = 1; x < charNum; x++)
		cout << charType;
}

//inserts many blank spaces
void breakPage() {
	printChar(pageBreak, '\n');
}

//centers text without line break
void centerTextCin(string str) {
	printChar((conWidth - static_cast<int>(str.length())) / 2, ' ');
	cout << str;
}

//centers text on the screen
void centerText(string str) {
	centerTextCin(str);
	cout << "\n";
}

//clears the cin buffer
void clrIgn() {
    cin.clear();
    cin.ignore();
}
