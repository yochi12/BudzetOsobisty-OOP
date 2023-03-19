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

void PersonalBudget::zmianaHaslaZalogowanegoUzytkownika(){  //pozniej na ang
    userManager.zmianaHaslaZalogowanegoUzytkownika();       //pozniej na ang
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
void PersonalBudget::bilansZBiezacegoMiasiaca(){    //pozniej na ang
    int aktualnaData, dataZPoczatekiemMiesiaca;

    aktualnaData = AuxiliaryMethods::convertStringToInt(checkingDate.enterCurrentDate());//tutaj byc moze pozniej zamienimy typ zwracany w "enterCurrentDate"
    dataZPoczatekiemMiesiaca = checkingDate.zwrocDateZPoczatkiemMiesiaca(aktualnaData);

    cout<<endl<<"BILANS Z BIEZACEGO MIESIACA"<<endl<<endl;
    incomiesAndExpensesManager -> bilansZJednegoMiesiaca(dataZPoczatekiemMiesiaca, aktualnaData);
}

void PersonalBudget::bilansZPoprzedniegoMiesiaca(){ //pozniej na ang
    int aktualnaData, dataZPoczatkiemPoprzedniegoMiesiaca, dataZKoncemPoprzedniegoMiesiaca;

    aktualnaData = AuxiliaryMethods::convertStringToInt(checkingDate.enterCurrentDate());

    dataZPoczatkiemPoprzedniegoMiesiaca = checkingDate.zwrocDateZPoczatkiemPoprzedniegoMiesiaca(aktualnaData);
    dataZKoncemPoprzedniegoMiesiaca = checkingDate.zwrocDateZKoncemMiesiaca(dataZPoczatkiemPoprzedniegoMiesiaca);

    cout<<endl<<"BILANS Z POPRZEDNIEGO MIESIACA"<<endl<<endl;
    incomiesAndExpensesManager -> bilansZJednegoMiesiaca(dataZPoczatkiemPoprzedniegoMiesiaca, dataZKoncemPoprzedniegoMiesiaca);
}

void PersonalBudget::bilansZWybranegoOkresu(){      //pozniej na ang
    string poczatkowaData, koncowaData, pomocniczaData;

    cout<<endl<<"BILANS Z WYBRANEGO OKRESU"<<endl;

    cout<<"Wprowadz pierwsza date (RRRR-MM-DD): ";
    poczatkowaData = AuxiliaryMethods::replaceDateToTextWithoutDashes(checkingDate.enterDate(poczatkowaData));

    cout<<"Wprowadz druga date (RRRR-MM-DD) (aktualna data -> wcisnij 'd'): ";
    koncowaData = AuxiliaryMethods::replaceDateToTextWithoutDashes(checkingDate.enterDate(koncowaData));

    poczatkowaData >= koncowaData ? pomocniczaData = poczatkowaData, poczatkowaData = koncowaData, koncowaData = pomocniczaData : pomocniczaData;
    incomiesAndExpensesManager -> bilansZWybranegoOkresu(AuxiliaryMethods::convertStringToInt(poczatkowaData), AuxiliaryMethods::convertStringToInt(koncowaData));
}


