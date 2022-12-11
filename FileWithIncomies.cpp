#include "FileWithIncomies.h"

void FileWithIncomies::addIncomiesToFileXML(Incomies incomiesC){
    CMarkup xml;

    bool fileExists = xml.Load("incomies.xml");
    if (!fileExists){ //jesli plik nie istnieje, to dodajemy glowny element "Incomies"
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Incomies");
    }

    xml.FindElem(); //szuka elementu w pliku
    xml.IntoElem(); //robi ten element elementem glownym
    xml.AddElem("Incomies"); //do obiektu dodajemy "Incomies"
    xml.IntoElem(); //wchodzimy do tej galezi
    xml.AddElem("UserID", incomiesC.getUserId());
    xml.AddElem("IncomeID", incomiesC.getIncomeId());
    xml.AddElem("Date", incomiesC.getDate());
    xml.AddElem("Item", incomiesC.getItem());
    xml.AddElem("Amount", AuxiliaryMethods::convertFloatToString(incomiesC.getAmount()));
    //MCD_STR strXML = xml.GetDoc(); //zmienna "strXML" pokazuje pelen tekst obiektu "xml"
    //cout<<"Pelen tekst obiektu 'xml':"<<endl<<strXML<<endl;   system("pause");
    ///dwa wiersze wyzej pokazuja aktualnie wpisana osobe tak jak w pliku .XML
    xml.Save("incomies.xml");
}

vector <Incomies> FileWithIncomies::loadIncomiesFromFileXML(int loggedInUserId){
    Incomies incomiesC;
    vector <Incomies> incomiesV;
    CMarkup xml;

    xml.Load("incomies.xml");
    xml.FindElem(); //<Incomies>
    xml.IntoElem();

    while (xml.FindElem("Incomies")){
        xml.IntoElem();
        xml.FindElem(); //<UserID>
        MCD_STR line = xml.GetData();

        if(line == to_string(loggedInUserId)){
                                                incomiesC.setUserId(atoi(line.c_str()));         //cout<<"line = "<<line<<endl;
            xml.FindElem(); //IncomeID
            line = xml.GetData();               incomiesC.setIncomeId(atoi(line.c_str()));       //cout<<"line = "<<line<<endl;
            xml.FindElem(); //Date
            line = xml.GetData();               incomiesC.setDate(atoi(line.c_str()));           //cout<<"line = "<<line<<endl;
            xml.FindElem(); //Item
            line = xml.GetData();               incomiesC.setItem(line);                         //cout<<"line = "<<line<<endl;
            xml.FindElem(); //Amount
            line = xml.GetData();               incomiesC.setAmount(atof(line.c_str()));         //cout<<"line = "<<line<<endl;

            incomiesV.push_back(incomiesC);
        }
        xml.OutOfElem();
    }
    return incomiesV;
}



