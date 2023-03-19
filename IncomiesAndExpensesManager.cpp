#include "IncomiesAndExpensesManager.h"

//------------------------przychody------------------------------------------------------------------------------
void IncomiesAndExpensesManager::addIncome(){//"dodajPrzychod"
    Income income = enterNewIncomeDetails();//"podajDaneNowegoPrzychodu"
    incomies.push_back(income);
    fileWithIncomies.addIncomiesToFileXML(income);
    cout<<endl<<"Dodano nowy przychod."<<endl<<endl;
    system("pause");
}

Income IncomiesAndExpensesManager::enterNewIncomeDetails(){//"podajDaneNowegoPrzychodu"
    Income income;
    string dateWithDashes;

    income.setUserId(LOGGED_IN_USER_ID);
    income.setIncomeId(getNewIncomieId());

    cout<<endl<<"Podaj date w formacie RRRR-MM-DD  (aktualna data -> wcisnij 'd'): ";
    dateWithDashes = checkingDate.enterDate(dateWithDashes);

    income.setDate(atoi(AuxiliaryMethods::replaceDateToTextWithoutDashes(dateWithDashes).c_str()));

    cout<<"Podaj przedmiot: ";
    income.setItem(AuxiliaryMethods::loadLine());

    cout<<"Podaj kwote: ";
    income.setAmount(atof(AuxiliaryMethods::loadAmount().c_str()));

    return income;
}

int IncomiesAndExpensesManager::getNewIncomieId(){
        return fileWithIncomies.loadLastIncomeID() + 1;
}


//------------------------wydatki------------------------------------------------------------------------------
void IncomiesAndExpensesManager::addExpense(){//"dodajWydatek"
    Expense expense = enterNewExpenseDetails();
    expenses.push_back(expense);
    fileWithExpenses.addExpensesToFileXML(expense);
    cout<<endl<<"Dodano nowy wydatek."<<endl<<endl;
    system("pause");
}

Expense IncomiesAndExpensesManager::enterNewExpenseDetails(){//"podajDaneNowegoWydatku"
    Expense expense;
    string dateWithDashes;

    expense.setUserId(LOGGED_IN_USER_ID);
    expense.setExpenseId(getNewExpenseId());

    cout<<endl<<"Podaj date w formacie RRRR-MM-DD  (aktualna data -> wcisnij 'd'): ";
    dateWithDashes = checkingDate.enterDate(dateWithDashes);

    expense.setDate(atoi(AuxiliaryMethods::replaceDateToTextWithoutDashes(dateWithDashes).c_str()));

    cout<<"Podaj przedmiot: ";
    expense.setItem(AuxiliaryMethods::loadLine());

    cout<<"Podaj kwote: ";
    expense.setAmount(atof(AuxiliaryMethods::loadAmount().c_str()));

    return expense;
}

int IncomiesAndExpensesManager::getNewExpenseId(){
    return fileWithExpenses.loadLastExpenseID() + 1;
}


//------------------------bilanse------------------------------------------------------------------------------
void IncomiesAndExpensesManager::bilansZJednegoMiesiaca(int pierwszaData, int drugaData){///moze zrobic pierwsza i druga date jako glowne? chyba sie nie da przez przesylanie argumentow od innej klasy...
    przypiszDatyDoZmiennychGlownych(pierwszaData, drugaData);
    posortujWektoryPoDacie();

    cout << "             >>> Przychody <<<" << endl;
    cout << "-----------------------------------------------" << endl;
    policzBilansDlaPrzychodowZJednegoMiesiaca();
    sprawdzCzyBilansJestPusty();

    cout << "             >>> Wydatki <<<" << endl;
    cout << "-----------------------------------------------" << endl;
    policzBilansDlaWydatkowZJednegoMiesiaca();
    sprawdzCzyBilansJestPusty();

    wyswietlSumePrzychodowIWydatkow();

    system("pause");
}

void IncomiesAndExpensesManager::bilansZWybranegoOkresu(int pierwszaData, int drugaData){
    przypiszDatyDoZmiennychGlownych(pierwszaData, drugaData);
    posortujWektoryPoDacie();

    cout << "             >>> Przychody <<<" << endl;
    cout << "-----------------------------------------------" << endl;
    policzBilansDlaPrzychodow(drugaData);
    sprawdzCzyBilansJestPusty();

    przypiszDatyDoZmiennychGlownych(pierwszaData, drugaData);

    cout << "             >>> Wydatki <<<" << endl;
    cout << "-----------------------------------------------" << endl;
    policzBilansDlaWydatkow(drugaData);
    sprawdzCzyBilansJestPusty();

    wyswietlSumePrzychodowIWydatkow();

    system("pause");
}///sprawdzamy teraz zmienne jako glowne

void IncomiesAndExpensesManager::policzBilansDlaPrzychodow(int drugaData){
    do{
        policzBilansDlaPrzychodowZJednegoMiesiaca();

        dataPoczatekPrzedzialu = checkingDate.zwrocDateZPoczatkiemNastepnegoMiesiaca(dataPoczatekPrzedzialu);
        dataKoniecPrzedzialu = checkingDate.zwrocDateZKoncemMiesiaca(dataPoczatekPrzedzialu);
        dataKoniecPrzedzialu < drugaData ? dataKoniecPrzedzialu : dataKoniecPrzedzialu = drugaData;
    }while(dataPoczatekPrzedzialu < drugaData);
}

void IncomiesAndExpensesManager::policzBilansDlaWydatkow(int drugaData){
    do{
        policzBilansDlaWydatkowZJednegoMiesiaca();

        dataPoczatekPrzedzialu = checkingDate.zwrocDateZPoczatkiemNastepnegoMiesiaca(dataPoczatekPrzedzialu);
        dataKoniecPrzedzialu = checkingDate.zwrocDateZKoncemMiesiaca(dataPoczatekPrzedzialu);
        dataKoniecPrzedzialu < drugaData ? dataKoniecPrzedzialu : dataKoniecPrzedzialu = drugaData;
    }while(dataPoczatekPrzedzialu < drugaData);                                             ///trzeba sprawdzic czy ten warunek jest dobry
}

void IncomiesAndExpensesManager::policzBilansDlaPrzychodowZJednegoMiesiaca(){
    for (vector <Income> :: iterator itr = incomies.begin(); itr != incomies.end(); itr++){
        for (int i=dataPoczatekPrzedzialu; i<=dataKoniecPrzedzialu; i++){
            if(itr -> getDate() == i){
                pokazPojedynczyPrzychod(*itr);
                sumaWszystkichPrzychodow += itr -> getAmount();
                brakPlatnosci = false;
            }
        }
    }
}

void IncomiesAndExpensesManager::policzBilansDlaWydatkowZJednegoMiesiaca(){
    for (vector <Expense> :: iterator itr = expenses.begin(); itr != expenses.end(); itr++){
        for (int i=dataPoczatekPrzedzialu; i<=dataKoniecPrzedzialu; i++){
            if(itr -> getDate() == i){
                pokazPojedynczyWydatek(*itr);
                sumaWszystkichWydatkow += itr -> getAmount();
                brakPlatnosci = false;
            }
        }
    }
}

int IncomiesAndExpensesManager::przypiszDatyDoZmiennychGlownych(int pierwszaData, int drugaData){
    int dataZKoncemMiesiaca = checkingDate.zwrocDateZKoncemMiesiaca(pierwszaData);
    dataPoczatekPrzedzialu = pierwszaData;
    drugaData >= dataZKoncemMiesiaca ? dataKoniecPrzedzialu = dataZKoncemMiesiaca : dataKoniecPrzedzialu = drugaData;

    return dataZKoncemMiesiaca;
}

void IncomiesAndExpensesManager::posortujWektoryPoDacie(){
    sort(incomies.begin(), incomies.end( ), [ ](Income a, Income b)  {return a.getDate() < b.getDate();} ); //wyrazenie lambda
    sort(expenses.begin(), expenses.end( ), [ ](Expense a, Expense b)  {return a.getDate() < b.getDate();} );
}


//------------------------Wyswietlanie-danych------------------------------------------------------------------------------
void IncomiesAndExpensesManager::pokazPojedynczyPrzychod(Income income){
    cout<<left;
    cout<<setw(13)<<"  Data:"<<AuxiliaryMethods::dodajKreskiDoDaty(AuxiliaryMethods::convertIntToString(income.getDate()))<<endl;
    cout<<setw(13)<<"  Przedmiot:"<<income.getItem()<<endl;
    cout<<setw(13)<<"  Kwota:"<<fixed<<setprecision(2)<<income.getAmount()<<endl<<endl;
}

void IncomiesAndExpensesManager::pokazPojedynczyWydatek(Expense expense){
    cout<<left;
    cout<<setw(13)<<"  Data:"<<AuxiliaryMethods::dodajKreskiDoDaty(AuxiliaryMethods::convertIntToString(expense.getDate()))<<endl;
    cout<<setw(13)<<"  Przedmiot:"<<expense.getItem()<<endl;
    cout<<setw(13)<<"  Kwota:"<<fixed<<setprecision(2)<<expense.getAmount()<<endl<<endl;
}

void IncomiesAndExpensesManager::sprawdzCzyBilansJestPusty(){
    if(brakPlatnosci == true)
        cout<<"Brak platnosci w tym okresie."<<endl<<endl;
    brakPlatnosci = true;
}

void IncomiesAndExpensesManager::wyswietlSumePrzychodowIWydatkow(){
    cout<<endl<<"Calkowite przychody: "<<fixed<<setprecision(2)<<sumaWszystkichPrzychodow<<endl;    sumaWszystkichPrzychodow = 0;
    cout<<"Calkowite wydatki: "<<fixed<<setprecision(2)<<sumaWszystkichWydatkow<<endl<<endl;    sumaWszystkichWydatkow = 0;
}

