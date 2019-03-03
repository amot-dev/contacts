//CLASSES.H v1.0 BY ALEXANDER MOT
//Created 15/04/2017
//Updated 16/04/2017

#ifndef CLASSES_H
#define CLASSES_H

#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include "../../include/IO.h"

extern stringstream con;

class config {
public:
    bool firstNameFirst;                //config rules
    bool emailBeforePhone;
    bool formatPhone;
    char formatPhoneChar;

    string firstNameFirstTemp;          //temp hold for config rules
    string emailBeforePhoneTemp;
    string formatPhoneTemp;
    string formatPhoneCharTemp;

    void loadConfig(string username);
};

class sortCon {
public:
    void organise(string username, int passLine);
private:
    vector <string> hold;               //holds the user file
    string filePath;                    //holds file path of user
    string userPassword;                //holds the user's password
    string setPath(string username);    //sets the path to a user's file
};

class person {
public:
    string firstName;                   //contact's first name
    string lastName;                    //contact's last name
    int emailNum;                       //number of emails
    int phoneNum;                       //number of phone numbers

    void addToEmails(string item);      //adds an item to the email vector
    void addToPhones(string item);      //adds an item to the phone number vector
    void clearVectors();                //clears the vectors
    vector <string> getEmails();        //returns the email vector
    vector <string> getPhones();        //returns the phone number vector
    void setEmails(vector <string> inVec);  //sets the email vector to another vector (good for multiple changes)
    void setPhones(vector <string> inVec);  //sets the phon number vector to another vector

private:
    vector <string> emails;             //holds contact's emails
    vector <string> phones;             //holds contact's phones
    vector <string> organise(vector <string> toOrganise);   //organises a vector in alphabetical order
};

#endif
