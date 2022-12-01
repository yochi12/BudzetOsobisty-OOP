#ifndef IncomiesAndExpensesManager_H
#define IncomiesAndExpensesManager_H
#include <iostream>
#include <vector>

#include "Incomies.h"
#include "Expenses.h"
#include "AuxiliaryMethods.h" //nie wiem czemu, ale bez tego nie dzialaja metody z tej klasy... (w Ksiazce Adresowej dzialalo bez)
#include "FileWithIncomies.h"
#include "FileWithExpenses.h"
#include "CheckingDate.h"

using namespace std;

class IncomiesAndExpensesManager
{
    vector <Incomies> incomiesV; //IncomiesV -> vector, incomiesC -> class
    vector <Expenses> expensesV;
    FileWithIncomies fileWithIncomies;
    FileWithExpenses fileWithExpenses;
    CheckingDate checkingDate;

    //int loggedInUserId; //przyda sie w sytuacji, kiedy w konstruktorze dostaniemy "idZalogowanegoUzytkownika"

public:
    IncomiesAndExpensesManager()//nie moge wyslac nic do tego konstruktora....
    {
        //loggedInUserId = idZalogowanegoUzytkownika; //<- to trzeba przeslac przez konstruktor, a nie jak teraz przez metody....ghb
        //incomiesV = fileWithIncomies.loadIncomiessFromFileXML();//<- to powinno tu wrocic, ale jest problem z zalogowanym uzytkownikiem....
    };


//------------------------przychody------------------------------------------------------------------------------
    void addIncome(int loggedInUserId); //dodajPrzychod, nie wiem jak przeslac ID zalogowanego uzytkownika z "PersonalBudget", wiec chwilowo kombinuje
    Incomies enterNewIncomeDetails(int loggedInUserId);//"podajDaneNowegoPrzychodu"
    int getNewIncomieId(); //przypisuje nowe ID do przychodu


//------------------------wydatki------------------------------------------------------------------------------
    void addExpense(int loggedInUserId); //dodajWydatek, nie wiem jak przeslac ID zalogowanego uzytkownika z "PersonalBudget", wiec chwilowo kombinuje
    Expenses enterNewExpenseDetails(int loggedInUserId);//"podajDaneNowegoWydatku"
    int getNewExpenseId(); //przypisuje nowe ID do wydatku


//------------------------dodatkowe------------------------------------------------------------------------------
    void enterDate(string dateWithDashes);


//------------------------tymczasowe------------------------------------------------------------------------------
    void pokazWszystkiePrzychody();//tymczasowe
    void pokazWszystkiePrzychodyCD(Incomies incomiesC);//tymczasowe
    void pokazWszystkieWydatki();//tymczasowe
    void pokazWszystkieWydatkiCD(Expenses expensesC);//tymczasowe


//------------------------puste------------------------------------------------------------------------------
    void dodajWydatek();//puste
    void bilansZBiezacegoMiasiaca();//puste
    void bilansZPoprzedniegoMiesiaca();//puste
    void bilansZWybranegoOkresu();//puste
};

#endif
