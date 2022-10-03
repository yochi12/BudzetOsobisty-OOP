#include <iostream>

#include "PersonalBudget.h"

using namespace std;

int main()
{
    PersonalBudget personalBudget;

    char choice;

    while (true){
        //if(personalBudget.czyUzytkownikJestZalogowany()==false){
            choice=personalBudget.selectOptionFromMainMenu();

            switch (choice){
                case '1':
                    personalBudget.registerUser();
                    break;
                case '2':
                    personalBudget.loginUser();
                    break;
                case '0':
                    exit(0);                                                            break;
                default:
                    cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                    system("pause");
                    system("cls");                                                      break;
            }
        //}
    }
    return 0;
}

//wyswietla sie menu, mozemy wczytac znak (wybrac opcje z menu) ale na razie bez efektu (dziala opcja '0' :] )
//przyda sie dodac wiecej metod do "AuxiliaryMethods" i wypelnic logowanie oraz rejestracje
