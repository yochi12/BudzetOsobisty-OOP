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
int CheckingDate::zwrocDateZPoczatkiemMiesiaca(int aktualnaDataInt){
    string aktualnaData = AuxiliaryMethods::convertIntToString(aktualnaDataInt);
    return AuxiliaryMethods::convertStringToInt(aktualnaData.replace(6, 2, "01"));
}

int CheckingDate::zwrocDateZPoczatkiemPoprzedniegoMiesiaca(int aktualnaDataInt){
    string aktualnaData = AuxiliaryMethods::convertIntToString(aktualnaDataInt);
    string poprzedniMiesiac = AuxiliaryMethods::convertIntToString(AuxiliaryMethods::convertStringToInt(aktualnaData.substr(4, 2)) - 1);
    string poprzedniRok = AuxiliaryMethods::convertIntToString(AuxiliaryMethods::convertStringToInt(aktualnaData.substr(0, 4)) - 1);

    if (poprzedniMiesiac != "0"){   //ten sam rok
        poprzedniMiesiac.length()==1 ? poprzedniMiesiac = "0" + poprzedniMiesiac : poprzedniMiesiac;
        return AuxiliaryMethods::convertStringToInt(aktualnaData.replace(4, 4, poprzedniMiesiac + "01"));
    }else{                          //poprzedni rok
        return AuxiliaryMethods::convertStringToInt(poprzedniRok + "01" + "01");
    }
}

int CheckingDate::zwrocDateZPoczatkiemNastepnegoMiesiaca(int dataInt){
    string data = AuxiliaryMethods::convertIntToString(dataInt);
    string nastepnyMiesiac = AuxiliaryMethods::convertIntToString(AuxiliaryMethods::convertStringToInt(data.substr(4, 2)) + 1);
    string nastepnyRok = AuxiliaryMethods::convertIntToString(AuxiliaryMethods::convertStringToInt(data.substr(0, 4)) + 1);

    if (nastepnyMiesiac != "13"){   //ten sam rok
        nastepnyMiesiac.length()==1 ? nastepnyMiesiac = "0" + nastepnyMiesiac : nastepnyMiesiac;
        return AuxiliaryMethods::convertStringToInt(data.replace(4, 4, nastepnyMiesiac + "01"));
    }else{                          //kolejny rok
        return AuxiliaryMethods::convertStringToInt(nastepnyRok + "01" + "01");
    }
}

int CheckingDate::zwrocDateZKoncemMiesiaca(int poczatkowaDataInt){
    string koniecMiesiaca, poczatkowaData = AuxiliaryMethods::convertIntToString(poczatkowaDataInt);

    koniecMiesiaca = AuxiliaryMethods::dodajKreskiDoDaty(poczatkowaData);
    splitDateIntoIntVariables(koniecMiesiaca);

    return AuxiliaryMethods::convertStringToInt((AuxiliaryMethods::convertIntToString(year) + zwrocDwucyfrowaLiczbe(month) + AuxiliaryMethods::convertIntToString(maxNumberOfDaysInMonth())));
}

string CheckingDate::zwrocDwucyfrowaLiczbe(int miesiacLubDzien){
    string miesiacString = AuxiliaryMethods::convertIntToString(miesiacLubDzien);
    miesiacString.length()==1 ? miesiacString = "0" + miesiacString : miesiacString;
    return miesiacString;
}


//------------------------Funkcje zwiazane z data------------------------------------------------------------------------------
string CheckingDate::enterDate(string dateWithDashes){
    while(true){
        dateWithDashes = AuxiliaryMethods::loadLine();
        if(isDateCorrect(dateWithDashes))
            break;

        else if(dateWithDashes == "d"){
            dateWithDashes = AuxiliaryMethods::dodajKreskiDoDaty(enterCurrentDate());
            cout<<"("<<dateWithDashes<<")"<<endl;
            break;
        }

        cout<<"Data niepoprawna. Podaj date: ";
    }
    return dateWithDashes;
}




