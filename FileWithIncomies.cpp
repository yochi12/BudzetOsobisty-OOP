#include "FileWithIncomies.h"

void FileWithIncomies::addIncomiesToFileXML(Income income){
    bool fileExists = xml.Load("incomies.xml");
    if (!fileExists){ //jesli plik nie istnieje, to dodajemy glowny element "Incomies"
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Incomies");
    }

    xml.FindElem(); //szuka elementu w pliku
    xml.IntoElem(); //robi ten element elementem glownym
    xml.AddElem("Income"); //do obiektu dodajemy "Incomies"
    xml.IntoElem(); //wchodzimy do tej galezi
    xml.AddElem("UserID", income.getUserId());
    xml.AddElem("IncomeID", income.getIncomeId());
    xml.AddElem("Date", income.getDate());
    xml.AddElem("Item", income.getItem());
    xml.AddElem("Amount", AuxiliaryMethods::convertFloatToString(income.getAmount()));
    //MCD_STR strXML = xml.GetDoc(); //zmienna "strXML" pokazuje pelen tekst obiektu "xml"
    //cout<<"Pelen tekst obiektu 'xml':"<<endl<<strXML<<endl;   system("pause");
    ///dwa wiersze wyzej pokazuja aktualnie wpisana osobe tak jak w pliku .XML
    xml.Save("incomies.xml");
}

vector <Income> FileWithIncomies::loadIncomiesFromFileXML(int loggedInUserId){
    Income income;
    vector <Income> incomiesV;

    xml.Load("incomies.xml");
    xml.FindElem(); //<Incomies>
    xml.IntoElem();

    while (xml.FindElem("Income")){
        xml.IntoElem();
        xml.FindElem(); //<UserID>
        MCD_STR line = xml.GetData();

        if(line == to_string(loggedInUserId)){
                                                income.setUserId(atoi(line.c_str()));         //cout<<"line = "<<line<<endl;
            xml.FindElem(); //IncomeID
            line = xml.GetData();               income.setIncomeId(atoi(line.c_str()));       //cout<<"line = "<<line<<endl;
            xml.FindElem(); //Date
            line = xml.GetData();               income.setDate(atoi(line.c_str()));           //cout<<"line = "<<line<<endl;
            xml.FindElem(); //Item
            line = xml.GetData();               income.setItem(line);                         //cout<<"line = "<<line<<endl;
            xml.FindElem(); //Amount
            line = xml.GetData();               income.setAmount(atof(line.c_str()));         //cout<<"line = "<<line<<endl;

            incomiesV.push_back(income);
        }
        xml.OutOfElem();
    }
    return incomiesV;
}

int FileWithIncomies::loadLastIncomeID(){
    xml.Load("incomies.xml");
    xml.FindElem(); //<Incomies>
    xml.IntoElem();
    MCD_STR line = xml.GetData();

    while (xml.FindElem("Income")){
        xml.IntoElem();
        xml.FindElem("IncomeID");
        line = xml.GetData();
        xml.OutOfElem();
    }
    return atoi(line.c_str());
}



