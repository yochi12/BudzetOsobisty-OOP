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

int CheckingDate::maxNumberOfDaysInMonth(){
    int february = 2, juli = 7;
    bool leapYear = isLeapYear();

	if (month == february)
		return leapYear ? 29 : 28;//"rokPrzestepny"
// jesli "leapYear" to "true" to zwroc "29", jesli nie to "28"
	if (month <= juli)
		return month % 2 == 0 ? 30 : 31;

	return month % 2 == 0 ? 31 : 30;
}

bool CheckingDate::isDateCorrect(string dateWithDashes){//"czyDataJestPrawidlowa"
    splitDateIntoIntVariables(dateWithDashes);
	if (day <= 0 || day > 31 || month <= 0 || month > 12 || year < 2000)//warunek do spelnienia = data nie mniejsza niz 2000-01-01
		return false;

	int maxNumbersOfDays = maxNumberOfDaysInMonth();
	return day <= maxNumbersOfDays;
}

string CheckingDate::enterCurrentDate(){//"podajAktualnaDate"
    char bufor[64];
    time_t czas;
    time(&czas);
    tm czasTM = *localtime(&czas);

    strftime(bufor, sizeof(bufor), "%Y%m%d", &czasTM);
    return bufor;
}

//------------------------Bilanse------------------------------------------------------------------------------
int CheckingDate::returnDateWithBeginningOfMonth(int currentDate){
    string currentDateStr = AuxiliaryMethods::convertIntToString(currentDate);
    return AuxiliaryMethods::convertStringToInt(currentDateStr.replace(6, 2, "01"));
}

int CheckingDate::returnDateWithBeginningOfPreviousmMonth(int currentDate){//zwrocDateZPoczatkiemPoprzedniegoMiesiaca
    string currentDateStr = AuxiliaryMethods::convertIntToString(currentDate);
    string previousMonth = AuxiliaryMethods::convertIntToString(AuxiliaryMethods::convertStringToInt(currentDateStr.substr(4, 2)) - 1);
    string previousYear = AuxiliaryMethods::convertIntToString(AuxiliaryMethods::convertStringToInt(currentDateStr.substr(0, 4)) - 1);

    if (previousMonth != "0"){
        previousMonth.length()==1 ? previousMonth = "0" + previousMonth : previousMonth;
        return AuxiliaryMethods::convertStringToInt(currentDateStr.replace(4, 4, previousMonth + "01"));
    }else{
        return AuxiliaryMethods::convertStringToInt(previousYear + "01" + "01");
    }
}

int CheckingDate::returnDateWithBeginningOfNextMonth(int date){
    string dateStr = AuxiliaryMethods::convertIntToString(date);
    string nextMonth = AuxiliaryMethods::convertIntToString(AuxiliaryMethods::convertStringToInt(dateStr.substr(4, 2)) + 1);
    string nextYear = AuxiliaryMethods::convertIntToString(AuxiliaryMethods::convertStringToInt(dateStr.substr(0, 4)) + 1);

    if (nextMonth != "13"){
        nextMonth.length()==1 ? nextMonth = "0" + nextMonth : nextMonth;
        return AuxiliaryMethods::convertStringToInt(dateStr.replace(4, 4, nextMonth + "01"));
    }else{
        return AuxiliaryMethods::convertStringToInt(nextYear + "01" + "01");
    }
}

int CheckingDate::returnDateAtEndOfMonth(int date){
    string endOfMonth, startDate = AuxiliaryMethods::convertIntToString(date);

    endOfMonth = AuxiliaryMethods::addDashesToDate(startDate);
    splitDateIntoIntVariables(endOfMonth);

    return AuxiliaryMethods::convertStringToInt((AuxiliaryMethods::convertIntToString(year) + AuxiliaryMethods::returnTwoDigitNumber(month) + AuxiliaryMethods::convertIntToString(maxNumberOfDaysInMonth())));
}

//------------------------Funkcje zwiazane z data------------------------------------------------------------------------------
string CheckingDate::enterDate(string dateWithDashes){
    while(true){
        dateWithDashes = AuxiliaryMethods::loadLine();
        if(isDateCorrect(dateWithDashes))
            break;
        else if(dateWithDashes == "d"){
            dateWithDashes = AuxiliaryMethods::addDashesToDate(enterCurrentDate());
            cout<<"(Aktualna data: "<<dateWithDashes<<")"<<endl<<endl;
            break;
        }
        cout<<"Data niepoprawna. Podaj date: ";
    }
    return dateWithDashes;
}




