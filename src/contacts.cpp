//Title:                Contacts
//Description:          View and create contacts with multiple accounts
//Created By:           Sasha Mot
//Date Created:         12/04/2017
//Last Updated:         12/04/2017
//Known Limitations:    Spacing not allowed for any input

#include "../include/accountFunctions.h"
#include "../include/userFunctions.h"
#include "../include/settingsFunctions.h"
using namespace std;

//CONSTANT VARIABLES
const int devPass = 354635494;          //lets the 'user' access the dev menu

//BOOLEAN VARIABLES
bool run = true;                        //determines whether the program will run
bool userLogin = false;                 //determines the user's login status
bool forceLog = false;                  //forces the user to log out (when an account is deleted)

//INPUT VARIABLES
int selector;                           //lets users select options in menus
char userYN;                            //lets the user decide in yes or no situations

//STRINGSTREAM VARIABLES
stringstream con;                       //temp storage for conversion to string

//USER VARIABLES
string username;                        //the current user's username
string password;                        //the current user's password
int passLine = 1;                       //the line the password is stored on in user's file

//CONFIG VARIABLES
sortCon organiseContacts;               //class for organising contacts in alphabetical order
config rules;                           //class for everything to do with config rules

//MENU FUNCTIONS
void printTitle() {
    breakPage();
    cout << "****************    ****************    ********    ****    ****************    ****************    ****************    ****************    ****************\n";
    cout << "****************    ****************    ********    ****    ****************    ****************    ****************    ****************    ****************\n";
    cout << "****                ****        ****    **** ****   ****          ****          ****        ****    ****                      ****          ****            \n";
    cout << "****                ****        ****    **** ****   ****          ****          ****        ****    ****                      ****          ****            \n";
    cout << "****                ****        ****    ****  ****  ****          ****          ****************    ****                      ****          ****************\n";
    cout << "****                ****        ****    ****  ****  ****          ****          ****************    ****                      ****          ****************\n";
    cout << "****                ****        ****    ****   **** ****          ****          ****        ****    ****                      ****                      ****\n";
    cout << "****                ****        ****    ****   **** ****          ****          ****        ****    ****                      ****                      ****\n";
    cout << "****************    ****************    ****    ********          ****          ****        ****    ****************          ****          ****************\n";
    cout << "****************    ****************    ****    ********          ****          ****        ****    ****************          ****          ****************\n";
}

void mainMenu(bool userLogin) {
    while (userLogin == true) {                                         //if there is a user logged on
        printTitle();
        rules.loadConfig(username);                                     //load config file for current user
        organiseContacts.organise(username, passLine);
        printChar(54, '\n');
        cout << "Welcome, " << username << "\n\n";
        cout << "Press '1' to view contacts\n";
        cout << "Press '2' to edit a contact\n";
        cout << "Press '3' to add a contact\n";
        cout << "Press '4' to remove a contact\n";
        cout << "Press '5' to change account settings\n";
        cout << "Press '6' to logout\n";
        cin >> selector;
        clrIgn();
        switch(selector) {
            case 1:
                contactViewer();
                break;
            case 2:
                contactEditWizard();
                break;
            case 3:
                contactAddWizard();
                break;
            case 4:
                contactRemoveWizard();
                break;
            case 5:
                settingsMenu();
                if (forceLog) userLogin = false;                        //log the user off
                break;
            case 6:
                userLogin = false;                                      //log the user off
                break;
        }
    }
    if (userLogin == false) {                                           //if there is no user logged on
        printTitle();
        printChar(60, '\n');
        cout << "Press '1' to create an account\n";
        cout << "Press '2' to login to an existing account\n";
        cout << "Press '3' to exit\n";
        cin >> selector;
        clrIgn();
        switch(selector) {
            case 1:
                accountWizard();                                        //run the account creation wizard
                break;
            case 2:
                loginWizard();                                          //run the login wizard
                break;
            case 3:
                run = false;                                            //stop looping the program
                break;
            case devPass:
                devMenu();                                              //open the dev menu
                break;
        }
    }
}
int main() {while(run) mainMenu(userLogin);}                            //run the main menu (isn't it amazing how small main() is?)
