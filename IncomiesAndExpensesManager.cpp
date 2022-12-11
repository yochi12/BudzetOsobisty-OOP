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

    cout<<endl<<"Podaj date: ";
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

string IncomiesAndExpensesManager::loadAmount(){
    return AuxiliaryMethods::convertCommaToDot(AuxiliaryMethods::loadLine());
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

    cout<<endl<<"Podaj date: ";
    dateWithDashes = enterDate(dateWithDashes);

    expensesC.setDate(atoi(AuxiliaryMethods::replaceDateToTextWithoutDashes(dateWithDashes).c_str()));

    cout<<"Podaj przedmiot: ";
    expensesC.setItem(AuxiliaryMethods::loadLine());

    cout<<"Podaj kwote: ";
    expensesC.setAmount(AuxiliaryMethods::loadFloat());

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
        cout<<"Data niepoprawna. Podaj date: ";
    }
    return dateWithDashes;
}


//------------------------puste------------------------------------------------------------------------------
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

