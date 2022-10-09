#ifndef UserManager_H
#define UserManager_H
#include <iostream>
#include <vector>

#include "User.h"
#include "AuxiliaryMethods.h" //nie wiem czemu, ale bez tego nie dzialaja metody z tej klasy... (w Ksiazce Adresowej dzialalo bez)

using namespace std;

class UserManager
{
    vector <User> users;

public:
    int loggedInUserId=0;//tymczasowa wartosc

    void registerUser();
    void loginUser();
    User getNewUserData();
    int getNewUserId();
    bool isLoginExist(string login);
    void wyswietlDaneUzytkownikow(User user);
    int getLoggedInUserId();

    void dodajPrzychod();//puste
    void dodajWydatek();//puste
    void bilansZBiezacegoMiasiaca();//puste
    void bilansZPoprzedniegoMiesiaca();//puste
    void bilansZWybranegoOkresu();//puste
    void zmianaHaslaZalogowanegoUzytkownika();//puste
    void wylogujUzytkownika();//puste


    void showAllUsers();
};

#endif
