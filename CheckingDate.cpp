#include "CheckingDate.h"

void CheckingDate::splitDateIntoIntVariables(string dateWithDashes){//"rozdzielDateNaZmienneInt"
    string dateElement = "";//"elementDaty"
    int dateElementNumber = 1;//"numerElementuDaty"

    dateWithDashes=dateWithDashes+'-';//dodajemy na koncu dodatkowa kreske do daty, aby petla nizej dzialala bez modyfikacji

    for (int charPosition=0; charPosition<(int)dateWithDashes.length(); charPosition++)
    {
        if(dateWithDashes[charPosition]!='-'){
            dateElement+=dateWithDashes[charPosition];
        }else{
            switch(dateElementNumber){
                case 1:
                    year = atoi(dateElement.c_str());       break;
                case 2:
                    month = atoi(dateElement.c_str());      break;
                case 3:
                    day = atoi(dateElement.c_str());        break;
            }
        dateElement = "";
        dateElementNumber++;
        }
    }
}

bool CheckingDate::isLeapYear(){//"czyRokJestPrzestepny"
	if ((year % 4 == 0 && year % 100 != 0) && (year % 400 == 0))
		return true;
	else
		return false;
}

int CheckingDate::maxNumberOfDaysInMonth(bool leapYear){
    int february=2, juli=7;

	if (month == february)
		return leapYear ? 29 : 28;//"rokPrzestepny"
// jesli "leapYear" to "true" to zwroc "29", jesli nie to "28"
	if (month <= juli)
		return month % 2 == 0 ? 30 : 31;

	return month % 2 == 0 ? 31 : 30;
}

bool CheckingDate::isDateCorrect(string dateWithDashes){//"czyDataJestPrawidlowa"
    splitDateIntoIntVariables(dateWithDashes);
	if (day <= 0 || day > 31 || month <= 0 || month > 12)
		return false;

	int maxNumbersOfDays = maxNumberOfDaysInMonth(isLeapYear());
	return day <= maxNumbersOfDays;
}

string CheckingDate::enterCurrentDate(){//"podajAktualnaDate" srednio rozumiem ta funkcje....
    char bufor[64];
    time_t czas;
    time(&czas);
    tm czasTM = *localtime(&czas);

    strftime(bufor, sizeof(bufor), "%Y-%m-%d", &czasTM);
    return bufor;
}
