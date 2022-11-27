#ifndef IncomiesAndExpensesManager_H
#define IncomiesAndExpensesManager_H
#include <iostream>
#include <vector>

#include "Incomies.h"
#include "AuxiliaryMethods.h" //nie wiem czemu, ale bez tego nie dzialaja metody z tej klasy... (w Ksiazce Adresowej dzialalo bez)
#include "FileWithIncomies.h"

using namespace std;

class IncomiesAndExpensesManager
{
    vector <Incomies> incomiesV; //IncomiesV -> vector, incomiesC -> class
    FileWithIncomies fileWithIncomies;
    int loggedInUserId;
    int day, month, year;

public:
    IncomiesAndExpensesManager()//nie moge wyslac nic do tego konstruktora....
    {
        //loggedInUserId = idZalogowanegoUzytkownika; //<- to trzeba przeslac przez konstruktor, a nie jak teraz przez metody....ghb
        //incomiesV = fileWithIncomies.loadIncomiessFromFileXML();//<- to powinno tu wrocic, ale jest problem z zalogowanym uzytkownikiem....
        day = 0; month = 0; year = 0;
    };

    void addIncome(int loggedInUserId1); //dodajPrzychod, nie wiem jak przeslac ID zalogowanego uzytkownika z "PersonalBudget", wiec chwilowo kombinuje
    Incomies enterNewIncomeDetails(int loggedInUserId);//"podajDaneNowegoPrzychodu"
    int getNewIncomieId(); //przypisuje nowe ID do wydatku
    string replaceDateToTextWithoutDashes(string dateWithDashes);//"zamienDateNaTekstBezKresek"

//------------------------sprawdzanie-daty------------------------------------------------------------------------------
    void splitDateIntoIntVariables(string dateWithDashes);//"rozdzielDateNaZmienneInt"
    bool isDateIsCorrect(string dateWithDashes);//czyDataJestPrawidlowa
    int maxNumberOfDaysInMonth(bool rokPrzestepny);
    bool isLeapYear();//"czyRokJestPrzestepny"


//------------------------tymczasowe------------------------------------------------------------------------------
    void pokazWszystkiePrzychody();//tymczasowe
    void pokazWszystkiePrzychodyCD(Incomies incomiesC);//tymczasowe

//------------------------puste------------------------------------------------------------------------------
    void dodajWydatek();//puste
    void bilansZBiezacegoMiasiaca();//puste
    void bilansZPoprzedniegoMiesiaca();//puste
    void bilansZWybranegoOkresu();//puste
};

#endif
