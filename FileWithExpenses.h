#ifndef FileWithExpenses_H
#define FileWithExpenses_H
#include <iostream>
#include <vector>
#include <string>

#include "Markup.h"
#include "Expenses.h"
#include "AuxiliaryMethods.h"

using namespace std;

class FileWithExpenses
{

public:
    void addExpensesToFileXML(Expenses expensesC);
    vector <Expenses> loadExpensesFromFileXML(int loggedInUserId);
};

#endif
