#ifndef PersonalBudget_H
#define PersonalBudget_H
#include <iostream>
#include <vector>

#include "User.h"
#include "UserManager.h"
#include "AuxiliaryMethods.h" //nie wiem czemu, ale bez tego nie dzialaja metody z tej klasy... (w Ksiazce Adresowej dzialalo bez)

using namespace std;

class PersonalBudget
{
    UserManager userManager;
    int loggedInUserId;

    vector <User> users;

public:
    char selectOptionFromMainMenu();
    char selectOptionFromUserMenu();
    char loadChar();
    void registerUser(); //dziala, ale jeszcze bez pliku
    void loginUser(); //jeszcze puste

    bool isUserLoggedIn();
    void dodajPrzychod();//puste
    void dodajWydatek();//puste
    void bilansZBiezacegoMiasiaca();//puste
    void bilansZPoprzedniegoMiesiaca();//puste
    void bilansZWybranegoOkresu();//puste
    void zmianaHaslaZalogowanegoUzytkownika();//puste
    void wylogujUzytkownika();//puste


    void pokazWszystkichUzytkownikow(); //tymczasowe, pokazuje wszystkich uzytkownikow
};

#endif
