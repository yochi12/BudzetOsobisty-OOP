#ifndef Incomies_H
#define Incomies_H

#include <iostream>

using namespace std;

class Incomies
{
    int incomeId;
    int userId;
    int date;
    string item;
    string amount;

public:
    void setIncomeId(int newIncomeId);
    void setUserId(int newUserId);
    void setDate(int newDate);
    void setItem(string newItem);
    void setAmount(string newAmount);

    int getIncomeId();
    int getUserId();
    int getDate();
    string getItem();
    string getAmount();

};

#endif
