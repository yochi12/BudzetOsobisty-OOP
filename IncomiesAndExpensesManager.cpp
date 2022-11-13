#include "IncomiesAndExpensesManager.h" //czas na zajecie sie datami (najpierw wczytujemy string, przerabiamy na stringa bez kresek i !do klasy jako int!)

void IncomiesAndExpensesManager::addIncome(int loggedInUserId)//dodajPrzychod
{
    Incomies incomiesC = podajDaneNowegoPrzychodu(loggedInUserId);

    incomiesV.push_back(incomiesC);

    wyswietlDaneZVectora();//tymczasowo
}

Incomies IncomiesAndExpensesManager::podajDaneNowegoPrzychodu(int loggedInUserId)
{
    Incomies incomiesC;
    string dataZKreskami;

    incomiesC.setIncomeId(getNewIncomieId());
    incomiesC.setUserId(loggedInUserId);

    cout<<"Podaj date: ";
    do{
        dataZKreskami = AuxiliaryMethods::loadLine();
        if(!czyDataJestPrawidlowa(dataZKreskami))
            cout<<"Data niepoprawna. Podaj date: ";
    }while(!czyDataJestPrawidlowa(dataZKreskami));

    incomiesC.setDate(atoi(zamienDateNaTekstBezKresek(dataZKreskami).c_str()));

    cout<<"Podaj przedmiot: ";
    incomiesC.setItem(AuxiliaryMethods::loadLine());

    cout<<"Podaj kwote: ";
    incomiesC.setAmount(AuxiliaryMethods::loadLine());

    return incomiesC;
}

int IncomiesAndExpensesManager::getNewIncomieId(){
    if (incomiesV.empty() == true)
        return 1;
    else
        return incomiesV.back().getIncomeId() + 1;
}

//wersja ktora zwroci date bez kresek jako string, oraz zapisze jako "int" wszystkie skladowe daty (przygotuje do sprawdzenia daty)
void IncomiesAndExpensesManager::zamienDateNaZmienneInt(string dataZKreskami){
    string skladowaDaty = "";
    int numerPojedynczejDaty = 1;

    dataZKreskami=dataZKreskami+'-';//dodajemy na koncu dodatkowa kreske do daty, aby petla nizej dzialala bez modyfikacji

    for (int pozycjaZnaku=0; pozycjaZnaku<(int)dataZKreskami.length(); pozycjaZnaku++)
    {
        if(dataZKreskami[pozycjaZnaku]!='-'){
            skladowaDaty+=dataZKreskami[pozycjaZnaku];
        }else{
            switch(numerPojedynczejDaty){
                case 1:
                    rok = atoi(skladowaDaty.c_str());        break;
                case 2:
                    miesiac = atoi(skladowaDaty.c_str());    break;
                case 3:
                    dzien = atoi(skladowaDaty.c_str());      break;
            }
        skladowaDaty = "";
        numerPojedynczejDaty++;
        }
    }
}

//zamienia na tekst bez kresek
string IncomiesAndExpensesManager::zamienDateNaTekstBezKresek(string dataZKreskami){
    string dataBezKresek;
    for (int pozycjaZnaku=0; pozycjaZnaku<(int)dataZKreskami.length(); pozycjaZnaku++)
        if(dataZKreskami[pozycjaZnaku]!='-'){
            dataBezKresek+=dataZKreskami[pozycjaZnaku];
        }
    return dataBezKresek;
}

//-------------sprawdzamy-poprawnosc-daty------------------------------------------------------------------

bool IncomiesAndExpensesManager::czyRokJestPrzestepny(){
	if ((rok % 4 == 0 && rok % 100 != 0) && (rok % 400 == 0))
		return true;
	else
		return false;
}

int IncomiesAndExpensesManager::maksymalnaIloscDniWMiesiacu(bool rokPrzestepny){
    int luty=2, lipiec=7;

	if (miesiac == luty)
		return rokPrzestepny ? 29 : 28;
// jesli "rokPrzestepny" to "true" to zwroc "29", jesli nie to "28"
	if (miesiac <= lipiec)
		return miesiac % 2 == 0 ? 30 : 31;

	return miesiac % 2 == 0 ? 31 : 30;
}

bool IncomiesAndExpensesManager::czyDataJestPrawidlowa(string dataZKreskami){
    zamienDateNaZmienneInt(dataZKreskami);
	if (dzien <= 0 || dzien > 31 || miesiac <= 0 || miesiac > 12)
		return false;

	int maksymalnaIloscDni = maksymalnaIloscDniWMiesiacu(czyRokJestPrzestepny());
	return dzien <= maksymalnaIloscDni;
}

//-------------------------puste----------------------------------------------------------------------------
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
//----------------------------------------------------------------------------------------------------------


void IncomiesAndExpensesManager::wyswietlDaneZVectora()//tymczasowe
{
    if (!incomiesV.empty()){
        cout << "             >>> Przychody <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Incomies> :: iterator itr = incomiesV.begin(); itr != incomiesV.end(); itr++){
            wyswietl(*itr);
        }
        cout << endl;
    }else{
        cout << endl << "Przychodow brak." << endl << endl;
    }
    system("pause");
    system("cls");
}

void IncomiesAndExpensesManager::wyswietl(Incomies incomiesC)//tymczasowe
{
    cout<<"incomiesC.getIncomeId(): "<<incomiesC.getIncomeId()<<endl;
    cout<<"incomiesC.getUserId(): "<<incomiesC.getUserId()<<endl;
    cout<<"incomiesC.getDate(): "<<incomiesC.getDate()<<endl;
    cout<<"incomiesC.getItem(): "<<incomiesC.getItem()<<endl;
    cout<<"incomiesC.getAmount(): "<<incomiesC.getAmount()<<endl<<endl;
}

