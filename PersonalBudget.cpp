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



void PersonalBudget::registerUser()
{
    userManager.registerUser();
}

void PersonalBudget::loginUser()
{
    userManager.loginUser();
}



