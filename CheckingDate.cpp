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

    strftime(bufor, sizeof(bufor), "%Y-%m-%d", &czasTM);
    return bufor;
}

//------------------------Bilanse------------------------------------------------------------------------------
string CheckingDate::zwrocDateZPoczatkiemMiesiaca(){
    string dataZPoczatiemMiesiaca, aktualnaData = enterCurrentDate(); //np. 2023-03-05
    aktualnaData = AuxiliaryMethods::replaceDateToTextWithoutDashes(aktualnaData);//2023-03-05 - >20230305
    return dataZPoczatiemMiesiaca = aktualnaData.replace(6, 2, "01");//20230305 -> 20230301
}

string CheckingDate::zwrocDateZPoczatkiemPoprzedniegoMiesiaca(){
    string dataZPoczatiemPoprzedniegoMiesiaca, poprzedniMiesiac, poprzedniRok, aktualnaData = enterCurrentDate();

    aktualnaData = AuxiliaryMethods::replaceDateToTextWithoutDashes(aktualnaData);

    poprzedniMiesiac = AuxiliaryMethods::convertIntToString(AuxiliaryMethods::convertStringToInt(aktualnaData.substr(4, 2)) - 1);
    poprzedniRok = AuxiliaryMethods::convertIntToString(AuxiliaryMethods::convertStringToInt(aktualnaData.substr(0, 4)) - 1);

    if (poprzedniMiesiac != "0"){ //ten sam rok
        poprzedniMiesiac.length()==1 ? poprzedniMiesiac = "0" + poprzedniMiesiac : poprzedniMiesiac;
        dataZPoczatiemPoprzedniegoMiesiaca = aktualnaData.replace(4, 2, poprzedniMiesiac);
    }else{ //kolejny rok
        dataZPoczatiemPoprzedniegoMiesiaca = poprzedniRok + "01";
    }

    return dataZPoczatiemPoprzedniegoMiesiaca.replace(6, 2, "01");
}

int CheckingDate::zwrocDateZPoczatkiemNastepnegoMiesiaca(string poczatkowaDataString){
    string dataZPoczatiemNastepnegoMiesiaca, nastepnyMiesiac, nastepnyRok, aktualnaData = enterCurrentDate(); //np. 2023-03-05

    aktualnaData = AuxiliaryMethods::replaceDateToTextWithoutDashes(aktualnaData);//2023-03-05 - >20230305

    nastepnyMiesiac = AuxiliaryMethods::convertIntToString(AuxiliaryMethods::convertStringToInt(aktualnaData.substr(4, 2)) + 1);
    nastepnyRok = AuxiliaryMethods::convertIntToString(AuxiliaryMethods::convertStringToInt(aktualnaData.substr(0, 4)) + 1);

    if (nastepnyMiesiac != "13"){ //ten sam rok
        nastepnyMiesiac.length()==1 ? nastepnyMiesiac = "0" + nastepnyMiesiac : nastepnyMiesiac;
        dataZPoczatiemNastepnegoMiesiaca = aktualnaData.replace(4, 2, nastepnyMiesiac);
    }else{ //kolejny rok
        dataZPoczatiemNastepnegoMiesiaca = nastepnyRok + "01";
    }
    return AuxiliaryMethods::convertStringToInt(dataZPoczatiemNastepnegoMiesiaca.replace(6, 2, "01"));
}

int CheckingDate::zwrocDateZKoncemMiesiaca(string poczatkowaData){
    string koniecMiesiaca;

    koniecMiesiaca = poczatkowaData.insert(6, "-");
    koniecMiesiaca = koniecMiesiaca.insert(4, "-");

    splitDateIntoIntVariables(koniecMiesiaca);

    return AuxiliaryMethods::convertStringToInt((AuxiliaryMethods::convertIntToString(year) + zwrocDwucyfrowaLiczbe(month) + AuxiliaryMethods::convertIntToString(maxNumberOfDaysInMonth())));
}

string CheckingDate::zwrocDwucyfrowaLiczbe(int miesiacLubDzien){
    string miesiacString = AuxiliaryMethods::convertIntToString(miesiacLubDzien);
    miesiacString.length()==1 ? miesiacString = "0" + miesiacString : miesiacString;
    return miesiacString;
}

int CheckingDate::zwrocDateZeZemiennychGlobalnych(){
    string rokString, miesiacString, dzienString;

    rokString = AuxiliaryMethods::convertIntToString(year);
    miesiacString = dwucyfrowyMiesiacLubDzien(month);
    dzienString = dwucyfrowyMiesiacLubDzien(day);

    return AuxiliaryMethods::convertStringToInt(rokString + miesiacString + dzienString);
}

string CheckingDate::dwucyfrowyMiesiacLubDzien(int miesiacLubDzien){
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
            dateWithDashes = enterCurrentDate();
            cout<<"("<<dateWithDashes<<")"<<endl;
            break;
        }

        cout<<"Data niepoprawna. Podaj date: ";
    }
    return dateWithDashes;
}



