#include "../include/settingsFunctions.h"

void passwordWizard() {
    vector <string> hold;               //holds the open file
    string passwordTemp;                //the password to change to
    breakPage();
    cout << "Enter a new password: ";
    cin >> passwordTemp;
    clrIgn();
    cout << "Are you sure? (Y/N): ";
    cin >> userYN;
    clrIgn();
    if (userYN == 'Y' || userYN == 'y') {
        con.str("");
        con << "../data/user-" << username << "/@" << username << ".txt";
        hold = saveFile(con.str());
        hold.erase (hold.begin()+(passLine - 1));                       //remove old password
        ofstream passwordWiz(con.str(), fstream::trunc);
        if (passwordWiz.is_open()) {
            passwordWiz << passwordTemp << "\n";
            for (int i = 0; i <= static_cast<int>(hold.size() - 1); i++) {  //loop through rest of user file (don't know why the -1 needs to be there but it does or else things break)
                passwordWiz << hold[i] << "\n";                         //put everything back
            }
        }
        else {                                                          //if file not opened...
            cout << "\nFatal Error!\n";                                 //...display error message
        }
        passwordWiz.close();
        cout << "\nPassword changed\n";
    }
    else {
        cout << "\nCancelling operation...\n";
    }
    wait(1);
}
void configWizard() {
    bool updated = false;               //tells whether anything was updated
    char tempChar = '-';                //temporarily holds separator
    rules.loadConfig(username);
    breakPage();
    cout << "Config rules\n";
    cout << "\n";
    if (rules.firstNameFirst) cout << "1 - First name comes first\n";
    else cout << "1 - Last name comes first\n";
    if (rules.emailBeforePhone) cout << "2 - Emails come before phone numbers\n";
    else cout << "2 - Phone numbers come before emails\n";
    if (rules.formatPhone) cout << "3 - Use character to separate phone numbers (ex: 555-555-5555)\n";
    else cout << "3 - Do not use character to separate phone numbers (ex: 5555555555)\n";
    cout << "4 - The separation character is: " << rules.formatPhoneChar << "\n";
    cout << "\nPress 1 through 4 to edit rules: ";
    cin >> selector;
    clrIgn();
    cout << "\n";
    switch(selector) {
        case 1:
            cout << "Press '1' for 'First name comes first'\n";
            cout << "Press '2' for 'Last name comes first'\n";
            cin >> selector;
            clrIgn();
            if (selector == 1) {
                rules.firstNameFirstTemp = "True";
                updated = true;
            }
            else if (selector == 2) {
                rules.firstNameFirstTemp = "False";
                updated = true;
            }
            else cout << "\nNo changes made\n";
            break;
        case 2:
            cout << "Press '1' for 'Emails before phone numbers'\n";
            cout << "Press '2' for 'Phone numbers before emails'\n";
            cin >> selector;
            clrIgn();
            if (selector == 1) {
                rules.emailBeforePhoneTemp = "True";
                updated = true;
            }
            else if (selector == 2) {
                rules.emailBeforePhoneTemp = "False";
                updated = true;
            }
            else cout << "\nNo changes made\n";
            break;
        case 3:
            cout << "Press '1' for 'Use character to separate phone numbers'\n";
            cout << "Press '2' for 'Do not use character to separate phone numbers'\n";
            cin >> selector;
            clrIgn();
            if (selector == 1) {
                rules.formatPhoneTemp = "True";
                updated = true;
            }
            else if (selector == 2) {
                rules.formatPhoneTemp = "False";
                updated = true;
            }
            else cout << "\nNo changes made\n";
            break;
        case 4:
            cout << "Please type in a character: ";
            cin >> tempChar;
            clrIgn();
            cout << "\n";
            updated = true;
            break;
    }
    con.str("");
    con << "../data/user-" << username << "/format.txt";                //set con to format file path
    ofstream configWiz(con.str(), fstream::trunc);
    if (configWiz.is_open()) {
        configWiz << rules.firstNameFirstTemp << "\n";                  //update config rules
        configWiz << rules.emailBeforePhoneTemp << "\n";
        configWiz << rules.formatPhoneTemp << "\n";
        if (selector == 4) configWiz << tempChar << "\n";               //check if the character was updated
        else configWiz << rules.formatPhoneChar << "\n";
    }
    else {                                                              //if file not opened...
        cout << "\nFatal Error!\n";                                     //...display error message
    }
    configWiz.close();
    if (updated) cout << "Operation complete\n";
    wait(1);
}
void contactClearWizard() {
    breakPage();
    cout << "Are you sure? (Y/N): ";
    cin >> userYN;
    clrIgn();
    if (userYN == 'Y' || userYN == 'y') {
        con.str("");
        con << "rm ../data/user-" << username << "/entry-*";
        system(con.str().c_str());
        con.str("");
        con << "../data/user-" << username << "/@" << username << ".txt";
        password = fromFile(passLine, con.str());
        ofstream contactClearWiz(con.str(), fstream::trunc);
        if (contactClearWiz.is_open()) {
            contactClearWiz << password;
        }
        else {                                                          //if file not opened...
            cout << "\nFatal Error!\n";                                 //...display error message
        }
        cout << "\nOperation complete\n";
    }
    else cout << "\nCancelling operation...\n";
    wait(1);
}
void settingsMenu() {
    bool settings = true;               //determines whether the settings menu will run
    while (settings) {
        breakPage();
        cout << "Account Settings\n";
        cout << "================\n\n";
        cout << "Press '1' to change password\n";
        cout << "Press '2' to change formatting\n";
        cout << "Press '3' to remove all contacts\n";
        cout << "Press '4' to delete account\n";
        cout << "Press '5' to close menu\n";
        cin >> selector;
        clrIgn();
        switch(selector) {
            case 1:
                passwordWizard();
                break;
            case 2:
                configWizard();
                break;
            case 3:
                contactClearWizard();
                break;
            case 4:
                breakPage();
                cout << "Are you sure? (Y/N): ";
                cin >> userYN;
                clrIgn();
                if (userYN == 'Y' || userYN == 'y') {
                    deleteUser(username, getUserLine(username));        //delete the current user
                    settings = false;                                   //close the settings menu
                    forceLog = true;                                    //tell the main menu to log the user off
                }
                else cout << "\nCancelling operation...\n";
                wait(1);
                break;
            case 5:
                settings = false;                                       //close the settings menu
                break;
        }
    }
}
