//USERFUNCTIONS.CPP v1.0 BY ALEXANDER MOT
//Created 19/04/2017
//Updated 19/04/2017

#include "../include/userFunctions.h"

void listContacts() {
    breakPage();
    person contact;                     //holds first and last name of person
    vector <string> hold;               //holds the open file
    con.str("");
    con << "user-" << username << "/@" << username << ".txt";
    hold = saveFile(con.str());
    hold.erase (hold.begin()+(passLine - 1));                           //remove password from list of contacts
    for (int i = 0; i < static_cast<int>(hold.size()); i++) {
        con.str("");
        con << "user-" << username << "/entry-" << hold[i] << ".txt";   //open contact file
        contact.firstName = fromFile(1, con.str());                     //add names to contact person
        contact.lastName = fromFile(2, con.str());
        if (rules.firstNameFirst) {
            cout << (i + 1) << " - " << contact.firstName << " " << contact.lastName << "\n";           //display list of contacts
        }
        else {
            cout << (i + 1) << " - " << contact.lastName << ", " << contact.firstName << "\n";          //display list of contacts
        }
    }
    cout << "\n";

}
void listContactsFancy(person contact) {
    vector <string> emails;             //holds contact's emails
    vector <string> phones;             //holds contact's phones
    string phoneTemp;                   //holds the phone number being formatted
    if (rules.firstNameFirst) {
        printChar(conWidth, '#');                                                                       //display top border
        cout << "\n";
        cout << contact.firstName << " " << contact.lastName << "\n";                                   //display name
        printChar(static_cast<int>(contact.firstName.length() + contact.lastName.length()) + 2, '=');   //display underline
        cout << "\n";
    }
    else {
        printChar(conWidth, '#');
        cout << "\n";
        cout << contact.lastName << ", " << contact.firstName << "\n";
        printChar(static_cast<int>(contact.firstName.length() + contact.lastName.length()) + 3, '=');
        cout << "\n";
    }
    emails = contact.getEmails();                                   //fetch emails vector from contact person
    phones = contact.getPhones();                                   //fetch phones vector from contact person
    if (rules.emailBeforePhone) {
        for (int i = 0; i < static_cast<int>(emails.size()); i++) {                                     //for each email
            cout << emails[i] << "\n";                                                                  //display email
        }
        if (contact.emailNum == 0) cout << "No emails" << "\n";
        cout << "\n";
        if (rules.formatPhone) {                                    //if phone numbers are to be formatted
            for (int i = 0; i < static_cast<int>(phones.size()); i++) {                                 //for each phone number
                phoneTemp = phones[i];
                cout << phoneTemp[0] << phoneTemp[1] << phoneTemp[2] << rules.formatPhoneChar;          //display formatted number
                cout << phoneTemp[3] << phoneTemp[4] << phoneTemp[5] << rules.formatPhoneChar;
                cout << phoneTemp[6] << phoneTemp[7] << phoneTemp[8] << phoneTemp[9] << "\n";
            }
        }
        else {                                                      //if phone numbers not formatted
            for (int i = 0; i < static_cast<int>(phones.size()); i++) {                                 //for each phone number
                cout << phones[i] << "\n";                                                              //display unformatted number
            }
        }
        if (contact.phoneNum == 0) cout << "No phone numbers" << "\n";
    }

    else {
        if (rules.formatPhone) {
            for (int i = 0; i < static_cast<int>(phones.size()); i++) {
                phoneTemp = phones[i];
                cout << phoneTemp[0] << phoneTemp[1] << phoneTemp[2] << rules.formatPhoneChar;
                cout << phoneTemp[3] << phoneTemp[4] << phoneTemp[5] << rules.formatPhoneChar;
                cout << phoneTemp[6] << phoneTemp[7] << phoneTemp[8] << phoneTemp[9] << "\n";
            }
        }
        else {
            for (int i = 0; i < static_cast<int>(phones.size()); i++) {
                cout << phones[i] << "\n";
            }
        }
        if (contact.phoneNum == 0) cout << "No phone numbers" << "\n";
        cout << "\n";
        for (int i = 0; i < static_cast<int>(emails.size()); i++) {
            cout << emails[i] << "\n";
        }
        if (contact.emailNum == 0) cout << "No emails" << "\n";
    }
}
person getContact(string contactName) {
    person contact;                     //holds contact info
    con.str("");
    con << "user-" << username << "/entry-" << contactName << ".txt";                                   //open contact file
    contact.firstName = fromFile(1, con.str());                     //add all information to contact person
    contact.lastName = fromFile(2, con.str());
    contact.emailNum = fromFileInt(3, con.str());
    contact.phoneNum = fromFileInt(4, con.str());
    contact.clearVectors();                                         //clear emails and phone numbers
    for (int i = 0; i < contact.emailNum; i++) {                    //for the number of emails there are
        contact.addToEmails(fromFile((i + 5), con.str()));          //add email to vector
    }
    for (int i = 0; i < contact.phoneNum; i++) {                    //for the number of phones numbers there are
        contact.addToPhones(fromFile((i + 5 + contact.emailNum), con.str()));                           //add phone number to vector
    }
    listContactsFancy(contact);
    return contact;
}
void contactViewer() {
    breakPage();
    vector <string> hold;               //holds the open file
    con.str("");
    con << "user-" << username << "/@" << username << ".txt";
    hold = saveFile(con.str());
    hold.erase (hold.begin()+(passLine - 1));                           //remove password from list of contacts
    for (int i = 0; i < static_cast<int>(hold.size()); i++) {           //for each item in contacts...
        getContact(hold[i]);
    }
    cout << "\nPress any key then enter to close\n";
    cin >> selector;
    clrIgn();
}
vector <string> deleteFromVector(int toDelete, vector <string> vectorToChange) {
    vectorToChange.erase (vectorToChange.begin()+toDelete);
    return vectorToChange;
}
void contactEditWizard() {
    listContacts();
    person contact;                     //holds the user being edited
    sortCon orgVector;                  //vector organiser
    bool editing = true;                //determines if the user is editing
    vector <string> hold;               //holds the open file
    vector <string> emails;             //holds emails
    vector <string> phones;             //holds phones
    string emailTemp;                   //temp email holder
    string phoneTemp;                   //temp phone hold
    string tempCon;                     //temporary hold for con
    string contactPath;                 //holds the path to the contact being edited
    con.str("");
    con << "user-" << username << "/@" << username << ".txt";
    hold = saveFile(con.str());                                         //save user file
    hold.erase (hold.begin()+(passLine - 1));                           //remove password from user file
    cout << "Select a contact to edit\n";
    cin >> selector;
    clrIgn();
    if (selector <= static_cast<int>(hold.size()) && selector > 0) {    //make sure selected contact is in range
        contact = getContact(fromFile((selector + 1), con.str()));
        contactPath = con.str();
        while(editing) {
            breakPage();
            listContactsFancy(contact);
            printChar(5, '\n');
            cout << "Press '1' to edit first name\n";
            cout << "Press '2' to edit last name\n";
            cout << "Press '3' to add an email\n";
            cout << "Press '4' to add a phone number\n";
            cout << "Press '5' to change an email\n";
            cout << "Press '6' to change a phone number\n";
            cout << "Press '7' to remove an email\n";
            cout << "Press '8' to remove a phone number\n";
            cout << "Press '9' to save changes\n";
            cout << "Press '0' to close menu\n";
            cin >> selector;
            clrIgn();
            cout << "\n";
            switch(selector) {
                case 1:
                    cout << "Please enter a new first name: ";
                    cin >> contact.firstName;                           //get new first name
                    clrIgn();
                    break;
                case 2:
                    cout << "Please enter a new last name: ";
                    cin >> contact.lastName;                            //get new last name
                    clrIgn();
                    break;
                case 3:
                    cout << "Please enter an email to add: ";
                    cin >> emailTemp;                                   //get new email
                    clrIgn();
                    contact.addToEmails(emailTemp);                     //add email to contact
                    contact.emailNum += 1;                              //add 1 to the number of emails
                    break;
                case 4:
                    cout << "Please enter a phone number to add: ";
                    cin >> phoneTemp;                                   //get new phone number
                    clrIgn();
                    contact.addToPhones(phoneTemp);                     //add phone number to contact
                    contact.phoneNum += 1;                              //add 1 to the number of phone numbers
                    break;
                case 5:
                    emails = contact.getEmails();                       //get emails from contact
                    for (int i = 0; i < static_cast<int>(emails.size()); i++) {
                        cout << (i + 1) << " - " << emails[i] << "\n";  //display emails
                    }
                    cout << "\nWhich email do you want to change?: ";
                    cin >> selector;
                    clrIgn();
                    if (selector <= static_cast<int>(emails.size()) && selector > 0) {                  //make sure selected email is in range
                        contact.setEmails(deleteFromVector((selector - 1), emails));                    //delete changed email and update the contact
                        cout << "\nChange email to: ";
                        cin >> emailTemp;                               //get new email
                        clrIgn();
                        contact.addToEmails(emailTemp);                 //add email to contact
                    }
                    else {
                        cout << "\nThat email does not exist\n";
                    }
                    break;
                case 6:
                    phones = contact.getPhones();                       //get phone numbers from contact
                    for (int i = 0; i < static_cast<int>(phones.size()); i++) {
                        cout << (i + 1) << " - " << phones[i] << "\n";  //display phone numbers
                    }
                    cout << "\nWhich phone number do you want to change?: ";
                    cin >> selector;
                    clrIgn();
                    if (selector <= static_cast<int>(phones.size()) && selector > 0) {                  //make sure selected phone number is in range
                        contact.setPhones(deleteFromVector((selector - 1), phones));                    //delete changed phone number and update the contact
                        cout << "\nChange phone number to: ";
                        cin >> phoneTemp;                               //get new phone number
                        clrIgn();
                        contact.addToPhones(phoneTemp);                 //add phone number to contact
                    }
                    else {
                        cout << "\nThat phone number does not exist\n";
                    }
                    break;
                case 7:
                    emails = contact.getEmails();                       //get emails from contact
                    for (int i = 0; i < static_cast<int>(emails.size()); i++) {
                        cout << (i + 1) << " - " << emails[i] << "\n";  //display emails
                    }
                    cout << "\nWhich email do you want to delete?: ";
                    cin >> selector;
                    clrIgn();
                    if (selector <= static_cast<int>(emails.size()) && selector > 0) {                  //make sure selected email is in range
                        contact.setEmails(deleteFromVector((selector - 1), emails));                    //delete email and update the contact
                        contact.emailNum -= 1;                                                          //subtract 1 from the number of emails
                    }
                    else {
                        cout << "\nThat email does not exist\n";
                    }
                    break;
                case 8:
                    phones = contact.getPhones();                       //get phone numbers from contact
                    for (int i = 0; i < static_cast<int>(phones.size()); i++) {
                        cout << (i + 1) << " - " << phones[i] << "\n";  //display phone numbers
                    }
                    cout << "\nWhich phone number do you want to delete?: ";
                    cin >> selector;
                    clrIgn();
                    if (selector <= static_cast<int>(phones.size()) && selector > 0) {                  //make sure selected phone number is in range
                        contact.setPhones(deleteFromVector((selector - 1), phones));                    //delete phone number and update the contact
                        contact.phoneNum -= 1;                                                          //subtract 1 from the number of phone numbers
                    }
                    else {
                        cout << "\nThat phone number does not exist\n";
                    }
                    break;
                case 9: {
                    ofstream contactEditWiz(contactPath, fstream::trunc);                               //delete content from contact file
                    contactEditWiz << contact.firstName << "\n";        //add information to contact file
                    contactEditWiz << contact.lastName << "\n";
                    contactEditWiz << contact.emailNum << "\n";
                    contactEditWiz << contact.phoneNum << "\n";
                    emails = contact.getEmails();                       //get emails from contact
                    phones = contact.getPhones();                       //get phone numbers from contact
                    for (int i = 0; i < static_cast<int>(emails.size()); i++) {
                        contactEditWiz << emails[i] << "\n";            //add emails to contact file
                    }
                    for (int i = 0; i < static_cast<int>(phones.size()); i++) {
                        contactEditWiz << phones[i] << "\n";            //add phone numbers to contact file
                    }
                    cout << "\nChanges Saved\n";
                    break;
                }
                case 0:
                    editing = false;
                    cout << "\nClosing menu...\n";
                    break;
            }
        }
    }
    else {
        cout << "\nThat contact does not exist\n";
    }
    wait(1);
}
void contactAddWizard() {
    string first;                       //first name holder
    string last;                        //last name holder
    string emailTemp;                   //temp email holder
    string phoneTemp;                   //temp phone hold
    vector <string> email;              //email holder
    vector <string> phone;              //phone holder
    int emailNum;                       //number of emails
    int phoneNum;                       //number of phones
    breakPage();
    cout << "Please type in a first name: ";
    cin >> first;
    clrIgn();
    cout << "Please type in a last name: ";
    cin >> last;
    clrIgn();
    cout << "\nHow many emails to add?: ";
    cin >> emailNum;
    clrIgn();
    for (int i = 0; i < emailNum; i++) {
        cout << "Please type in an email: ";
        cin >> emailTemp;
        clrIgn();
        email.push_back(emailTemp);
    }
    cout << "\nHow many phone numbers to add?: ";
    cin >> phoneNum;
    clrIgn();
    for (int i = 0; i < phoneNum; i++) {
        cout << "Please type in a phone number: ";
        cin >> phoneTemp;
        clrIgn();
        phone.push_back(phoneTemp);
    }
    con.str("");
    con << "user-" << username << "/" << "entry-" << first << last << ".txt";
    ofstream contactAddWiz(con.str());
    if (contactAddWiz.is_open()) {
        contactAddWiz << first << "\n" << last << "\n";
        contactAddWiz << emailNum << "\n" << phoneNum << "\n";
        for (int i = 0; i < static_cast<int>(email.size()); i++) {
            contactAddWiz << email[i] << "\n";
        }
        for (int i = 0; i < static_cast<int>(phone.size()); i++) {
            contactAddWiz << phone[i] << "\n";
        }
    }
    else {                                                              //if file not opened...
        cout << "\nFatal Error!\n";                                     //...display error message
    }
    contactAddWiz.close();
    con.str("");
    con << "user-" << username << "/@" << username << ".txt";
    contactAddWiz.open(con.str(), ios::app);
    if (contactAddWiz.is_open()) {
        contactAddWiz << first << last << "\n";
        cout << "\nOperation complete\n";
    }
    else {                                                              //if file not opened...
        cout << "\nFatal Error!\n";                                     //...display error message
    }
    contactAddWiz.close();
    wait(1);
}
void contactRemoveWizard() {
    listContacts();
    person contact;                     //holds first and last name of user being deleted
    vector <string> hold;               //holds the open file
    string contactFile;                 //the path of the contact file
    string tempCon;                     //temporary hold for con
    con.str("");
    con << "user-" << username << "/@" << username << ".txt";
    tempCon = con.str();
    hold = saveFile(con.str());                                         //save user file
    hold.erase (hold.begin()+(passLine - 1));                           //remove password from user file
    cout << "Select a contact to remove\n";
    cin >> selector;
    clrIgn();
    if (selector <= static_cast<int>(hold.size()) && selector > 0) {    //make sure selected contact is in range
        con.str("");
        con << "user-" << username << "/entry-" << fromFile((selector + 1), tempCon) << ".txt";
        contactFile = con.str();                                        //make copy of contact file path for later use
        contact.firstName = fromFile(1, con.str());                     //get names from contact file
        contact.lastName = fromFile(2, con.str());
        cout << "\n";
        if (rules.firstNameFirst) {
            cout << "Are you sure you want to remove " << contact.firstName << " " << contact.lastName << " from contacts? (Y/N): ";
        }
        else {
            cout << "Are you sure you want to remove " << contact.lastName << ", " << contact.firstName << " from contacts? (Y/N): ";
        }
        cin >> userYN;
        clrIgn();
        if (userYN == 'Y' || userYN == 'y') {
            hold.erase (hold.begin()+(selector - 1));                   //remove selected contact from user file
            password = fromFile(passLine, tempCon);                     //get user password
            ofstream contactRemoveWiz(tempCon, fstream::trunc);         //open user file and delete all content
            if (contactRemoveWiz.is_open()) {
                contactRemoveWiz << password << "\n";                   //add password
                for (int i = 0; i < static_cast<int>(hold.size()); i++) {
                    contactRemoveWiz << hold[i] << "\n";                //add contacts
                }
            }
            else {                                                      //if file not opened...
                cout << "\nFatal Error!\n";                             //...display error message
            }
            contactRemoveWiz.close();
            con.str("");
            con << "rm " << contactFile;                                //use copy of contact file path
            system(con.str().c_str());                                  //remove contact file
            cout << "\nOperation complete\n";
        }
        else {
            cout << "\nCancelling operation...\n";
        }
    }
    else {
        cout << "\nThat contact does not exist";
    }
    wait(1);
}
