//CLASSES.CPP v1.0 BY ALEXANDER MOT
//Created 16/04/2017
//Updated 16/04/2017

#include "../include/classes.h"

void config :: loadConfig(string username) {
    con.str("");                                                    //clear con stringstream
    con << "../data/user-" << username << "/format.txt";            //output config filepath to con
    firstNameFirstTemp = fromFile(1, con.str());                    //update config temps
    emailBeforePhoneTemp = fromFile(2, con.str());
    formatPhoneTemp = fromFile(3, con.str());
    formatPhoneCharTemp = fromFile(4, con.str());

    if (firstNameFirstTemp == "True") {
        firstNameFirst = true;                                      //update configs
    }
    else if (firstNameFirstTemp == "False") {
        firstNameFirst = false;
    }

    if (emailBeforePhoneTemp == "True") {
        emailBeforePhone = true;
    }
    else if (emailBeforePhoneTemp == "False") {
        emailBeforePhone = false;
    }

    if (formatPhoneTemp == "True") {
        formatPhone = true;
    }
    else if (formatPhoneTemp == "False") {
        formatPhone = false;
    }

    formatPhoneChar = formatPhoneCharTemp[0];
}

void sortCon :: organise(string username, int passLine) {
    filePath = setPath(username);                                   //get filepath for user file
    userPassword = fromFile(passLine, filePath);                    //get the user's password
    hold = saveFile(filePath);                                      //save the user file
    hold.erase (hold.begin()+(passLine - 1));                       //remove password from user file
    sort(hold.begin(), hold.end());                                 //organise user file
    ofstream organ(filePath, fstream::trunc);
    if (organ.is_open()) {
        organ << userPassword << "\n";                              //put password in user file
        for (int i = 0; i < static_cast<int>(hold.size()); i++) {
            organ << hold[i] << "\n";                               //put contacts in user file
        }
    }
    else {                                                          //if file not opened...
        cout << "\nFatal Error!\n";                                 //...display error message
    }
    organ.close();
}
string sortCon :: setPath(string username) {
    con.str("");
    con << "../data/user-" << username << "/@" << username << ".txt";
    return con.str();
}

void person :: addToEmails(string item) {
    emails.push_back(item);                                         //add item to emails vector
    emails = organise(emails);
}
void person :: addToPhones(string item) {
    phones.push_back(item);                                         //add item to phones vector
    phones = organise(phones);
}
void person :: clearVectors() {
    while (emails.size()) emails.pop_back();                        //clear emails vector
    while (phones.size()) phones.pop_back();                        //clear phones vector
}
vector <string>  person :: getEmails() {
    return emails;
}
vector <string> person :: getPhones() {
    return phones;
}
void person :: setEmails(vector <string> inVec) {
    emails = inVec;
}
void person :: setPhones(vector <string> inVec) {
    phones = inVec;
}

vector <string> person :: organise(vector <string> toOrganise) {
    sort(toOrganise.begin(), toOrganise.end());                     //organise user file
    return toOrganise;
}
