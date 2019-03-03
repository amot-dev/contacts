#include "../include/devFunctions.h"

int getUserLine(string username) {
    int line = 0;                       //temp hold for userLine
    int fileLength;                     //the length of the open file
    fileLength = numLines("../data/Accounts.txt");                      //get file length of Accounts.txt
    for (int i = 1; i <= fileLength; i++) {                             //go through Accounts.txt
        if (username == fromFile(i, "../data/Accounts.txt")) {          //check if username matches anything
            line = i;                                                   //set line for matching username
        }                                                               //set line to 0 if no line matches
    }
    return line;
}
void deleteUser(string deletedUser, int userLine) {
    vector <string> hold;               //holds the open file
    con.str("");
    con << "rm -rf " << "../data/user-" << deletedUser;                 //set con to command to recursively delete user's folder (the -r tag)
    system(con.str().c_str());                                          //execute rm command
    hold = saveFile("../data/Accounts.txt");                            //temporarily hold Accounts.txt
    hold.erase (hold.begin()+(userLine - 1));                           //remove deleted user from hold
    ofstream deletionWiz("../data/Accounts.txt", fstream::trunc);       //open Accounts.txt and delete all content
    if (deletionWiz.is_open()) {
        for (int i = 0; i < static_cast<int>(hold.size()); i++) {       //loop through Accounts.txt
            deletionWiz << hold[i] << "\n";                             //put hold into it
        }
    }
    else {                                                              //if file not opened...
        cout << "\nFatal Error!\n";                                     //...display error message
    }
    deletionWiz.close();
    cout << "\nUser deleted\n";
}
void deletionWizard() {
    bool isUser = false;                //determines whether the string inputted is a real user
    int userLine = 1;                   //the line the user is on
    int fileLength;                     //the length of the open file
    string deletedUser;                 //the name of the user being deleted
    breakPage();
    fileLength = numLines("../data/Accounts.txt");
    for (int i = 1; i <= fileLength; i++) {
        cout << fromFile(i, "../data/Accounts.txt") << "\n";            //show list of all users
    }
    cout << "\n";
    cout << "What user to delete?: ";
    cin >> deletedUser;
    clrIgn();
    for (int i = 1; i <= fileLength; i++) {
        if (deletedUser == fromFile(i, "../data/Accounts.txt")) {       //check if user to be deleted exists (the rm -rf tag is dangerous)
            isUser = true;
            userLine = getUserLine(deletedUser);                        //get line of user to be deleted
        }
    }
    if (isUser) {
        cout << "Are you sure? (Y/N): ";
        cin >> userYN;
        clrIgn();
        if (userYN == 'Y' || userYN == 'y') {
            deleteUser(deletedUser, userLine);                          //delete user
        }
        else {
            cout << "\nCancelling operation...\n";
        }
    }
    else {
        cout << "\nThat user does not exist\n";
    }
    wait(1);
}
void devMenu() {
    bool dev = true;                    //determines whether the dev menu will run
    while(dev) {
        breakPage();
        cout << "Developper Menu\n";
        cout << "===============\n\n";
        cout << "Press '1' to delete specific user\n";
        cout << "Press '2' to delete all users\n";
        cout << "Press '3' to close menu\n";
        cin >> selector;
        clrIgn();
        switch(selector) {
            case 1:
                deletionWizard();                                       //run the user deletion wizard
                break;
            case 2:
                breakPage();
                cout << "Are you sure? (Y/N): ";
                cin >> userYN;
                clrIgn();
                if (userYN == 'Y' || userYN == 'y') {
                    system("rm -rf ../data/user-*");                    //removes all folders starting with user-
                    system("rm ../data/Accounts.txt");                  //removes Accounts.txt
                }
                else cout << "\nCancelling operation...\n";
                wait(1);
                break;
            case 3:
                userLogin = false;                                      //log out any users that might be logged on (redundant)
                dev = false;                                            //stop looping dev menu
                break;
        }
    }
}
