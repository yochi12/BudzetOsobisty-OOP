#include "Incomies.h"

//tutaj mamy gettery i settery
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
void Incomies::setAmount(string newAmount){
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
string Incomies::getAmount(){
    return amount;
}
