#include "PersonalBudget.h"

char PersonalBudget::selectOptionFromMainMenu(){

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

bool PersonalBudget::isUserLoggedIn(){
    return userManager.getLoggedInUserId();
}


void PersonalBudget::registerUser(){
    userManager.registerUser();
}

void PersonalBudget::loginUser(){
    userManager.loginUser();

    //incomiesAndExpensesManager(); //pozniej trzeba do tego wrocic (problem z konstruktorem)
}

void PersonalBudget::pokazWszystkichUzytkownikow(){//tymczasowe
    userManager.pokazWszystkichUzytkownikow();
}




void PersonalBudget::dodajPrzychod(){
    incomiesAndExpensesManager.addIncome(userManager.getLoggedInUserId());//trzeba gdzies dac informacje dotyczaca zalogowanego uzytkownika
}

void PersonalBudget::dodajWydatek(){
    incomiesAndExpensesManager.addExpense(userManager.getLoggedInUserId());
}


void PersonalBudget::bilansZBiezacegoMiasiaca(){
    incomiesAndExpensesManager.bilansZBiezacegoMiasiaca();//puste
}

void PersonalBudget::bilansZPoprzedniegoMiesiaca(){
    incomiesAndExpensesManager.bilansZPoprzedniegoMiesiaca();//puste
}

void PersonalBudget::bilansZWybranegoOkresu(){
    incomiesAndExpensesManager.bilansZWybranegoOkresu();//puste
}


void PersonalBudget::zmianaHaslaZalogowanegoUzytkownika(){
    userManager.zmianaHaslaZalogowanegoUzytkownika();//puste
}

void PersonalBudget::wylogujUzytkownika(){
    userManager.wylogujUzytkownika();
}



