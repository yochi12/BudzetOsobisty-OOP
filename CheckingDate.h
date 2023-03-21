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

//------------------------do bilansow------------------------------------------------------------------------------
    int returnDateWithBeginningOfMonth(int currentDate);
    int returnDateWithBeginningOfPreviousmMonth(int currentDate);
    int returnDateWithBeginningOfNextMonth(int date);
    int returnDateAtEndOfMonth(int date);


//------------------------Funkcje zwiazane z data------------------------------------------------------------------------------
    string enterDate(string dateWithDashes);
};

#endif
