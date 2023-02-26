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

string CheckingDate::enterCurrentDate(){//"podajAktualnaDate" srednio rozumiem ta funkcje....
    char bufor[64];
    time_t czas;
    time(&czas);
    tm czasTM = *localtime(&czas);

    strftime(bufor, sizeof(bufor), "%Y-%m-%d", &czasTM);
    return bufor;
}

//------------------------Eksperymenty------------------------------------------------------------------------------

string CheckingDate::zwrocPoczatekMiesiacaTM(){
    char bufor[64];
    time_t czas;
    time(&czas);
    tm czasTM = *localtime(&czas);

    czasTM.tm_mday = 1;

    strftime(bufor, sizeof(bufor), "%Y%m%d", &czasTM);
    return bufor;
}

string CheckingDate::zwrocPoczatekPoprzedniegoMiesiacaTM(){
    char bufor[64];
    time_t czas;
    time(&czas);
    tm czasTM = *localtime(&czas);

    if (czasTM.tm_mon == 0) // "0" to styczen
    {
        czasTM.tm_mday = 1;
        czasTM.tm_mon = 11; // "11" to grudzien
        czasTM.tm_year -= 1;
    }else{
        czasTM.tm_mon -= 1;
        czasTM.tm_mday = 1;
    }

    strftime(bufor, sizeof(bufor), "%Y%m%d", &czasTM);
    return bufor;
}

int CheckingDate::zwrocPoczatekNastepnegoMiesiacaTM(string poczatkowaDataString){
    char bufor[64];
    time_t czas;
    time(&czas);
    tm czasTM;

    czasTM.tm_mday = AuxiliaryMethods::convertStringToInt(poczatkowaDataString.substr(6,2)) - 1;
    czasTM.tm_mon = AuxiliaryMethods::convertStringToInt(poczatkowaDataString.substr(4,2)) - 1;
    czasTM.tm_year = AuxiliaryMethods::convertStringToInt(poczatkowaDataString.substr(0,4)) - 1900;

    if (czasTM.tm_mon == 11){ // "0" to styczen
        czasTM.tm_mon = 0; // "11" to grudzien
        czasTM.tm_year += 1;
    }else{
        czasTM.tm_mon += 1;
    }
    czasTM.tm_mday = 1;

    strftime(bufor, sizeof(bufor), "%Y%m%d", &czasTM);

    return AuxiliaryMethods::convertStringToInt(bufor);
}

int CheckingDate::zwrocKoniecMiesiaca(string poczatkowaData){
    string koniecMiesiaca;

    koniecMiesiaca = poczatkowaData.insert(6, "-");
    koniecMiesiaca = koniecMiesiaca.insert(4, "-");

    splitDateIntoIntVariables(koniecMiesiaca);

    return AuxiliaryMethods::convertStringToInt((AuxiliaryMethods::convertIntToString(year) + zwrocDwucyfrowaLiczbe(month) + AuxiliaryMethods::convertIntToString(maxNumberOfDaysInMonth())));
}

string CheckingDate::zwrocDwucyfrowaLiczbe(int miesiacLubDzien){//tymczasowo tutaj, pozniej trafi do pomocniczych lub do menegera
    string miesiacString = AuxiliaryMethods::convertIntToString(miesiacLubDzien);
    miesiacString.length()==1 ? miesiacString = "0" + miesiacString : miesiacString;
    return miesiacString;
}

int CheckingDate::podajDateZeZemiennychInt(){
    string rokString, miesiacString, dzienString;

    rokString = AuxiliaryMethods::convertIntToString(year);
    miesiacString = dwucyfrowyMiesiacLubDzien(month);
    dzienString = dwucyfrowyMiesiacLubDzien(day);

    return AuxiliaryMethods::convertStringToInt(rokString + miesiacString + dzienString);
}

string CheckingDate::dwucyfrowyMiesiacLubDzien(int miesiacLubDzien){//tymczasowo tutaj, pozniej trafi do pomocniczych lub do menegera
    string miesiacString = AuxiliaryMethods::convertIntToString(miesiacLubDzien);
    miesiacString.length()==1 ? miesiacString = "0" + miesiacString : miesiacString;
    return miesiacString;
}


