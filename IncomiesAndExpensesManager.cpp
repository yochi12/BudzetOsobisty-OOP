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
void IncomiesAndExpensesManager::balanceOfOneMonth(int firstDate, int secondDate){//bilansZBiezacegoMiasiaca
    savesDatesToMainVariables(firstDate, secondDate);
    sortVectorsByDate();

    cout << "             >>> Przychody <<<" << endl;
    cout << "-----------------------------------------------" << endl;
    calculateBalanceForOneMonthsIncomies();
    isBalanceEmpty();

    cout << "             >>> Wydatki <<<" << endl;
    cout << "-----------------------------------------------" << endl;
    calculateBalanceForOneMonthsExpenses();
    isBalanceEmpty();

    showSumOfIncomiesAndExpenses();

    system("pause");
}

void IncomiesAndExpensesManager::balanceOfSelectedTime(int firstDate, int secondDate){
    savesDatesToMainVariables(firstDate, secondDate);
    sortVectorsByDate();

    cout << "             >>> Przychody <<<" << endl;
    cout << "-----------------------------------------------" << endl;
    calculateBalanceForIncomies(secondDate);
    isBalanceEmpty();

    savesDatesToMainVariables(firstDate, secondDate);

    cout << "             >>> Wydatki <<<" << endl;
    cout << "-----------------------------------------------" << endl;
    calculateBalanceForExpenses(secondDate);
    isBalanceEmpty();

    showSumOfIncomiesAndExpenses();

    system("pause");
}

void IncomiesAndExpensesManager::calculateBalanceForIncomies(int secondDate){
    do{
        calculateBalanceForOneMonthsIncomies();

        dateStartOfRange = checkingDate.returnDateWithBeginningOfNextMonth(dateStartOfRange);///
        dateEndOfRange = checkingDate.returnDateAtEndOfMonth(dateStartOfRange);//zwrocDateZKoncemMiesiaca
        dateEndOfRange < secondDate ? dateEndOfRange : dateEndOfRange = secondDate;
    }while(dateStartOfRange < secondDate);
}

void IncomiesAndExpensesManager::calculateBalanceForExpenses(int secondDate){
    do{
        calculateBalanceForOneMonthsExpenses();

        dateStartOfRange = checkingDate.returnDateWithBeginningOfNextMonth(dateStartOfRange);///
        dateEndOfRange = checkingDate.returnDateAtEndOfMonth(dateStartOfRange);
        dateEndOfRange < secondDate ? dateEndOfRange : dateEndOfRange = secondDate;
    }while(dateStartOfRange < secondDate);
}

void IncomiesAndExpensesManager::calculateBalanceForOneMonthsIncomies(){
    for (vector <Income> :: iterator itr = incomies.begin(); itr != incomies.end(); itr++){
        for (int i=dateStartOfRange; i<=dateEndOfRange; i++){
            if(itr -> getDate() == i){
                showSingleIncome(*itr);
                sumOfAllIncomies += itr -> getAmount();
                noPayments = false;
            }
        }
    }
}

void IncomiesAndExpensesManager::calculateBalanceForOneMonthsExpenses(){
    for (vector <Expense> :: iterator itr = expenses.begin(); itr != expenses.end(); itr++){
        for (int i=dateStartOfRange; i<=dateEndOfRange; i++){
            if(itr -> getDate() == i){
                showSingleExpense(*itr);
                sumOfAllExpenses += itr -> getAmount();
                noPayments = false;
            }
        }
    }
}

int IncomiesAndExpensesManager::savesDatesToMainVariables(int firstDate, int secondDate){
    int dateEndOfMonth = checkingDate.returnDateAtEndOfMonth(firstDate);
    dateStartOfRange = firstDate;
    secondDate >= dateEndOfMonth ? dateEndOfRange = dateEndOfMonth : dateEndOfRange = secondDate;

    return dateEndOfMonth;
}

void IncomiesAndExpensesManager::sortVectorsByDate(){
    sort(incomies.begin(), incomies.end( ), [ ](Income a, Income b)  {return a.getDate() < b.getDate();} ); //wyrazenie lambda
    sort(expenses.begin(), expenses.end( ), [ ](Expense a, Expense b)  {return a.getDate() < b.getDate();} );
}


//------------------------Wyswietlanie-danych------------------------------------------------------------------------------
void IncomiesAndExpensesManager::showSingleIncome(Income income){
    cout<<left;
    cout<<setw(13)<<"  Data:"<<AuxiliaryMethods::addDashesToDate(AuxiliaryMethods::convertIntToString(income.getDate()))<<endl;
    cout<<setw(13)<<"  Przedmiot:"<<income.getItem()<<endl;
    cout<<setw(13)<<"  Kwota:"<<fixed<<setprecision(2)<<income.getAmount()<<endl<<endl;
}

void IncomiesAndExpensesManager::showSingleExpense(Expense expense){
    cout<<left;
    cout<<setw(13)<<"  Data:"<<AuxiliaryMethods::addDashesToDate(AuxiliaryMethods::convertIntToString(expense.getDate()))<<endl;
    cout<<setw(13)<<"  Przedmiot:"<<expense.getItem()<<endl;
    cout<<setw(13)<<"  Kwota:"<<fixed<<setprecision(2)<<expense.getAmount()<<endl<<endl;
}

void IncomiesAndExpensesManager::isBalanceEmpty(){
    if(noPayments == true)
        cout<<"Brak platnosci w tym okresie."<<endl<<endl;

    noPayments = true;
}

void IncomiesAndExpensesManager::showSumOfIncomiesAndExpenses(){
    cout<<endl<<"Calkowite przychody: "<<fixed<<setprecision(2)<<sumOfAllIncomies<<endl;    sumOfAllIncomies = 0;
    cout<<"Calkowite wydatki: "<<fixed<<setprecision(2)<<sumOfAllExpenses<<endl<<endl;    sumOfAllExpenses = 0;
}

