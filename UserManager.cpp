#include "UserManager.h"

void UserManager::registerUser()
{
    User user = getNewUserData();

    users.push_back(user);

    fileWithUsers.addUserToFileXML(user);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
    system("cls");
}

User UserManager::getNewUserData(){
    User user;

    user.setId(getNewUserId());

    do{
        cout << "Podaj login: ";
        user.setLogin(AuxiliaryMethods::loadLine());
    }while (isLoginExist(user.getLogin()) == true);//nie trzeba tego porownywac do "true", wychodzi na tao samo : ]
                                        //jesli chcemy porownac do "false" to wykrzyknik przed, np. "(!uzytkownik.pobierzLogin())"
    cout << "Podaj haslo: ";
    user.setPassword(AuxiliaryMethods::loadLine());

    cout << "Podaj imie: ";
    user.setName(AuxiliaryMethods::loadLine());

    cout << "Podaj nazwisko: ";
    user.setSurname(AuxiliaryMethods::loadLine());

    return user;
}

int UserManager::getNewUserId(){
    if (users.empty() == true)
        return 1;
    else
        return users.back().getId() + 1;
}

bool UserManager::isLoginExist(string login){
    for(int i=0; i<(int)users.size(); i++){///inne typy zmiennych ("i" i "uzytkownicy.size()", dlatego int w nawiasie (warning, nie error))
        if(users[i].getLogin() == login){
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}

void UserManager::loginUser(){ //"logowanie uzytkownika"
    User user;
    string login = "", password = "";

    cout << endl << "Podaj login: ";
    login = AuxiliaryMethods::loadLine();

    vector <User>::iterator itr = users.begin();

    while (itr != users.end()){
        if (itr -> getLogin() == login)/// tutaj przechodze po wektorze zawierajacym obiekty typu "Uzytkownik", dlatego nie uzywam kropek ani innych znakow
        {
            for (int numberOfAttempts = 3; numberOfAttempts > 0; numberOfAttempts--){ //numberOfAttempts -> ilosc prob
                cout << "Podaj haslo. Pozostalo prob: " << numberOfAttempts << ": ";
                password = AuxiliaryMethods::loadLine();

                if (itr -> getPassword() == password){
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    loggedInUserId = itr -> getId(); return;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            system("cls");
            loggedInUserId = 0; return;
        }
        itr++;
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    system("cls");
    loggedInUserId = 0; return;
}


int UserManager::getLoggedInUserId(){ //pobierzIdZalogowanegoUzytkownika
    return loggedInUserId;
}


void UserManager::zmianaHaslaZalogowanegoUzytkownika()
{
    cout<<"zmianaHaslaZalogowanegoUzytkownika:"<<endl;
}

void UserManager::logoutUser()
{
    cout<<"Trwa wylogowywanie..."<<endl;
    loggedInUserId=0;
    system("pause");
    system("cls");
}


void UserManager::pokazWszystkichUzytkownikow()
{
    if (!users.empty()){
        cout << "             >>> Uzutkownicy <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <User> :: iterator itr = users.begin(); itr != users.end(); itr++){
            wyswietlDaneUzytkownikow(*itr);//nie trzeba iteratorami, mozna jak za pomoca zwyklych tablic ( :))) )
        }
        cout << endl;
    }else{
        cout << endl << "Uzytkownikow brak." << endl << endl;
    }
    system("pause");
    system("cls");
}

void UserManager::wyswietlDaneUzytkownikow(User user){
    cout << endl << "Id:                 " << user.getId() << endl;
    cout << "Login:              " << user.getLogin() << endl;
    cout << "Haslo:              " << user.getPassword() << endl;
    cout << "Imie:               " << user.getName() << endl;
    cout << "Nazwisko:           " << user.getSurname() << endl;
}



