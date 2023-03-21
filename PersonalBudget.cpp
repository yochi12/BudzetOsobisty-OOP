#include "PersonalBudget.h"

char PersonalBudget::selectOptionFromMainMenu(){
    cout << "   >>>> BUDZET OSOBISTY <<<<" <<   endl;
    cout << "    >>> MENU  GLOWNE <<<" <<       endl;
    cout << "---------------------------" <<    endl;
    cout << "1. Rejestracja" <<                 endl;
    cout << "2. Logowanie" <<                   endl;
    cout << "0. Koniec programu" <<             endl;
    cout << "---------------------------" <<    endl;
    cout << "Twoj wybor: ";

    return AuxiliaryMethods::loadChar();
}

char PersonalBudget::selectOptionFromUserMenu(){
    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" <<      endl;
    cout << "---------------------------" <<    endl;
    cout << "1. Dodaj przychod" <<              endl;
    cout << "2. Dodaj wydatek" <<         endl;
    cout << "3. Bilans z biezacego miasiaca" <<        endl;
    cout << "4. Bilans z poprzedniego miesiaca" <<          endl;
    cout << "5. Bilans z wybranego okresu" <<               endl;
    cout << "---------------------------" <<    endl;
    cout << "6. Zmien haslo" <<                 endl;
    cout << "7. Wyloguj sie" <<                 endl;
    cout << "---------------------------" <<    endl;
    cout << "Twoj wybor: ";

    return AuxiliaryMethods::loadChar();
}

void PersonalBudget::registerUser(){
    userManager.registerUser();
}

void PersonalBudget::loginUser(){
    userManager.loginUser();
    if(userManager.getLoggedInUserId()!=0){
        incomiesAndExpensesManager = new IncomiesAndExpensesManager(userManager.getLoggedInUserId());
    }
}

void PersonalBudget::changePassword(){
    userManager.changePassword();
}

bool PersonalBudget::isUserLoggedIn(){
    return userManager.getLoggedInUserId();
}

void PersonalBudget::logoutUser(){
    userManager.logoutUser();
}


void PersonalBudget::addIncome(){
    incomiesAndExpensesManager -> addIncome();
}

void PersonalBudget::addExpense(){
    incomiesAndExpensesManager -> addExpense();
}

//------------------------bilanse------------------------------------------------------------------------------
void PersonalBudget::balanceOfCurrentMonth(){
    int currentDate, dateBeginningOfMonth;

    currentDate = AuxiliaryMethods::convertStringToInt(checkingDate.enterCurrentDate());
    dateBeginningOfMonth = checkingDate.returnDateWithBeginningOfMonth(currentDate);

    cout<<endl<<"BILANS Z BIEZACEGO MIESIACA"<<endl<<endl;
    incomiesAndExpensesManager -> balanceOfOneMonth(dateBeginningOfMonth, currentDate);
}

void PersonalBudget::balanceOfPreviousMonth(){
    int currentDate, dateBeginningOfPreviousMonth, dateEndOfPreviousMonth;

    currentDate = AuxiliaryMethods::convertStringToInt(checkingDate.enterCurrentDate());

    dateBeginningOfPreviousMonth = checkingDate.returnDateWithBeginningOfPreviousmMonth(currentDate);
    dateEndOfPreviousMonth = checkingDate.returnDateAtEndOfMonth(dateBeginningOfPreviousMonth);

    cout<<endl<<"BILANS Z POPRZEDNIEGO MIESIACA"<<endl<<endl;
    incomiesAndExpensesManager -> balanceOfOneMonth(dateBeginningOfPreviousMonth, dateEndOfPreviousMonth);
}

void PersonalBudget::balanceOfSelectedTime(){
    string firstDate, secondDate, supportingDate;

    cout<<endl<<"BILANS Z WYBRANEGO OKRESU"<<endl;

    cout<<"Wprowadz pierwsza date (RRRR-MM-DD): ";
    firstDate = AuxiliaryMethods::replaceDateToTextWithoutDashes(checkingDate.enterDate(firstDate));

    cout<<"Wprowadz druga date (RRRR-MM-DD) (aktualna data -> wcisnij 'd'): ";
    secondDate = AuxiliaryMethods::replaceDateToTextWithoutDashes(checkingDate.enterDate(secondDate));

    firstDate >= secondDate ? supportingDate = firstDate, firstDate = secondDate, secondDate = supportingDate : supportingDate;
    incomiesAndExpensesManager -> balanceOfSelectedTime(AuxiliaryMethods::convertStringToInt(firstDate), AuxiliaryMethods::convertStringToInt(secondDate));
}


