#ifndef FileWithUsers_H
#define FileWithUsers_H
#include <iostream>
#include <vector>

#include "Markup.h"
#include "User.h"


using namespace std;

class FileWithUsers
{
public:
    void addUserToFileXML(User user);
    vector <User> loadUsersFromFileXML();
};

#endif
