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
                    personalBudget.balanceOfCurrentMonth();                 break;
                case '4':
                    personalBudget.balanceOfPreviousMonth();                break;
                case '5':
                    personalBudget.balanceOfSelectedTime();                 break;
                case '6':
                    personalBudget.changePassword();                        break;
                case '7':
                    personalBudget.logoutUser();                            break;
                }
        }
    }
    return 0;
}


