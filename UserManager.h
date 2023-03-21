#ifndef UserManager_H
#define UserManager_H
#include <iostream>
#include <vector>

#include "FileWithUsers.h"

using namespace std;

class UserManager
{
    vector <User> users;
    FileWithUsers fileWithUsers;
    int loggedInUserId;

public:
    UserManager(){
        loggedInUserId=0;
        users = fileWithUsers.loadUsersFromFileXML();
    }

    void registerUser();
    void loginUser();
    User getNewUserData();
    int getNewUserId();
    bool isLoginExist(string login);
    int getLoggedInUserId();

    void changePassword();
    void logoutUser();
};

#endif
