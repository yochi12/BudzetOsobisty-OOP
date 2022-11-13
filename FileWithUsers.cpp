#include "FileWithUsers.h"

void FileWithUsers::addUserToFileXML(User user){
    CMarkup xml;

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
    CMarkup xml1;

    xml1.Load("users.xml");
    xml1.FindElem(); //<Users>
    xml1.IntoElem();

    while (xml1.FindElem("User")){
        xml1.IntoElem();
        xml1.FindElem(); //ID
        MCD_STR line = xml1.GetData();     user.setId(atoi(line.c_str()));        //cout<<"line = "<<line<<endl;
        xml1.FindElem(); //Login
        line = xml1.GetData();             user.setLogin(line);                   //cout<<"line = "<<line<<endl;
        xml1.FindElem(); //Password
        line = xml1.GetData();             user.setPassword(line);                //cout<<"line = "<<line<<endl;
        xml1.FindElem(); //Name
        line = xml1.GetData();             user.setName(line);                    //cout<<"line = "<<line<<endl;
        xml1.FindElem(); //Surname
        line = xml1.GetData();             user.setSurname(line);                 //cout<<"line = "<<line<<endl;

        xml1.OutOfElem();

        users.push_back(user);
    }
    return users;
}


