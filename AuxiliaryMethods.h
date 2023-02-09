#ifndef AuxiliaryMethods_H
#define AuxiliaryMethods_H
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

class AuxiliaryMethods
{
public:
    static char loadChar();
    static string loadLine();
    static int loadInteger();//"wczytajLiczbeCalkowita"
    static string loadFloat();
    static string replaceDateToTextWithoutDashes(string dateWithDashes);//"zamienDateNaTekstBezKresek"
    static string convertFloatToString(float floatNumber);
    static float convertStringToFloat(string stringNumber);
    static int convertStringToInt(string stringNumber);
    static string convertIntToString(int intNumber);

};

#endif
