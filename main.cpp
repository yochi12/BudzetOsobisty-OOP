#include <iostream>

#include "PersonalBudget.h"

using namespace std;

int main()
{
    PersonalBudget personalBudget;

    char choice;

    while (true){
        if(personalBudget.isUserLoggedIn()==false){
            choice=personalBudget.selectOptionFromMainMenu();

            switch (choice){
                case '1':
                    personalBudget.registerUser();
                    break;
                case '2':
                    personalBudget.loginUser();
                    break;
                case '3':

                    break;
                case '4':
                    personalBudget.pokazWszystkichUzytkownikow();//tymczasowo
                    break;
                case '0':
                    exit(0);
                    break;
                default:
                    cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                    system("pause");
                    system("cls");
                    break;
            }
        }else{
            choice=personalBudget.selectOptionFromUserMenu();

            switch (choice){
                case '1':
                    personalBudget.addIncome();                         break;
                case '2':
                    personalBudget.addExpense();                          break;
                case '3':
                    personalBudget.bilansZBiezacegoMiasiaca();              break;//puste
                case '4':
                    personalBudget.bilansZPoprzedniegoMiesiaca();           break;//puste
                case '5':
                    personalBudget.bilansZWybranegoOkresu();                break;//puste
                case '6':
                    personalBudget.zmianaHaslaZalogowanegoUzytkownika();    break;//puste
                case '7':
                    personalBudget.logoutUser();                            break;
                }
        }
    }
    return 0;
}

///rzeczy do zrobienia
///blad w funkcji "getNewIncomeID" od minuty 5 i 8.30 (to samo w "getNewExpenseID") ---------- nie potrafie znalezc problemu
///w bilansach z tego i porzedniego miesiaca trzeba cos poprawic 7,35 ------------------------ nie wiem gdzie lezy problem, wszystko wydaje sie dzialac dobrze
///funkcje w "checkingDate" jako statyczne 8,45 --------------------------------------------- nie udalo sie...
