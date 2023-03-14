#ifndef IncomiesAndExpensesManager_H
#define IncomiesAndExpensesManager_H///ogarniecie rowniez WYDATKOW do bilansow!
#include <iostream>                 ///do tego trzeba jeszcze na dole pokazac sume przychodow i wydatkow - chyba zrobione
#include <vector>
#include <iomanip>
#include <algorithm>
#include <sstream>

#include "Income.h"
#include "Expense.h"
#include "FileWithIncomies.h"
#include "FileWithExpenses.h"
#include "CheckingDate.h"

using namespace std;

class IncomiesAndExpensesManager
{
    const int LOGGED_IN_USER_ID;
    float sumaWszystkichPrzychodow, sumaWszystkichWydatkow;

    vector <Income> incomies; //Income -> klasa, income -> obiekt klasy, incomies -> wektor
    vector <Expense> expenses;

    FileWithIncomies fileWithIncomies;
    FileWithExpenses fileWithExpenses;
    CheckingDate checkingDate;

public:
    IncomiesAndExpensesManager(int loggedInUserId) : LOGGED_IN_USER_ID(loggedInUserId){
        incomies = fileWithIncomies.loadIncomiesFromFileXML(LOGGED_IN_USER_ID);
        expenses = fileWithExpenses.loadExpensesFromFileXML(LOGGED_IN_USER_ID);
    }


//------------------------przychody------------------------------------------------------------------------------
    void addIncome();                   //"dodajPrzychod"
    Income enterNewIncomeDetails();     //"podajDaneNowegoPrzychodu"
    int getNewIncomieId();              //przypisuje nowe ID do przychodu


//------------------------wydatki------------------------------------------------------------------------------
    void addExpense();                  //"dodajWydatek"
    Expense enterNewExpenseDetails();   //"podajDaneNowegoWydatku"
    int getNewExpenseId();              //przypisuje nowe ID do wydatku


//------------------------dodatkowe------------------------------------------------------------------------------


//------------------------bilanse------------------------------------------------------------------------------
    void bilansZBiezacegoLubPoprzedniegoMiesiaca(int pierwszaData, int drugaData);
    void bilansZWybranegoOkresu(int poczatkowaData, int koncowaData);
    void policzBilansZJednegoMiesiaca(int pierwszaData, int drugaData);
    void policzBilansZJednegoMiesiacaDlaPrzychodu(int pierwszaData, int drugaData);
    void policzBilansZJednegoMiesiacaDlaWydatkow(int pierwszaData, int drugaData);
    void policzBilansDlaPrzychodow(int pierwszaData, int drugaData, int wpisanaDrugaData);
    void policzBilansDlaWydatkow(int pierwszaData, int drugaData, int wpisanaDrugaData);


//------------------------tymczasowe------------------------------------------------------------------------------
    void pokazWszystkiePrzychody();//tymczasowe
    void pokazWszystkiePrzychodyCD(Income income);//tymczasowe
    void pokazWszystkieWydatki();//tymczasowe
    void pokazWszystkieWydatkiCD(Expense expense);//tymczasowe
    void pokazPojedynczyPrzychod(Income income);//tymczasowe
    void pokazPojedynczyWydatek(Expense expense);//tymczasowe


//------------------------puste------------------------------------------------------------------------------


};

#endif
