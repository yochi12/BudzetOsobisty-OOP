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
    CheckingDate checkingDate;

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
    void changePassword();
    bool isUserLoggedIn();
    void logoutUser();//wylogujUzytkownika

    void addIncome();//dodajPrzychod
    void addExpense();//dodajWydatek

//------------------------bilanse------------------------------------------------------------------------------
    void balanceOfCurrentMonth();//bilansZBiezacegoMiasiaca
    void balanceOfPreviousMonth();//bilansZPoprzedniegoMiesiaca
    void balanceOfSelectedTime();//bilansZWybranegoOkresu
};

#endif
