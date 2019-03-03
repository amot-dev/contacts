//SPACING.H v1.1 BY ALEXANDER MOT
//Created 01/03/2017
//Updated 01/03/2017

#ifndef SPACING_H
#define SPACING_H

#include <iostream>
#include <string>
using namespace std;

#ifdef __APPLE__
//const int conWidth = 85;    //the width of the minimised console in Xcode
const int conWidth = 279;   //the width of the fullscreen console in Xcode
#endif
#ifdef __linux__
const int conWidth = 150;   //the width of the console of the terminal
#endif
#ifdef _WIN32
const int conWidth = 225;   //the width of the console in command prompt
#endif

const int pageBreak = 200;  //clear screen number

void printChar(int charNum, char charType);
void breakPage();
void centerTextCin(string str);
void centerText(string str);
void clrIgn();

#endif
