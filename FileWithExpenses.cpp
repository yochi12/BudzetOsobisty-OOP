#include "FileWithExpenses.h"

void FileWithExpenses::addExpensesToFileXML(Expenses expensesC){
    CMarkup xml;

    bool fileExists = xml.Load("expenses.xml");
    if (!fileExists){ //jesli plik nie istnieje, to dodajemy glowny element "Expenses"
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Expenses");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Expenses");
    xml.IntoElem();
    xml.AddElem("UserID", expensesC.getUserId());
    xml.AddElem("IncomeID", expensesC.getExpenseId());
    xml.AddElem("Date", expensesC.getDate());
    xml.AddElem("Item", expensesC.getItem());
    xml.AddElem("Amount", expensesC.getAmount());

    xml.Save("expenses.xml");
}

vector <Expenses> FileWithExpenses::loadExpensesFromFileXML(int loggedInUserId){
    Expenses expensesC;
    vector <Expenses> expensesV;
    CMarkup xml;

    xml.Load("expenses.xml");
    xml.FindElem(); //<Expenses>
    xml.IntoElem();

    while (xml.FindElem("Expenses")){
        xml.IntoElem();
        xml.FindElem(); //<UserID>
        MCD_STR line = xml.GetData();

        if(line == to_string(loggedInUserId)){
                                                expensesC.setUserId(atoi(line.c_str()));
            xml.FindElem(); //IncomeID
            line = xml.GetData();              expensesC.setExpenseId(atoi(line.c_str()));
            xml.FindElem(); //Date
            line = xml.GetData();              expensesC.setDate(atoi(line.c_str()));
            xml.FindElem(); //Item
            line = xml.GetData();              expensesC.setItem(line);
            xml.FindElem(); //Amount
            line = xml.GetData();              expensesC.setAmount(atoi(line.c_str()));

            expensesV.push_back(expensesC);
        }
        xml.OutOfElem();
    }
    return expensesV;
}



