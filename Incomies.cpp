#include "Incomies.h"

void Incomies::setIncomeId(int newIncomeId){
        incomeId=newIncomeId;
}
void Incomies::setUserId(int newUserId){
        userId=newUserId;
}
void Incomies::setDate(int newDate){
        date=newDate;
}
void Incomies::setItem(string newItem){
        item=newItem;
}
void Incomies::setAmount(float newAmount){
        amount=newAmount;
}

int Incomies::getIncomeId(){
    return incomeId;
}
int Incomies::getUserId(){
    return userId;
}
int Incomies::getDate(){
    return date;
}
string Incomies::getItem(){
    return item;
}
float Incomies::getAmount(){
    return amount;
}
