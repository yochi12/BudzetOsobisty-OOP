#ifndef CheckingDate_H
#define CheckingDate_H
#include <time.h>

#include "AuxiliaryMethods.h"//przydaloby sie tego pozbyc

#include <iostream>

using namespace std;

class CheckingDate
{
    int day, month, year;


    int maxNumberOfDaysInMonth();
    bool isLeapYear();//"czyRokJestPrzestepny"

public:
    CheckingDate(){
        day = 0; month = 0; year = 0;
    };

    void splitDateIntoIntVariables(string dateWithDashes);//"rozdzielDateNaZmienneInt"
    bool isDateCorrect(string dateWithDashes);//"czyDataJestPrawidlowa"
    string enterCurrentDate();

//------------------------Eksperymenty------------------------------------------------------------------------------
    ////////////////Daty (w tym struktury tm)//////////////////////////////////////////////////////////
    string zwrocPoczatekMiesiacaTM();
    string zwrocPoczatekPoprzedniegoMiesiacaTM();
    int zwrocPoczatekNastepnegoMiesiacaTM(string poczatkowaDataString);
    int zwrocKoniecMiesiaca(string koniecMiesiaca);
    string zwrocDwucyfrowaLiczbe(int miesiacLubDzien);//tymczasowo tutaj, idzie pozniej do pomocniczych
    int podajDateZeZemiennychInt();
    string dwucyfrowyMiesiacLubDzien(int miesiacLubDzien);



};

#endif
