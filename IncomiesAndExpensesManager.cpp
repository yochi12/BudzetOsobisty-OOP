#include "IncomiesAndExpensesManager.h"

//------------------------przychody------------------------------------------------------------------------------
void IncomiesAndExpensesManager::addIncome(){//"dodajPrzychod"
//pokazWszystkiePrzychody();//tymczasowo
    Incomies incomiesC = enterNewIncomeDetails();//"podajDaneNowegoPrzychodu"
    incomiesV.push_back(incomiesC);
    fileWithIncomies.addIncomiesToFileXML(incomiesC);
    cout<<endl<<"Dodano nowy przychod."<<endl<<endl;
    system("pause");
}

Incomies IncomiesAndExpensesManager::enterNewIncomeDetails(){//"podajDaneNowegoPrzychodu"
    Incomies incomiesC;
    string dateWithDashes;

    incomiesC.setUserId(LOGGED_IN_USER_ID);
    incomiesC.setIncomeId(getNewIncomieId());

    cout<<endl<<"Podaj date w formacie RRRR-MM-DD  (aktualna data -> wcisnij 'd'): "<<endl;
    dateWithDashes = enterDate(dateWithDashes);

    incomiesC.setDate(atoi(AuxiliaryMethods::replaceDateToTextWithoutDashes(dateWithDashes).c_str()));

    cout<<"Podaj przedmiot: ";
    incomiesC.setItem(AuxiliaryMethods::loadLine());

    cout<<"Podaj kwote: ";
    incomiesC.setAmount(atof(loadAmount().c_str()));

    return incomiesC;
}

int IncomiesAndExpensesManager::getNewIncomieId(){
    if (incomiesV.empty() == true)
        return 1;
    else
        return incomiesV.back().getIncomeId() + 1;
}


//------------------------wydatki------------------------------------------------------------------------------
void IncomiesAndExpensesManager::addExpense(){//"dodajWydatek"
//pokazWszystkieWydatki();//tymczasowo
    Expenses expensesC = enterNewExpenseDetails();
    expensesV.push_back(expensesC);
    fileWithExpenses.addExpensesToFileXML(expensesC);
    cout<<endl<<"Dodano nowy wydatek."<<endl<<endl;
    system("pause");
}

Expenses IncomiesAndExpensesManager::enterNewExpenseDetails(){//"podajDaneNowegoWydatku"
    Expenses expensesC;
    string dateWithDashes;

    expensesC.setUserId(LOGGED_IN_USER_ID);
    expensesC.setExpenseId(getNewExpenseId());

    cout<<endl<<"Podaj date w formacie RRRR-MM-DD  (aktualna data -> wcisnij 'd'): "<<endl;
    dateWithDashes = enterDate(dateWithDashes);

    expensesC.setDate(atoi(AuxiliaryMethods::replaceDateToTextWithoutDashes(dateWithDashes).c_str()));

    cout<<"Podaj przedmiot: ";
    expensesC.setItem(AuxiliaryMethods::loadLine());

    cout<<"Podaj kwote: ";
    expensesC.setAmount(atof(loadAmount().c_str()));

    return expensesC;
}

int IncomiesAndExpensesManager::getNewExpenseId(){
    if (expensesV.empty() == true)
        return 1;
    else
        return expensesV.back().getExpenseId() + 1;
}


//------------------------dodatkowe------------------------------------------------------------------------------
string IncomiesAndExpensesManager::enterDate(string dateWithDashes){
    while(true){
        dateWithDashes = AuxiliaryMethods::loadLine();
        if(checkingDate.isDateCorrect(dateWithDashes))
            break;

        else if(dateWithDashes == "d"){
            dateWithDashes = checkingDate.enterCurrentDate();
            cout<<"("<<dateWithDashes<<")"<<endl;
            break;
        }

        cout<<"Data niepoprawna. Podaj date: ";
    }
    return dateWithDashes;
}

string IncomiesAndExpensesManager::loadAmount(){//wczytajKwote
    string cashAmount;
    do{
       cashAmount = convertCommaToDot(AuxiliaryMethods::loadLine());

       if(!checkCashAmountFormat(cashAmount)){
           cout << "Niepoprawna wartosc. Sprobuj ponownie: " << endl;
       }
    }while(!checkCashAmountFormat(cashAmount));

    cashAmount = roundingToTwoDecimalPlaces(cashAmount);
    return cashAmount;
}

string IncomiesAndExpensesManager::convertCommaToDot(string cashAmount){//konwersjaPrzecinkaNaKropke
    replace(cashAmount.begin(), cashAmount.end(), ',', '.');
    return cashAmount;
}

bool IncomiesAndExpensesManager::checkCashAmountFormat(string cashAmount){//sprawdzFormatKwoty
    int numberOfDots = 0;

    numberOfDots = count(cashAmount.begin(), cashAmount.end(), '.');

    if(numberOfDots>1){
        return false;
    }

    for(int i=0; i<(int)cashAmount.length(); i++){
        if(!isdigit(cashAmount[i]) && cashAmount[i] != '.'){
            return false;
        }
    }
    return true;
}

string IncomiesAndExpensesManager::roundingToTwoDecimalPlaces(string cashAmount){//"zaokr¹glanieDoDwóchMiejscPoPrzecinku"
    float cashAmountFloat;

    cashAmountFloat = AuxiliaryMethods::convertStringToFloat(cashAmount);
    cashAmountFloat *= 100;
    cashAmountFloat = floor(cashAmountFloat);
    cashAmountFloat /= 100;

    cashAmount = AuxiliaryMethods::convertFloatToString(cashAmountFloat);
    return cashAmount;
}


//------------------------Eksperymenty------------------------------------------------------------------------------


void IncomiesAndExpensesManager::bilansZBiezacegoMiesiaca(){
    Incomies incomiesC;
    int poczatekMiesiaca, aktualnaData;

    sort(incomiesV.begin(), incomiesV.end( ), [ ](Incomies a, Incomies b)  {return a.getDate() < b.getDate();} ); ///wyrazenie lambda

    poczatekMiesiaca = AuxiliaryMethods::convertStringToInt(checkingDate.zwrocPoczatekMiesiacaTM());//"20230101"
    aktualnaData = AuxiliaryMethods::convertStringToInt(AuxiliaryMethods::replaceDateToTextWithoutDashes(checkingDate.enterCurrentDate()));//np. "20230122"

    cout<<endl<<"Bilans z biezacego miesiaca: "<<endl<<endl;

    for (vector <Incomies> :: iterator itr = incomiesV.begin(); itr != incomiesV.end(); itr++){
        for (int i=poczatekMiesiaca; i<=aktualnaData; i++){
            if(itr -> getDate() == i){
                pokazPojedynczyWydatek(*itr);
            }
        }
    }
    system("pause");
}

void IncomiesAndExpensesManager::bilansZPoprzedniegoMiesiaca(){
    int poczatekPoprzedniegoMiesiaca, koniecPoprzedniegoMiesiaca;

    sort(incomiesV.begin(), incomiesV.end( ), [ ](Incomies a, Incomies b)  {return a.getDate() < b.getDate();} ); ///wyrazenie lambda

    poczatekPoprzedniegoMiesiaca = AuxiliaryMethods::convertStringToInt(checkingDate.zwrocPoczatekPoprzedniegoMiesiacaTM());//20221201
    koniecPoprzedniegoMiesiaca = checkingDate.zwrocKoniecMiesiaca(AuxiliaryMethods::convertIntToString(poczatekPoprzedniegoMiesiaca));

    cout<<endl<<"Bilans z poprzedniego miesiaca: "<<endl<<endl;

    for (vector <Incomies> :: iterator itr = incomiesV.begin(); itr != incomiesV.end(); itr++){
        for (int i=poczatekPoprzedniegoMiesiaca; i<=koniecPoprzedniegoMiesiaca; i++){
            if(itr -> getDate() == i){
                pokazPojedynczyWydatek(*itr);
            }
        }
    }
    system("pause");
}

void IncomiesAndExpensesManager::bilansZWybranegoOkresu(){//funkcja jest dluga i brzydka, ale dziala...
    Incomies incomiesC;
    int poczatkowaData, koncowaData, koniecMiesiaca, koniecPrzedzialu, tymczasowePoczatkowaData, tymczasoweKoniecPrzedzialu, tymczasoweKoniecMiesiaca;
    string wpisanaDataPierwsza, wpisanaDataDruga;

    sort(incomiesV.begin(), incomiesV.end( ), [ ](Incomies a, Incomies b)  {return a.getDate() < b.getDate();} ); ///wyrazenie lambda

    cout<<endl<<"Bilans z wybranego okresu: "<<endl<<endl;

    cout<<"Wprowadz pierwsza date (RRRR-MM-DD): ";   cin>>wpisanaDataPierwsza;
    cout<<"Wprowadz druga date (RRRR-MM-DD): ";   cin>>wpisanaDataDruga;

    //tutaj musimy jeszcze sprawdzic poprawnosc obu dat, oraz dac warunek: wpisanaDataDruga>=wpisanaDataPierwsza

    checkingDate.splitDateIntoIntVariables(wpisanaDataPierwsza);
    poczatkowaData = checkingDate.podajDateZeZemiennychInt();

    koniecMiesiaca = checkingDate.zwrocKoniecMiesiaca(AuxiliaryMethods::convertIntToString(poczatkowaData));

    checkingDate.splitDateIntoIntVariables(wpisanaDataDruga);
    koncowaData = checkingDate.podajDateZeZemiennychInt();

    koncowaData >= koniecMiesiaca ? koniecPrzedzialu = koniecMiesiaca : koniecPrzedzialu = koncowaData;//jesli damy funkcje uniemozliwiajaca wpisanie drugiej daty pozniejszej niz aktualna data, to ta linijka nie bedzie potrzebna

    for (vector <Incomies> :: iterator itr = incomiesV.begin(); itr != incomiesV.end(); itr++){
        tymczasowePoczatkowaData = poczatkowaData;
        tymczasoweKoniecMiesiaca = koniecMiesiaca;
        tymczasoweKoniecPrzedzialu = koniecPrzedzialu;

        for (int i=poczatkowaData; i<=koniecPrzedzialu; i++){
            if(itr -> getDate() == i){
                pokazPojedynczyWydatek(*itr);
            }
            if(i==koniecPrzedzialu && koniecPrzedzialu!=koniecMiesiaca)
                break;
            if(i==koniecPrzedzialu){
                poczatkowaData = checkingDate.zwrocPoczatekNastepnegoMiesiacaTM(AuxiliaryMethods::convertIntToString(poczatkowaData));
                koniecMiesiaca = checkingDate.zwrocKoniecMiesiaca(AuxiliaryMethods::convertIntToString(poczatkowaData));
                koncowaData >= koniecMiesiaca ? koniecPrzedzialu = koniecMiesiaca : koniecPrzedzialu = koncowaData;
                i = poczatkowaData - 1;
            }
        }
        poczatkowaData = tymczasowePoczatkowaData;
        koniecMiesiaca = tymczasoweKoniecMiesiaca;
        koniecPrzedzialu = tymczasoweKoniecPrzedzialu;
    }
    system("pause");
}


//------------------------puste------------------------------------------------------------------------------



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
    cout<<"incomiesC.getAmount(): "<<fixed<<setprecision(2)<<incomiesC.getAmount()<<endl<<endl;//probojemy wyswietlic dwa zera po zlotowkach
}


void IncomiesAndExpensesManager::pokazWszystkieWydatki()//tymczasowe
{
    if (!expensesV.empty()){
        cout << "             >>> Wydatki <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Expenses> :: iterator itr = expensesV.begin(); itr != expensesV.end(); itr++){
            pokazWszystkieWydatkiCD(*itr);
        }
        cout << endl;
    }else{
        cout << endl << "Wydatkow brak." << endl << endl;
    }
    system("pause");
    system("cls");
}

void IncomiesAndExpensesManager::pokazWszystkieWydatkiCD(Expenses expensesC)//tymczasowe
{
    cout<<"expensesC.getUserId(): "<<expensesC.getUserId()<<endl;
    cout<<"expensesC.getExpenseId(): "<<expensesC.getExpenseId()<<endl;
    cout<<"expensesC.getDate(): "<<expensesC.getDate()<<endl;
    cout<<"expensesC.getItem(): "<<expensesC.getItem()<<endl;
    cout<<"expensesC.getAmount(): "<<fixed<<setprecision(2)<<expensesC.getAmount()<<endl<<endl;
}


void IncomiesAndExpensesManager::pokazPojedynczyWydatek(Incomies incomiesC){
    cout<<left;
    cout<<setw(6)<<incomiesC.getUserId();
    cout<<setw(6)<<incomiesC.getIncomeId();
    cout<<setw(13)<<incomiesC.getDate();
    cout<<setw(13)<<incomiesC.getItem();
    cout<<fixed<<setprecision(2)<<incomiesC.getAmount()<<endl;
}

