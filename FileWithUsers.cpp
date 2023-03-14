#include "FileWithUsers.h"

void FileWithUsers::addUserToFileXML(User user){
    bool fileExists = xml.Load("users.xml");
    if (!fileExists){ //jesli plik nie istnieje, to dodajemy glowny element "Users"
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }

    xml.FindElem(); //szuka elementu w pliku
    xml.IntoElem(); //robi ten element elementem glownym
    xml.AddElem("User"); //do obiektu dodajemy "User"
    xml.IntoElem(); //wchodzimy do tej galezi
    xml.AddElem("ID", user.getId());
    xml.AddElem("Login", user.getLogin());
    xml.AddElem("Password", user.getPassword());
    xml.AddElem("Name", user.getName());
    xml.AddElem("Surname", user.getSurname());
    //MCD_STR strXML = xml.GetDoc(); //zmienna "strXML" pokazuje pelen tekst obiektu "xml"
    //cout<<"Pelen tekst obiektu 'xml':"<<endl<<strXML<<endl;
    ///dwa wiersze wyzej pokazuja aktualnie wpisana osobe tak jak w pliku .XML
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
        MCD_STR line = xml.GetData();     user.setId(atoi(line.c_str()));        //cout<<"line = "<<line<<endl;
        xml.FindElem(); //Login
        line = xml.GetData();             user.setLogin(line);                   //cout<<"line = "<<line<<endl;
        xml.FindElem(); //Password
        line = xml.GetData();             user.setPassword(line);                //cout<<"line = "<<line<<endl;
        xml.FindElem(); //Name
        line = xml.GetData();             user.setName(line);                    //cout<<"line = "<<line<<endl;
        xml.FindElem(); //Surname
        line = xml.GetData();             user.setSurname(line);                 //cout<<"line = "<<line<<endl;

        xml.OutOfElem();

        users.push_back(user);
    }
    return users;
}




