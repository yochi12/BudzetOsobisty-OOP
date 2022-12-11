#ifndef PersonalBudget_H
#define PersonalBudget_H
#include <iostream>
#include <vector>

#include "User.h"
#include "UserManager.h"
#include "IncomiesAndExpensesManager.h"
#include "AuxiliaryMethods.h" //nie wiem czemu, ale bez tego nie dzialaja metody z tej klasy... (w Ksiazce Adresowej dzialalo bez)

using namespace std;

class PersonalBudget
{
    UserManager userManager;
    IncomiesAndExpensesManager *incomiesAndExpensesManager;

    vector <User> users;

    int tymczasowaZmiennaDoKonstruktora = 1;

public:
    PersonalBudget(){
        incomiesAndExpensesManager = NULL;
    }
    ~PersonalBudget(){
        delete incomiesAndExpensesManager;
        incomiesAndExpensesManager = NULL;
    }


    char selectOptionFromMainMenu();
    char selectOptionFromUserMenu();
    void registerUser();
    void loginUser();

    bool isUserLoggedIn();
    void addIncome();//dodajPrzychod
    void addExpense();//dodajWydatek
    void bilansZBiezacegoMiasiaca();//puste
    void bilansZPoprzedniegoMiesiaca();//puste
    void bilansZWybranegoOkresu();//puste
    void zmianaHaslaZalogowanegoUzytkownika();//puste
    void wylogujUzytkownika();//puste


    void pokazWszystkichUzytkownikow(); //tymczasowe,
};

#endif
