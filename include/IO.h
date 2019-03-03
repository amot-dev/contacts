#ifndef IO_H
#define IO_H

#include <iostream>
#include <fstream>
#include <vector>
#include "spacing.h"
using namespace std;

int numLines(string fileName);
vector <string> saveFile(string fileName);
string fromFile(int lineNum, string FileName);
int fromFileInt(int lineNum, string fileName);
float fromFileFloat(int lineNum, string fileName);
char fromFileChar(int lineNum, string fileName);
void toFile(int lineNum, string fileName, string toWrite);
void ssWriteInt(int toWrite);
void ssWriteString(string toWrite);
string ssRead();

#endif
