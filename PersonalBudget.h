#include <iostream>
#include <vector>

#include "User.h"

using namespace std;

class PersonalBudget
{
    int loggedInUserId;

    vector <User> users;

public:
    void registerUser();
};
