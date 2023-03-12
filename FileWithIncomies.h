#ifndef FileWithIncomies_H
#define FileWithIncomies_H
#include <iostream>
#include <vector>
#include <string>

#include "Markup.h"
#include "Income.h"
#include "AuxiliaryMethods.h"

using namespace std;

class FileWithIncomies
{
    CMarkup xml;

public:
    void addIncomiesToFileXML(Income income);
    vector <Income> loadIncomiesFromFileXML(int loggedInUserId);
    int loadLastIncomeID();
};

#endif
