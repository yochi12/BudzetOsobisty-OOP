#include "IncomiesAndExpensesManager.h"//trzeba zmienic nazwy, wszystko to przychody!! i ogarnac temat tego konstruktora

void IncomiesAndExpensesManager::addIncome(int loggedInUserId)//"dodajPrzychod"
{incomiesV = fileWithIncomies.loadIncomiessFromFileXML(loggedInUserId);//powinno byc w konstruktorze, ale tam nie ma "loggedInUserId"
//pokazWszystkiePrzychody();//tymczasowo
    Incomies incomiesC = enterNewIncomeDetails(loggedInUserId);//"podajDaneNowegoPrzychodu"

    incomiesV.push_back(incomiesC);

    fileWithIncomies.addIncomiesToFileXML(incomiesC);
}

Incomies IncomiesAndExpensesManager::enterNewIncomeDetails(int loggedInUserId)//"podajDaneNowegoPrzychodu"
{
    Incomies incomiesC;
    string dateWithDashes;//"dataZKreskami"

    incomiesC.setUserId(loggedInUserId);
    incomiesC.setIncomeId(getNewIncomieId());

    cout<<"Podaj date: ";
    while(true){
        dateWithDashes = AuxiliaryMethods::loadLine();
        if(isDateIsCorrect(dateWithDashes))
            break;
        cout<<"Data niepoprawna. Podaj date: ";
    }

    incomiesC.setDate(atoi(replaceDateToTextWithoutDashes(dateWithDashes).c_str()));

    cout<<"Podaj przedmiot: ";
    incomiesC.setItem(AuxiliaryMethods::loadLine());

    cout<<"Podaj kwote: ";
    incomiesC.setAmount(AuxiliaryMethods::loadInteger());

    return incomiesC;
}

int IncomiesAndExpensesManager::getNewIncomieId(){
    if (incomiesV.empty() == true)
        return 1;
    else
        return incomiesV.back().getIncomeId() + 1;
}

//zamiana daty z kreskami na date bez kresek
string IncomiesAndExpensesManager::replaceDateToTextWithoutDashes(string dateWithDashes){//"zamienDateNaTekstBezKresek"
    string dateWithoutDashes;//"dataBezKresek"
    for (int charPosition=0; charPosition<(int)dateWithDashes.length(); charPosition++)
        if(dateWithDashes[charPosition]!='-'){
            dateWithoutDashes+=dateWithDashes[charPosition];
        }
    return dateWithoutDashes;
}


//------------------------sprawdzanie-daty------------------------------------------------------------------------------
//zapisze jako "int" wszystkie skladowe daty (przygotuje do sprawdzenia daty)
void IncomiesAndExpensesManager::splitDateIntoIntVariables(string dateWithDashes){//"rozdzielDateNaZmienneInt"
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

bool IncomiesAndExpensesManager::isLeapYear(){//"czyRokJestPrzestepny"
	if ((year % 4 == 0 && year % 100 != 0) && (year % 400 == 0))
		return true;
	else
		return false;
}

int IncomiesAndExpensesManager::maxNumberOfDaysInMonth(bool leapYear){
    int february=2, juli=7;

	if (month == february)
		return leapYear ? 29 : 28;//"rokPrzestepny"
// jesli "leapYear" to "true" to zwroc "29", jesli nie to "28"
	if (month <= juli)
		return month % 2 == 0 ? 30 : 31;

	return month % 2 == 0 ? 31 : 30;
}

bool IncomiesAndExpensesManager::isDateIsCorrect(string dateWithDashes){//"czyDataJestPrawidlowa"
    splitDateIntoIntVariables(dateWithDashes);
	if (day <= 0 || day > 31 || month <= 0 || month > 12)
		return false;

	int maxNumbersOfDays = maxNumberOfDaysInMonth(isLeapYear());
	return day <= maxNumbersOfDays;
}


//------------------------puste------------------------------------------------------------------------------
void IncomiesAndExpensesManager::dodajWydatek()//puste
{
    cout<<"dodajWydatek:"<<endl;   system("pause");
}

void IncomiesAndExpensesManager::bilansZBiezacegoMiasiaca()//puste
{
    cout<<"bilansZBiezacegoMiasiaca:"<<endl;   system("pause");
}

void IncomiesAndExpensesManager::bilansZPoprzedniegoMiesiaca()//puste
{
    cout<<"bilansZPoprzedniegoMiesiaca:"<<endl;   system("pause");
}

void IncomiesAndExpensesManager::bilansZWybranegoOkresu()//puste
{
    cout<<"bilansZWybranegoOkresu:"<<endl;   system("pause");
}


//------------------------tymczasowe------------------------------------------------------------------------------
void IncomiesAndExpensesManager::pokazWszystkiePrzychody()//tymczasowe
{
    if (!incomiesV.empty()){
        cout << "             >>> Przychody <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Incomies> :: iterator itr = incomiesV.begin(); itr != incomiesV.end(); itr++){
            pokazWszystkiePrzychodyCD(*itr);
        }
        cout << endl;
    }else{
        cout << endl << "Przychodow brak." << endl << endl;
    }
    system("pause");
    system("cls");
}

void IncomiesAndExpensesManager::pokazWszystkiePrzychodyCD(Incomies incomiesC)//tymczasowe
{
    cout<<"incomiesC.getUserId(): "<<incomiesC.getUserId()<<endl;
    cout<<"incomiesC.getIncomeId(): "<<incomiesC.getIncomeId()<<endl;
    cout<<"incomiesC.getDate(): "<<incomiesC.getDate()<<endl;
    cout<<"incomiesC.getItem(): "<<incomiesC.getItem()<<endl;
    cout<<"incomiesC.getAmount(): "<<incomiesC.getAmount()<<endl<<endl;
}

