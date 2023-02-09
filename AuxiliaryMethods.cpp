#include "AuxiliaryMethods.h"

char AuxiliaryMethods::loadChar(){
    string input = "";
    char mark = {0};

    while (true){
        getline(cin, input);

        if (input.length() == 1){
            mark = input[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return mark;
}

string AuxiliaryMethods::loadLine(){
    string input = "";
    getline(cin, input);
    return input;
}

int AuxiliaryMethods::loadInteger(){
    string input = "";
    int number = 0;

    while (true){
        getline(cin, input);

        stringstream myStream(input);
        if (myStream >> number)
            break;
        cout << "To nie jest liczba. Wpisz ponownie. " << endl;
    }
    return number;
}

string AuxiliaryMethods::loadFloat(){//zasadniczo powinno byc "loadString"; ta funkcja zwraca wlasnie string
    string input = "";
    float number = 0;

    while (true){
        getline(cin, input);

        stringstream myStream(input);
        if (myStream >> number)
            break;
        cout << "To nie jest liczba. Wpisz ponownie. " << endl;
    }
    return input;
}

//zamiana daty z kreskami na date bez kresek
string AuxiliaryMethods::replaceDateToTextWithoutDashes(string dateWithDashes){
    string dateWithoutDashes;//"dataBezKresek"
    for (int charPosition=0; charPosition<(int)dateWithDashes.length(); charPosition++)
        if(dateWithDashes[charPosition]!='-'){
            dateWithoutDashes+=dateWithDashes[charPosition];
        }
    return dateWithoutDashes;
}

string AuxiliaryMethods::convertFloatToString(float floatNumber){
    ostringstream ss;
    ss << floatNumber;
    string stringNumber = ss.str();

    return stringNumber;
}

float AuxiliaryMethods::convertStringToFloat(string stringNumber){
    float floatNumber;
    istringstream iss(stringNumber);
    iss >> floatNumber;

    return floatNumber;
}

int AuxiliaryMethods::convertStringToInt(string stringNumber){
    int intNumber;
    istringstream iss(stringNumber);
    iss >> intNumber;

    return intNumber;
}

string AuxiliaryMethods::convertIntToString(int intNumber){
    ostringstream ss;
    ss << intNumber;
    string stringNumber = ss.str();

    return stringNumber;
}


