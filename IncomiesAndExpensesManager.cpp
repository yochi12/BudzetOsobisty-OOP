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
    return fileWithExpenses.loadLastExpenseID() + 1;
}


//------------------------dodatkowe------------------------------------------------------------------------------


//------------------------bilanse------------------------------------------------------------------------------
void IncomiesAndExpensesManager::bilansZBiezacegoLubPoprzedniegoMiesiaca(int pierwszaData, int drugaData){///trzeba jeszcze zrobic te bilanse dla wydatkow!
    sort(incomies.begin(), incomies.end( ), [ ](Income a, Income b)  {return a.getDate() < b.getDate();} ); //wyrazenie lambda

    policzBilansZJednegoMiesiaca(pierwszaData, drugaData);
    system("pause");
}

void IncomiesAndExpensesManager::bilansZWybranegoOkresu(int wpisanaPierwszaData, int wpisanaDrugaData){
    int pierwszaData = wpisanaPierwszaData;
    int drugaData = wpisanaDrugaData;
    int dataZKoncemMiesiaca = checkingDate.zwrocDateZKoncemMiesiaca(wpisanaPierwszaData);

    sort(incomies.begin(), incomies.end( ), [ ](Income a, Income b)  {return a.getDate() < b.getDate();} ); //wyrazenie lambda
    drugaData >= dataZKoncemMiesiaca ? drugaData = dataZKoncemMiesiaca : drugaData = wpisanaDrugaData;

    do{
        policzBilansZJednegoMiesiaca(pierwszaData, drugaData);

        pierwszaData = checkingDate.zwrocDateZPoczatkiemNastepnegoMiesiaca(pierwszaData);
        drugaData = checkingDate.zwrocDateZKoncemMiesiaca(pierwszaData);

        drugaData < wpisanaDrugaData ? drugaData : drugaData = wpisanaDrugaData;
    }while(pierwszaData < wpisanaDrugaData);
    system("pause");
}

void IncomiesAndExpensesManager::policzBilansZJednegoMiesiaca(int pierwszaData, int drugaData){
    for (vector <Income> :: iterator itr = incomies.begin(); itr != incomies.end(); itr++){
        for (int i=pierwszaData; i<=drugaData; i++){
            if(itr -> getDate() == i){
                pokazPojedynczyPrzychod(*itr);
            }
        }
    }
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

