#ifndef FileWithExpenses_H
#define FileWithExpenses_H
#include <iostream>
#include <vector>
#include <string>

#include "Markup.h"
#include "Expense.h"
#include "AuxiliaryMethods.h"

using namespace std;

class FileWithExpenses
{

public:
    void addExpensesToFileXML(Expense expense);
    vector <Expense> loadExpensesFromFileXML(int loggedInUserId);
};

#endif
