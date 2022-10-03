#ifndef PersonalBudget_H
#define PersonalBudget_H
#include <iostream>
#include <vector>

#include "User.h"
#include "UserManager.h"
#include "AuxiliaryMethods.h" //nie wiem czemu, ale bez tego nie dzialaja metody z tej klasy... (w Ksiazce Adresowej dzialalo bez)

using namespace std;

class PersonalBudget
{
    UserManager userManager;
    int loggedInUserId;

    vector <User> users;

public:
    char selectOptionFromMainMenu();
    char loadChar();
    void registerUser(); //jeszcze puste
    void loginUser(); //jeszcze puste

};

#endif
