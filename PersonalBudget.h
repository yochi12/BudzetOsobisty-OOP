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
    void zmianaHaslaZalogowanegoUzytkownika();  //pozniej na ang
    bool isUserLoggedIn();
    void logoutUser();//wylogujUzytkownika

    void addIncome();//dodajPrzychod
    void addExpense();//dodajWydatek

//------------------------bilanse------------------------------------------------------------------------------
    void bilansZBiezacegoMiasiaca();            //pozniej na ang
    void bilansZPoprzedniegoMiesiaca();         //pozniej na ang
    void bilansZWybranegoOkresu();              //pozniej na ang
};

#endif
