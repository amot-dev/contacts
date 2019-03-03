//IO.CPP v1.0 BY ALEXANDER MOT
//Created 01/03/2017
//Updated 07/04/2017

#include "../include/IO.h"

//get the number of lines in a file
int numLines(string fileName) {
	int num = 0;
	string line;
	ifstream openFile(fileName);                        //open file
	while (getline(openFile, line)) {                   //go through lines while there are still lines
		num++;                                          //increment number of lines
	}
	openFile.close();                                   //close file
	return num;
}

//save the file to a vector
vector <string> saveFile(string fileName) {
    vector <string> temporary;
    int totalLines = numLines(fileName);                //remembers num of lines that need to be rewritten
    for (int x = 1; x <= totalLines; x++) {             //loops through the lines in file
        temporary.push_back(fromFile(x, fileName));     //adds current line to vector
    }
    return temporary;
}

//get string from a line in a file
string fromFile(int lineNum, string fileName) {
    string line;
    ifstream openFile(fileName);                        //open file
    for (int x = 1; x <= lineNum; x++) {
        getline(openFile, line);                        //go to line and take line into string
    }
    openFile.close();                                   //close file
    return line;
}

//get integer from a line in a file
int fromFileInt(int lineNum, string fileName) {
    int tempNum;
    ifstream openFile(fileName);                        //open file
    string i;                                           //placeholder string
    for (int x = 1; x < lineNum; x++) {
        getline(openFile, i);                           //go to line
    }
    openFile >> tempNum;                                //get integer
    openFile.close();
    return tempNum;
}

//get float from a line in a file
float fromFileFloat(int lineNum, string fileName) {
    float tempNum;
    ifstream openFile(fileName);                        //open file
    string i;                                           //placeholder string
    for (int x = 1; x < lineNum; x++) {
        getline(openFile, i);                           //go to line
    }
    openFile >> tempNum;                                //get float
    openFile.close();
    return tempNum;
}

//get char from a line in a file
char fromFileChar(int lineNum, string fileName) {
    char tempChar;
    ifstream openFile(fileName);                        //open file
    string i;                                           //placeholder string
    for (int x = 1; x < lineNum; x++) {
        getline(openFile, i);                           //go to line
    }
    openFile >> tempChar;                                //get float
    openFile.close();
    return tempChar;
}

//change content from a line in a file
void toFile(int lineNum, string fileName, string toWrite) {
    lineNum -= 1;                                       //take lineNum down by one because in programming we count from 0
    int totalLines = numLines(fileName);                //save the total number of lines before tampering
    vector <string> temporary = saveFile(fileName);     //save the file to temporary vector
    ofstream openFile;
    openFile.open(fileName, fstream::trunc);            //open file and delete content
    if (openFile.is_open()) {                           //if file opened...
        for (int x = 1; x < lineNum; x++) {
            openFile << temporary[(x - 1)] << "\n";     //write original content to file until changing line
        }
        openFile << toWrite << "\n";                    //write message
        for (int x = (lineNum + 1); x < totalLines; x++) {
            openFile << temporary[x] << "\n";           //write the rest of the file
        }
        openFile.close();                               //close file
    }
    else {                                              //if file not opened...
        cout << "\n";
        centerText("Fatal Error!");                     //display error message
    }
}

//get first line of temp file (use to output combination of strings and ints with centerText)
string ssRead() {
    string line;
    line = fromFile(2, "temp.txt");                     //get first line of "temp.txt"
    remove("temp.txt");                                 //delete "temp.txt"
    return line;
}

//write integer to the first line in a file (use to output combination of strings and ints with centerText)
void ssWriteInt(int toWrite) {
    string temporary = ssRead();
    ofstream openFile("temp.txt");                      //open "temp.txt"
    if (openFile.is_open()) {                           //if file opened...
        openFile << toWrite;                            //write message
        openFile.close();                               //close file
    }
    else {                                              //if file not opened...
        cout << "\n";
        centerText("Fatal Error!");                     //display error message
    }
}

//write string to the first line in a file (use to output combination of strings and ints with centerText)
void ssWriteString(string toWrite) {
    ofstream openFile;
    openFile.open("temp.txt");                          //open "temp.txt"
    if (openFile.is_open()) {                           //if file opened...
        openFile << toWrite;                            //write message
        openFile.close();                               //close file
    }
    else {                                              //if file not opened...
        cout << "\n";
        centerText("Fatal Error!");                     //display error message
    }
}
