#ifndef AuxiliaryMethods_H
#define AuxiliaryMethods_H
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cmath>

using namespace std;

class AuxiliaryMethods
{
public:
    static char loadChar();
    static string loadLine();
    static int loadInteger();//"wczytajLiczbeCalkowita"
    static string replaceDateToTextWithoutDashes(string dateWithDashes);//"zamienDateNaTekstBezKresek"
    static string addDashesToDate(string dateWithoutDashes);
    static string convertFloatToString(float floatNumber);
    static float convertStringToFloat(string stringNumber);
    static int convertStringToInt(string stringNumber);
    static string convertIntToString(int intNumber);

    static string loadAmount();//wczytajKwote
    static string convertCommaToDot(string cashAmount);//konwersjaPrzecinkaNaKropke
    static bool checkCashAmountFormat(string cashAmount);//sprawdzFormatKwoty
    static string roundingToTwoDecimalPlaces(string cashAmount);//"zaokraglanieDoDwóchMiejscPoPrzecinku"
    static string returnTwoDigitNumber(int monthOrDay);//zwrocDwucyfrowaLiczbe
};

#endif
