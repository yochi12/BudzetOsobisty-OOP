#ifndef PersonalBudget_H
#define PersonalBudget_H
#include <iostream>
#include <vector>

#include "User.h"
#include "UserManager.h"
#include "IncomiesAndExpensesManager.h"
#include "CheckingDate.h"

using namespace std;

class PersonalBudget
{
    UserManager userManager;
    IncomiesAndExpensesManager *incomiesAndExpensesManager;
    CheckingDate checkingDate;  //aby sie tego pozbyc, musimy zrobic w "CheckingDate" wszystkie metody statyczne

    vector <User> users;

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
    void bilansZBiezacegoMiasiaca();
    void bilansZPoprzedniegoMiesiaca();
    void bilansZWybranegoOkresu();
    void zmianaHaslaZalogowanegoUzytkownika();
    void logoutUser();//wylogujUzytkownika


    void pokazWszystkichUzytkownikow(); //tymczasowe,
};

#endif
