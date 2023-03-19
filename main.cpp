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
                    personalBudget.addIncome();                             break;
                case '2':
                    personalBudget.addExpense();                            break;
                case '3':
                    personalBudget.bilansZBiezacegoMiasiaca();              break;//pozniej na ang
                case '4':
                    personalBudget.bilansZPoprzedniegoMiesiaca();           break;//pozniej na ang
                case '5':
                    personalBudget.bilansZWybranegoOkresu();                break;//pozniej na ang
                case '6':
                    personalBudget.zmianaHaslaZalogowanegoUzytkownika();    break;//pozniej na ang
                case '7':
                    personalBudget.logoutUser();                            break;
                }
        }
    }
    return 0;
}

///rzeczy do zrobienia
///funkcje w "checkingDate" jako statyczne 8,45 --------------------------------------------- nie udalo sie...
///w klasach np. FileWithUsers trzeba ustawic stala zmienna const z naswa pliku, jak w ksiazce adresowej
///wysylajac do bilansow zmienne, mozna je dac do glownych prywatnych zmiennych, moze bedzie ladniej : ] (moze na koniec, na razie nie wyszlo przez zmiane zmiennych glownych w policzBilansDlaPrzychodow i policzBilansDlaWydatkow
