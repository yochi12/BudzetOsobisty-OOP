#include "FileWithExpenses.h"

void FileWithExpenses::addExpensesToFileXML(Expense expense){
    bool fileExists = xml.Load("expenses.xml");
    if (!fileExists){ //jesli plik nie istnieje, to dodajemy glowny element "Expenses"
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Expenses");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Expense");
    xml.IntoElem();
    xml.AddElem("UserID", expense.getUserId());
    xml.AddElem("ExpenseID", expense.getExpenseId());
    xml.AddElem("Date", expense.getDate());
    xml.AddElem("Item", expense.getItem());
    xml.AddElem("Amount", AuxiliaryMethods::convertFloatToString(expense.getAmount()));

    xml.Save("expenses.xml");
}

vector <Expense> FileWithExpenses::loadExpensesFromFileXML(int loggedInUserId){
    Expense expense;
    vector <Expense> expenses;

    xml.Load("expenses.xml");
    xml.FindElem(); //<Expenses>
    xml.IntoElem();

    while (xml.FindElem("Expense")){
        xml.IntoElem();
        xml.FindElem(); //<UserID>
        MCD_STR line = xml.GetData();

        if(line == to_string(loggedInUserId)){
                                                expense.setUserId(atoi(line.c_str()));
            xml.FindElem(); //ExpenseID
            line = xml.GetData();               expense.setExpenseId(atoi(line.c_str()));
            xml.FindElem(); //Date
            line = xml.GetData();               expense.setDate(atoi(line.c_str()));
            xml.FindElem(); //Item
            line = xml.GetData();               expense.setItem(line);
            xml.FindElem(); //Amount
            line = xml.GetData();               expense.setAmount(atof(line.c_str()));

            expenses.push_back(expense);
        }
        xml.OutOfElem();
    }
    return expenses;
}

int FileWithExpenses::loadLastExpenseID(){
    xml.Load("expenses.xml");
    xml.FindElem(); //<Expenses>
    xml.IntoElem();
    MCD_STR line = xml.GetData();

    while (xml.FindElem("Expense")){
        xml.IntoElem();
        xml.FindElem("ExpenseID");
        line = xml.GetData();
        xml.OutOfElem();
    }
    return atoi(line.c_str());
}


