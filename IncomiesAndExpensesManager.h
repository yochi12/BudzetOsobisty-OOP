#ifndef IncomiesAndExpensesManager_H
#define IncomiesAndExpensesManager_H
#include <iostream>
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
    bool brakPlatnosci;
    int dataPoczatekPrzedzialu, dataKoniecPrzedzialu;
///sprawdzamy teraz zmienne jako glowne
    vector <Income> incomies; //Income -> klasa, income -> obiekt klasy, incomies -> wektor
    vector <Expense> expenses;

    FileWithIncomies fileWithIncomies;
    FileWithExpenses fileWithExpenses;
    CheckingDate checkingDate;

public:
    IncomiesAndExpensesManager(int loggedInUserId) : LOGGED_IN_USER_ID(loggedInUserId){
        incomies = fileWithIncomies.loadIncomiesFromFileXML(LOGGED_IN_USER_ID);
        expenses = fileWithExpenses.loadExpensesFromFileXML(LOGGED_IN_USER_ID);
        brakPlatnosci = true;
    }


//------------------------przychody------------------------------------------------------------------------------
    void addIncome();                   //"dodajPrzychod"
    Income enterNewIncomeDetails();     //"podajDaneNowegoPrzychodu"
    int getNewIncomieId();              //przypisuje nowe ID do przychodu


//------------------------wydatki------------------------------------------------------------------------------
    void addExpense();                  //"dodajWydatek"
    Expense enterNewExpenseDetails();   //"podajDaneNowegoWydatku"
    int getNewExpenseId();              //przypisuje nowe ID do wydatku


//------------------------bilanse------------------------------------------------------------------------------
    void bilansZJednegoMiesiaca(int dataPierwsza, int drugaData);
    void bilansZWybranegoOkresu(int dataPierwsza, int drugaData);

    void policzBilansDlaPrzychodowZJednegoMiesiaca();
    void policzBilansDlaWydatkowZJednegoMiesiaca();
    void policzBilansDlaPrzychodow(int drugaData);
    void policzBilansDlaWydatkow(int drugaData);

    int przypiszDatyDoZmiennychGlownych(int pierwszaData, int drugaData);
    void posortujWektoryPoDacie();

//------------------------Wyswietlanie-danych------------------------------------------------------------------------------
    void pokazPojedynczyPrzychod(Income income);//tymczasowe
    void pokazPojedynczyWydatek(Expense expense);//tymczasowe
    void wyswietlSumePrzychodowIWydatkow();
    void sprawdzCzyBilansJestPusty();
};

#endif
