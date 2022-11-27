#include "FileWithIncomies.h"

void FileWithIncomies::addIncomiesToFileXML(Incomies incomies){
    CMarkup xml;

    bool fileExists = xml.Load("incomies.xml");
    if (!fileExists){ //jesli plik nie istnieje, to dodajemy glowny element "Incomies"
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Incomies");
    }

    xml.FindElem(); //szuka elementu w pliku
    xml.IntoElem(); //robi ten element elementem glownym
    xml.AddElem("Incomies"); //do obiektu dodajemy "User"
    xml.IntoElem(); //wchodzimy do tej galezi
    xml.AddElem("UserID", incomies.getUserId());
    xml.AddElem("IncomeID", incomies.getIncomeId());
    xml.AddElem("Date", incomies.getDate());
    xml.AddElem("Item", incomies.getItem());
    xml.AddElem("Amount", incomies.getAmount());
    //MCD_STR strXML = xml.GetDoc(); //zmienna "strXML" pokazuje pelen tekst obiektu "xml"
    //cout<<"Pelen tekst obiektu 'xml':"<<endl<<strXML<<endl;
    ///dwa wiersze wyzej pokazuja aktualnie wpisana osobe tak jak w pliku .XML
    xml.Save("incomies.xml");
}

vector <Incomies> FileWithIncomies::loadIncomiessFromFileXML(int loggedInUserId){
    Incomies incomiesC;
    vector <Incomies> incomiesV;
    CMarkup xml1;//trzeba pozniej ta jedynke zlikwidowac

    xml1.Load("incomies.xml");
    xml1.FindElem(); //<Incomies>
    xml1.IntoElem();

    while (xml1.FindElem("Incomies")){
        xml1.IntoElem();
        xml1.FindElem(); //UserID
        MCD_STR line = xml1.GetData();

        if(line == to_string(loggedInUserId)){
                                                incomiesC.setUserId(atoi(line.c_str()));         //cout<<"line = "<<line<<endl;
            xml1.FindElem(); //IncomeID
            line = xml1.GetData();             incomiesC.setIncomeId(atoi(line.c_str()));       //cout<<"line = "<<line<<endl;
            xml1.FindElem(); //Date
            line = xml1.GetData();             incomiesC.setDate(atoi(line.c_str()));           //cout<<"line = "<<line<<endl;
            xml1.FindElem(); //Item
            line = xml1.GetData();             incomiesC.setItem(line);                         //cout<<"line = "<<line<<endl;
            xml1.FindElem(); //Amount
            line = xml1.GetData();             incomiesC.setAmount(atoi(line.c_str()));         //cout<<"line = "<<line<<endl;

            incomiesV.push_back(incomiesC);
        }
        xml1.OutOfElem();
    }
    return incomiesV;
}



