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

float AuxiliaryMethods::loadFloat(){
    string input = "";
    float number = 0;

    while (true){
        getline(cin, input);

        stringstream myStream(input);
        if (myStream >> number)
            break;
        cout << "To nie jest liczba. Wpisz ponownie. " << endl;
    }
    return number;
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

string AuxiliaryMethods::convertCommaToDot(string numberToCheck){
    string finalNumber;
    for (int i=0; i<(int)numberToCheck.length(); i++)
        if(numberToCheck[i]!=',')
            finalNumber+=numberToCheck[i];
        else
            finalNumber+='.';
    return finalNumber;
}

