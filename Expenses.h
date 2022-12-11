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
    float amount;

public:
    void setExpenseId(int newIncomeId);
    void setUserId(int newUserId);
    void setDate(int newDate);
    void setItem(string newItem);
    void setAmount(float newAmount);

    int getExpenseId();
    int getUserId();
    int getDate();
    string getItem();
    float getAmount();
};

#endif
