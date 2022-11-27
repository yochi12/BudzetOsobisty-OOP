#ifndef Expenses_H
#define Expenses_H

#include <iostream>

using namespace std;

class Expenses
{
int expenseId;
    int userId;
    int date;
    string item;
    int amount;

public:
    void setExpenseId(int newIncomeId);
    void setUserId(int newUserId);
    void setDate(int newDate);
    void setItem(string newItem);
    void setAmount(int newAmount);

    int getExpenseId();
    int getUserId();
    int getDate();
    string getItem();
    int getAmount();
};

#endif
