//ACCOUNTFUNCTIONS.CPP v1.0 BY ALEXANDER MOT
//Created 19/04/2017
//Updated 19/04/2017

#include "../include/accountFunctions.h"

void accountWizard() {
    bool goodName = true;               //if the user picked a good username
    int fileLength;                     //the length of the open file
    int minPassLength = 8;              //the minimum length of a password

    breakPage();
    fileLength = numLines("Accounts.txt");
    cout << "Please type in a username: ";
    cin >> username;
    clrIgn();
    for (int i = 1; i <= fileLength; i++) {
        if (username == fromFile(i, "Accounts.txt")) goodName = false;  //check Accounts.txt for username
    }
    if (goodName == false) {                                            //if the username is already taken
        cout << "\nThat name is already taken\n";
        userLogin = false;
    }
    else {                                                              //if the username is not yet taken
        cout << "Please type in a password (at least 8 characters): ";
        cin >> password;
        clrIgn();
        if (static_cast<int>(password.length()) >= minPassLength) {
            ofstream accountWiz("Accounts.txt", ios::app);              //open Accounts.txt to append
            if (accountWiz.is_open()) {
                accountWiz << username << "\n";                         //add username to Accounts.txt
            }
            else {                                                      //if file not opened...
                cout << "\nFatal Error!\n";                             //...display error message
            }
            accountWiz.close();                                         //close Accounts.txt
            con.str("");
            con << "mkdir " << "user-" << username;                     //set con to bash command to create directory for user
            system(con.str().c_str());                                  //execute mkdir command
            con.str("");
            con << "user-"<< username << "/@" << username << ".txt";    //set con to user file's path
            accountWiz.open(con.str());                                 //open user file
            if (accountWiz.is_open()) {
                accountWiz << password << "\n";                         //add password to user file
            }
            else {                                                      //if file not opened...
                cout << "\nFatal Error!\n";                             //...display error message
            }
            accountWiz.close();
            con.str("");
            con << "user-" << username << "/format.txt";                //set con to path to config file
            accountWiz.open(con.str());                                 //open config file
            if (accountWiz.is_open()) {
                for (int i = 0; i < 3; i++) {                           //for the first 3 rules
                    accountWiz << "True\n";                             //set to true
                }
                accountWiz << "-\n";                                    //set number format spacer to default '-'
            }
            else {                                                      //if file not opened...
                cout << "\nFatal Error!\n";                             //...display error message
            }
            userLogin = true;                                           //log the user in
            cout << "\nCreating account...\n";
        }
        else {                                                          //if the password length is not sufficient
            cout << "\nPassword not long enough\nOperation cancelled...\n";
        }
    }
    wait(1);
}
void loginWizard() {
    bool correctName = false;           //determines whether the user has a valid username
    int fileLength;                     //the length of the open file
    int loggingOn;                      //determines how many times the user attempted to login
    breakPage();
    userLogin = false;                  //sets the user to be logged out (redundant)
    cout << "Enter your username: ";
    cin >> username;
    clrIgn();
    con.str("");
    fileLength = numLines("Accounts.txt");
    for(int i = 1; i <= fileLength; i++) {                              //loops through Accounts.txt
        if (fromFile(i, "Accounts.txt") == username) {                  //if username matches a line
            correctName = true;                                         //user has a valid name
        }
    }
    if (correctName == true) {
        loggingOn = 3;                                                  //set password attempts to 3
        while(loggingOn > 0) {
            cout << "Enter your password: ";
            cin >> password;
            clrIgn();
            con.str("");
            con << "user-" << username << "/@" << username << ".txt";   //set con to user file's path
            if (password == fromFile(passLine, con.str())) {            //if password matches username
                userLogin = true;                                       //set user to logged on
                loggingOn = 0;                                          //set login attempts to 0
                cout << "\nYou are now logged on, " << username;
            }
            else {                                                      //if password does not match
                userLogin = false;                                      //set user to logged off (redundant)
                loggingOn -= 1;                                         //take off an attempt
                cout << "\nPassword Incorrect\nYou have " << loggingOn << " attempts left\n";
            }
            cout << "\n";
        }
    }
    else {                                                              //if username is not found
        cout << "\nThat is not a valid username\n";
    }
    wait(1);
}
