#ifndef IncomiesAndExpensesManager_H//czas na kolejne opcje uzytkownika (bilans z miesiaca) (jeszcze chwile!)
#define IncomiesAndExpensesManager_H//czas sprawdzic czy wszystko dobrze chodzxi i dodac informacje ze dodano nowy wydatek etc
#include <iostream>
#include <vector>
#include <iomanip>

#include "Incomies.h"
#include "Expenses.h"
#include "AuxiliaryMethods.h" //nie wiem czemu, ale bez tego nie dzialaja metody z tej klasy... (w Ksiazce Adresowej dzialalo bez)
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
