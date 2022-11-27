#ifndef UserManager_H
#define UserManager_H
#include <iostream>
#include <vector>

#include "FileWithUsers.h"
#include "AuxiliaryMethods.h" //nie wiem czemu, ale bez tego nie dzialaja metody z tej klasy... (w Ksiazce Adresowej dzialalo bez)

using namespace std;

class UserManager
{
    vector <User> users;
    FileWithUsers fileWithUsers;
    int loggedInUserId;

public:
    UserManager(){
        loggedInUserId=0;
        users = fileWithUsers.loadUsersFromFileXML();
    }

    void registerUser();
    void loginUser();
    User getNewUserData();
    int getNewUserId();
    bool isLoginExist(string login);
    int getLoggedInUserId();


//------------------------tymczasowe------------------------------------------------------------------------------
    void pokazWszystkichUzytkownikow();//tymczasowe
    void wyswietlDaneUzytkownikow(User user);//tymczasowe


//------------------------puste------------------------------------------------------------------------------
    void zmianaHaslaZalogowanegoUzytkownika();//puste
    void wylogujUzytkownika();//puste?
};

#endif
