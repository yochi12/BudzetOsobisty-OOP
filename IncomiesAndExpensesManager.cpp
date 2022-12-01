#include "IncomiesAndExpensesManager.h"// ogarnac temat tego konstruktora, sprawdzic czy NA PEWNO vector jest pusty przy wyborze innego uzytkownika

//------------------------przychody------------------------------------------------------------------------------
void IncomiesAndExpensesManager::addIncome(int loggedInUserId)//"dodajPrzychod"
{incomiesV = fileWithIncomies.loadIncomiesFromFileXML(loggedInUserId);//powinno byc w konstruktorze, ale tam nie ma "loggedInUserId"
pokazWszystkiePrzychody();//tymczasowo
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

    cout<<"Podaj date: ";//te kilka linijek powtarza sie w wydatkach, mozna z tego zrobic osobna funkcje
    enterDate(dateWithDashes);

    incomiesC.setDate(atoi(AuxiliaryMethods::replaceDateToTextWithoutDashes(dateWithDashes).c_str()));

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

//------------------------wydatki------------------------------------------------------------------------------
void IncomiesAndExpensesManager::addExpense(int loggedInUserId)//"dodajWydatek"
{expensesV = fileWithExpenses.loadExpensesFromFileXML(loggedInUserId);//jeszcze chwile poczeka
pokazWszystkieWydatki();//tymczasowo
    Expenses expensesC = enterNewExpenseDetails(loggedInUserId);

    expensesV.push_back(expensesC);

    fileWithExpenses.addExpensesToFileXML(expensesC);
}

Expenses IncomiesAndExpensesManager::enterNewExpenseDetails(int loggedInUserId)//"podajDaneNowegoWydatku"
{
    Expenses expensesC;
    string dateWithDashes;//"dataZKreskami"

    expensesC.setUserId(loggedInUserId);
    expensesC.setExpenseId(getNewExpenseId());

    cout<<"Podaj date: ";
    enterDate(dateWithDashes);

    expensesC.setDate(atoi(AuxiliaryMethods::replaceDateToTextWithoutDashes(dateWithDashes).c_str()));

    cout<<"Podaj przedmiot: ";
    expensesC.setItem(AuxiliaryMethods::loadLine());

    cout<<"Podaj kwote: ";
    expensesC.setAmount(AuxiliaryMethods::loadInteger());

    return expensesC;
}

int IncomiesAndExpensesManager::getNewExpenseId(){
    if (expensesV.empty() == true)
        return 1;
    else
        return expensesV.back().getExpenseId() + 1;
}

//------------------------puste------------------------------------------------------------------------------
void IncomiesAndExpensesManager::enterDate(string dateWithDashes)
{
    while(true){
        dateWithDashes = AuxiliaryMethods::loadLine();
        if(checkingDate.isDateCorrect(dateWithDashes))
            break;
        cout<<"Data niepoprawna. Podaj date: ";
    }
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
    cout<<"incomiesC.getAmount(): "<<incomiesC.getAmount()<<endl<<endl;
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
    cout<<"expensesC.getAmount(): "<<expensesC.getAmount()<<endl<<endl;
}

