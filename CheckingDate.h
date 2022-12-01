#ifndef CheckingDate_H
#define CheckingDate_H

#include <iostream>

using namespace std;

class CheckingDate
{
    int day, month, year;

    void splitDateIntoIntVariables(string dateWithDashes);//"rozdzielDateNaZmienneInt"
    int maxNumberOfDaysInMonth(bool leapYear);
    bool isLeapYear();//"czyRokJestPrzestepny"

public:
    CheckingDate(){
        day = 0; month = 0; year = 0;
    };
    bool isDateCorrect(string dateWithDashes);//czyDataJestPrawidlowa
};

#endif
