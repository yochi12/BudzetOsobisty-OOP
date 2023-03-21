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
    FileWithIncomies fileWithIncomies;
    FileWithExpenses fileWithExpenses;
    CheckingDate checkingDate;

    const int LOGGED_IN_USER_ID;
    float sumOfAllIncomies, sumOfAllExpenses;
    bool noPayments;
    int dateStartOfRange, dateEndOfRange;//dataKoniecPrzedzialu
    vector <Income> incomies; //Income -> klasa, income -> obiekt klasy, incomies -> wektor
    vector <Expense> expenses;

    int getNewIncomieId();              //przypisuje nowe ID do przychodu
    int getNewExpenseId();              //przypisuje nowe ID do wydatku
    Income enterNewIncomeDetails();     //"podajDaneNowegoPrzychodu"
    Expense enterNewExpenseDetails();   //"podajDaneNowegoWydatku"

    void calculateBalanceForOneMonthsIncomies();//policzBilansDlaPrzychodowZJednegoMiesiaca
    void calculateBalanceForOneMonthsExpenses();
    void calculateBalanceForIncomies(int secondDate);//policzBilansDlaPrzychodow
    void calculateBalanceForExpenses(int secondDate);

    int savesDatesToMainVariables(int firstDate, int secondDate);//zapiszDatyDoZmiennychGlownych
    void sortVectorsByDate();//sortujWektorPoDacie
    void isBalanceEmpty();//sprawdzCzyBilansJestPusty

//------------------------Wyswietlanie_danych------------------------------------------------------------------------------
    void showSingleIncome(Income income);//pokazPojedynczyPrzychod
    void showSingleExpense(Expense expense);
    void showSumOfIncomiesAndExpenses();//wyswietlSumePrzychodowIWydatkow

public:
    IncomiesAndExpensesManager(int loggedInUserId) : LOGGED_IN_USER_ID(loggedInUserId){
        incomies = fileWithIncomies.loadIncomiesFromFileXML(LOGGED_IN_USER_ID);
        expenses = fileWithExpenses.loadExpensesFromFileXML(LOGGED_IN_USER_ID);
        noPayments = true;
    }

//------------------------Przychody_i_Wydatki----------------------------------------------------------------------------
    void addIncome();                   //"dodajPrzychod"
    void addExpense();                  //"dodajWydatek"

//------------------------Bilanse------------------------------------------------------------------------------
    void balanceOfOneMonth(int firstDate, int secondDate);
    void balanceOfSelectedTime(int firstDate, int secondDate);
};

#endif
