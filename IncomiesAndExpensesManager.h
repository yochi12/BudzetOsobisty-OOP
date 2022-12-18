#ifndef IncomiesAndExpensesManager_H//czas na kolejne opcje uzytkownika (bilans z miesiaca)
#define IncomiesAndExpensesManager_H
#include <iostream>
#include <vector>
#include <iomanip>

#include "Incomies.h"
#include "Expenses.h"
#include "FileWithIncomies.h"
#include "FileWithExpenses.h"
#include "CheckingDate.h"

using namespace std;

class IncomiesAndExpensesManager
{
    const int LOGGED_IN_USER_ID;

    vector <Incomies> incomiesV; //IncomiesV -> vector, incomiesC -> class
    vector <Expenses> expensesV;

    FileWithIncomies fileWithIncomies;
    FileWithExpenses fileWithExpenses;
    CheckingDate checkingDate;

public:
    IncomiesAndExpensesManager(int loggedInUserId) : LOGGED_IN_USER_ID(loggedInUserId){
        incomiesV = fileWithIncomies.loadIncomiesFromFileXML(LOGGED_IN_USER_ID);
        expensesV = fileWithExpenses.loadExpensesFromFileXML(LOGGED_IN_USER_ID);
    }


//------------------------przychody------------------------------------------------------------------------------
    void addIncome();                   //"dodajPrzychod"
    Incomies enterNewIncomeDetails();   //"podajDaneNowegoPrzychodu"
    int getNewIncomieId();              //przypisuje nowe ID do przychodu


//------------------------wydatki------------------------------------------------------------------------------
    void addExpense();                  //"dodajWydatek"
    Expenses enterNewExpenseDetails();  //"podajDaneNowegoWydatku"
    int getNewExpenseId();              //przypisuje nowe ID do wydatku


//------------------------dodatkowe------------------------------------------------------------------------------
    string enterDate(string dateWithDashes);
    string loadAmount();


//------------------------tymczasowe------------------------------------------------------------------------------
    void pokazWszystkiePrzychody();//tymczasowe
    void pokazWszystkiePrzychodyCD(Incomies incomiesC);//tymczasowe
    void pokazWszystkieWydatki();//tymczasowe
    void pokazWszystkieWydatkiCD(Expenses expensesC);//tymczasowe


//------------------------puste------------------------------------------------------------------------------
    void bilansZBiezacegoMiasiaca();//puste
    void bilansZPoprzedniegoMiesiaca();//puste
    void bilansZWybranegoOkresu();//puste
};

#endif
