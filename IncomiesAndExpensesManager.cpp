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

    cout<<endl<<"Podaj date w formacie RRRR-MM-DD  (aktualna data -> wcisnij 'd'): "<<endl;
    dateWithDashes = checkingDate.enterDate(dateWithDashes);

    income.setDate(atoi(AuxiliaryMethods::replaceDateToTextWithoutDashes(dateWithDashes).c_str()));

    cout<<"Podaj przedmiot: ";
    income.setItem(AuxiliaryMethods::loadLine());

    cout<<"Podaj kwote: ";
    income.setAmount(atof(AuxiliaryMethods::loadAmount().c_str()));

    return income;
}

int IncomiesAndExpensesManager::getNewIncomieId(){
    if (incomies.empty() == true)
        return 1;
    else
        return incomies.back().getIncomeId() + 1;
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

    cout<<endl<<"Podaj date w formacie RRRR-MM-DD  (aktualna data -> wcisnij 'd'): "<<endl;
    dateWithDashes = checkingDate.enterDate(dateWithDashes);

    expense.setDate(atoi(AuxiliaryMethods::replaceDateToTextWithoutDashes(dateWithDashes).c_str()));

    cout<<"Podaj przedmiot: ";
    expense.setItem(AuxiliaryMethods::loadLine());

    cout<<"Podaj kwote: ";
    expense.setAmount(atof(AuxiliaryMethods::loadAmount().c_str()));

    return expense;
}

int IncomiesAndExpensesManager::getNewExpenseId(){
    if (expenses.empty() == true)
        return 1;
    else
        return expenses.back().getExpenseId() + 1;
}


//------------------------dodatkowe------------------------------------------------------------------------------


//------------------------bilanse------------------------------------------------------------------------------
void IncomiesAndExpensesManager::bilansZBiezacegoMiesiaca(){
    int poczatekMiesiaca, aktualnaData;

    sort(incomies.begin(), incomies.end( ), [ ](Income a, Income b)  {return a.getDate() < b.getDate();} ); //wyrazenie lambda

    poczatekMiesiaca = AuxiliaryMethods::convertStringToInt(checkingDate.zwrocDateZPoczatkiemMiesiaca());
    aktualnaData = AuxiliaryMethods::convertStringToInt(AuxiliaryMethods::replaceDateToTextWithoutDashes(checkingDate.enterCurrentDate()));

    cout<<endl<<"Bilans z biezacego miesiaca: "<<endl<<endl;

    for (vector <Income> :: iterator itr = incomies.begin(); itr != incomies.end(); itr++){
        for (int i=poczatekMiesiaca; i<=aktualnaData; i++){
            if(itr -> getDate() == i){
                pokazPojedynczyPrzychod(*itr);
            }
        }
    }
    system("pause");
}

void IncomiesAndExpensesManager::bilansZPoprzedniegoMiesiaca(){
    int poczatekPoprzedniegoMiesiaca, koniecPoprzedniegoMiesiaca;

    sort(incomies.begin(), incomies.end( ), [ ](Income a, Income b)  {return a.getDate() < b.getDate();} ); //wyrazenie lambda

    poczatekPoprzedniegoMiesiaca = AuxiliaryMethods::convertStringToInt(checkingDate.zwrocDateZPoczatkiemPoprzedniegoMiesiaca());
    koniecPoprzedniegoMiesiaca = checkingDate.zwrocDateZKoncemMiesiaca(AuxiliaryMethods::convertIntToString(poczatekPoprzedniegoMiesiaca));

    cout<<endl<<"Bilans z poprzedniego miesiaca: "<<endl<<endl;

    for (vector <Income> :: iterator itr = incomies.begin(); itr != incomies.end(); itr++){
        for (int i=poczatekPoprzedniegoMiesiaca; i<=koniecPoprzedniegoMiesiaca; i++){
            if(itr -> getDate() == i){
                pokazPojedynczyPrzychod(*itr);
            }
        }
    }
    system("pause");
}

void IncomiesAndExpensesManager::bilansZWybranegoOkresu(){
    int koniecPrzedzialu, tymczasowePoczatkowaData, tymczasoweKoniecPrzedzialu, tymczasoweKoniecMiesiaca;//"poczatekPrzedzialu" -> dla spojnosci trzeba bedzie wprowadzic ta zmienna

    sort(incomies.begin(), incomies.end( ), [ ](Income a, Income b)  {return a.getDate() < b.getDate();} ); //wyrazenie lambda

    do{
        zapiszObieDatyDoBilansu();
    }while (!sprawdzCzyPierwszaDataJestMniejszaOdDrugiej());

    dataZKoncemMiesiaca = checkingDate.zwrocDateZKoncemMiesiaca(AuxiliaryMethods::convertIntToString(poczatkowaData));

    koncowaData >= dataZKoncemMiesiaca ? koniecPrzedzialu = dataZKoncemMiesiaca : koniecPrzedzialu = koncowaData;

    tymczasowePoczatkowaData = poczatkowaData;
    tymczasoweKoniecMiesiaca = dataZKoncemMiesiaca;
    tymczasoweKoniecPrzedzialu = koniecPrzedzialu;

    for (vector <Income> :: iterator itr = incomies.begin(); itr != incomies.end(); itr++){
        if(itr -> getDate() >= poczatkowaData){
            for (int i=poczatkowaData; i<=koniecPrzedzialu; i++){
                if(itr -> getDate() == i)
                    pokazPojedynczyPrzychod(*itr);
                if(i==koniecPrzedzialu && koniecPrzedzialu!=dataZKoncemMiesiaca)
                    break;
                if(i==koniecPrzedzialu)
                    koniecPrzedzialu = przesunDatyOJedenMiesiacDoPrzodu(koniecPrzedzialu);
                }
                poczatkowaData = tymczasowePoczatkowaData;
                dataZKoncemMiesiaca = tymczasoweKoniecMiesiaca;
                koniecPrzedzialu = tymczasoweKoniecPrzedzialu;
            }
    }
    system("pause");
}

void IncomiesAndExpensesManager::zapiszObieDatyDoBilansu(){
    string pierwszaDataDoBilansuZKreskami, drugaDataDoBilansuZKreskami;

    cout<<endl<<"Bilans z wybranego okresu: "<<endl;

    cout<<"Wprowadz pierwsza date (RRRR-MM-DD): ";
    pierwszaDataDoBilansuZKreskami = checkingDate.enterDate(pierwszaDataDoBilansuZKreskami);

    cout<<"Wprowadz druga date (RRRR-MM-DD) (aktualna data -> wcisnij 'd'): ";
    drugaDataDoBilansuZKreskami = checkingDate.enterDate(drugaDataDoBilansuZKreskami);

    checkingDate.splitDateIntoIntVariables(pierwszaDataDoBilansuZKreskami);
    poczatkowaData = checkingDate.zwrocDateZeZemiennychGlobalnych();

    dataZKoncemMiesiaca = checkingDate.zwrocDateZKoncemMiesiaca(AuxiliaryMethods::convertIntToString(poczatkowaData));

    checkingDate.splitDateIntoIntVariables(drugaDataDoBilansuZKreskami);
    koncowaData = checkingDate.zwrocDateZeZemiennychGlobalnych();
}

bool IncomiesAndExpensesManager::sprawdzCzyPierwszaDataJestMniejszaOdDrugiej(){
    if(poczatkowaData>koncowaData)
    {
        cout<<"Pierwsza data nie moze byc wieksza od drugiej. Sproboj ponownie."<<endl;
        return false;
    }
    return true;
}

int IncomiesAndExpensesManager::przesunDatyOJedenMiesiacDoPrzodu(int koniecPrzedzialu){
    poczatkowaData = checkingDate.zwrocDateZPoczatkiemNastepnegoMiesiaca(AuxiliaryMethods::convertIntToString(poczatkowaData));
    dataZKoncemMiesiaca = checkingDate.zwrocDateZKoncemMiesiaca(AuxiliaryMethods::convertIntToString(poczatkowaData));
    koncowaData >= dataZKoncemMiesiaca ? koniecPrzedzialu = dataZKoncemMiesiaca : koniecPrzedzialu = koncowaData;

    return koniecPrzedzialu;
}






























//------------------------puste------------------------------------------------------------------------------



//------------------------tymczasowe------------------------------------------------------------------------------
void IncomiesAndExpensesManager::pokazWszystkiePrzychody()//tymczasowe
{
    if (!incomies.empty()){
        cout << "             >>> Przychody <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Income> :: iterator itr = incomies.begin(); itr != incomies.end(); itr++){
            pokazWszystkiePrzychodyCD(*itr);
        }
        cout << endl;
    }else{
        cout << endl << "Przychodow brak." << endl << endl;
    }
    system("pause");
    system("cls");
}

void IncomiesAndExpensesManager::pokazWszystkiePrzychodyCD(Income income)//tymczasowe
{
    cout<<"income.getUserId(): "<<income.getUserId()<<endl;
    cout<<"income.getIncomeId(): "<<income.getIncomeId()<<endl;
    cout<<"income.getDate(): "<<income.getDate()<<endl;
    cout<<"income.getItem(): "<<income.getItem()<<endl;
    cout<<"income.getAmount(): "<<fixed<<setprecision(2)<<income.getAmount()<<endl<<endl;//probojemy wyswietlic dwa zera po zlotowkach
}


void IncomiesAndExpensesManager::pokazWszystkieWydatki()//tymczasowe
{
    if (!expenses.empty()){
        cout << "             >>> Wydatki <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Expense> :: iterator itr = expenses.begin(); itr != expenses.end(); itr++){
            pokazWszystkieWydatkiCD(*itr);
        }
        cout << endl;
    }else{
        cout << endl << "Wydatkow brak." << endl << endl;
    }
    system("pause");
    system("cls");
}

void IncomiesAndExpensesManager::pokazWszystkieWydatkiCD(Expense expense)//tymczasowe
{
    cout<<"expense.getUserId(): "<<expense.getUserId()<<endl;
    cout<<"expense.getExpenseId(): "<<expense.getExpenseId()<<endl;
    cout<<"expense.getDate(): "<<expense.getDate()<<endl;
    cout<<"expense.getItem(): "<<expense.getItem()<<endl;
    cout<<"expense.getAmount(): "<<fixed<<setprecision(2)<<expense.getAmount()<<endl<<endl;
}


void IncomiesAndExpensesManager::pokazPojedynczyPrzychod(Income income){
    cout<<left;
    cout<<setw(6)<<income.getUserId();
    cout<<setw(6)<<income.getIncomeId();
    cout<<setw(13)<<income.getDate();
    cout<<setw(13)<<income.getItem();
    cout<<fixed<<setprecision(2)<<income.getAmount()<<endl;
}

