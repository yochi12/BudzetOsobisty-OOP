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
    if(userManager.getLoggedInUserId()!=0){
        incomiesAndExpensesManager = new IncomiesAndExpensesManager(userManager.getLoggedInUserId());
    }
}

void PersonalBudget::addIncome(){
    incomiesAndExpensesManager -> addIncome();
}

void PersonalBudget::addExpense(){
    incomiesAndExpensesManager -> addExpense();
}




void PersonalBudget::bilansZBiezacegoMiasiaca(){
    int aktualnaData, dataZPoczatekiemMiesiaca;

    aktualnaData = AuxiliaryMethods::convertStringToInt(checkingDate.enterCurrentDate());//tutaj byc moze pozniej zamienimy typ zwracany w "enterCurrentDate"
    dataZPoczatekiemMiesiaca = checkingDate.zwrocDateZPoczatkiemMiesiaca(aktualnaData);

    cout<<endl<<"Bilans z biezacego miesiaca: "<<endl<<endl;
    incomiesAndExpensesManager -> bilansZBiezacegoLubPoprzedniegoMiesiaca(dataZPoczatekiemMiesiaca, aktualnaData);
}

void PersonalBudget::bilansZPoprzedniegoMiesiaca(){
    int aktualnaData, poczatekPoprzedniegoMiesiaca, koniecPoprzedniegoMiesiaca;

    aktualnaData = AuxiliaryMethods::convertStringToInt(checkingDate.enterCurrentDate());

    poczatekPoprzedniegoMiesiaca = checkingDate.zwrocDateZPoczatkiemPoprzedniegoMiesiaca(aktualnaData);
    koniecPoprzedniegoMiesiaca = checkingDate.zwrocDateZKoncemMiesiaca(poczatekPoprzedniegoMiesiaca);

    cout<<endl<<"Bilans z poprzedniego miesiaca: "<<endl<<endl;
    incomiesAndExpensesManager -> bilansZBiezacegoLubPoprzedniegoMiesiaca(poczatekPoprzedniegoMiesiaca, koniecPoprzedniegoMiesiaca);
}

void PersonalBudget::bilansZWybranegoOkresu(){
    string poczatkowaData, koncowaData, pomocniczaData;

    cout<<endl<<"Bilans z wybranego okresu: "<<endl;

    cout<<"Wprowadz pierwsza date (RRRR-MM-DD): ";
    poczatkowaData = AuxiliaryMethods::replaceDateToTextWithoutDashes(checkingDate.enterDate(poczatkowaData));

    cout<<"Wprowadz druga date (RRRR-MM-DD) (aktualna data -> wcisnij 'd'): ";
    koncowaData = AuxiliaryMethods::replaceDateToTextWithoutDashes(checkingDate.enterDate(koncowaData));

    poczatkowaData >= koncowaData ? pomocniczaData = poczatkowaData, poczatkowaData = koncowaData, koncowaData = pomocniczaData : pomocniczaData;

    incomiesAndExpensesManager -> bilansZWybranegoOkresu(AuxiliaryMethods::convertStringToInt(poczatkowaData), AuxiliaryMethods::convertStringToInt(koncowaData));
}


void PersonalBudget::zmianaHaslaZalogowanegoUzytkownika(){
    userManager.zmianaHaslaZalogowanegoUzytkownika();//puste
}

void PersonalBudget::logoutUser(){
    userManager.logoutUser();
}


void PersonalBudget::pokazWszystkichUzytkownikow(){//tymczasowe
    userManager.pokazWszystkichUzytkownikow();
}

