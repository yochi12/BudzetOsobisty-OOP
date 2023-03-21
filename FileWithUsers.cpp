#include "FileWithUsers.h"

void FileWithUsers::addUserToFileXML(User user){
    bool fileExists = xml.Load("users.xml");
    if (!fileExists){ //jesli plik nie istnieje, to dodajemy glowny element "Users"
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }

    xml.FindElem();         //szuka elementu w pliku
    xml.IntoElem();         //robi ten element elementem glownym
    xml.AddElem("User");    //do obiektu dodajemy "User"
    xml.IntoElem();         //wchodzimy do tej galezi
    xml.AddElem("ID", user.getId());
    xml.AddElem("Login", user.getLogin());
    xml.AddElem("Password", user.getPassword());
    xml.AddElem("Name", user.getName());
    xml.AddElem("Surname", user.getSurname());
    xml.Save("users.xml");
}

vector <User> FileWithUsers::loadUsersFromFileXML(){
    User user;
    vector <User> users;

    xml.Load("users.xml");
    xml.FindElem(); //<Users>
    xml.IntoElem();

    while (xml.FindElem("User")){
        xml.IntoElem();
        xml.FindElem(); //ID
        MCD_STR line = xml.GetData();     user.setId(atoi(line.c_str()));
        xml.FindElem(); //Login
        line = xml.GetData();             user.setLogin(line);
        xml.FindElem(); //Password
        line = xml.GetData();             user.setPassword(line);
        xml.FindElem(); //Name
        line = xml.GetData();             user.setName(line);
        xml.FindElem(); //Surname
        line = xml.GetData();             user.setSurname(line);

        xml.OutOfElem();

        users.push_back(user);
    }
    return users;
}

vector <User> FileWithUsers::changePassword(int loggedInUserId, string newPassword){
    xml.Load("users.xml");
    xml.FindElem(); //<Users>
    xml.IntoElem();

    while (xml.FindElem("User")){
        xml.IntoElem();
        xml.FindElem(); //ID

        if (AuxiliaryMethods::convertStringToInt(xml.GetData()) == loggedInUserId){
            xml.FindElem("Password");
            xml.SetData(newPassword);
        }
        xml.OutOfElem();
    }
    xml.Save("users.xml");
    return loadUsersFromFileXML();
}


